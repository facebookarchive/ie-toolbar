<?


// ---------------------------------------------------------------------
// class Util 
// ---------------------------------------------------------------------

class Util {
   
/**
  * Returns value of param
  *
  */
public static function getParam($Name){
  global $HTTP_GET_VARS;
  global $HTTP_POST_VARS;
  global $HTTP_COOKIE_VARS;
  
  
  $result = "";

  if(isset($HTTP_GET_VARS[$Name])){
    $result = $HTTP_GET_VARS[$Name];
  } else if(isset($HTTP_POST_VARS[$Name])){
    $result = $HTTP_POST_VARS[$Name]; 
  } else if(isset($HTTP_COOKIE_VARS[$Name])){
    $result = $HTTP_COOKIE_VARS[$Name];        
  }

  return $result;
}


/**
  * Return array with files names from current directory 
  * that match $pattern 
  *
  * @return array of file names
  */
public static function getFiles($pattern){
  return glob($pattern);
}

/**
  * Returns URL to script 
  * excluding script name and params
  *
  */
public static function getScriptURL(){
  $url = preg_replace('/\?.*$/', '', $_SERVER['REQUEST_URI']);
  $url = 'http://'.$_SERVER['HTTP_HOST'].$url;
  return $url;
}


/**
  * Returns URL to script 
  * excluding script name and params
  *
  */
public static function getScriptPathURL(){
  $url = preg_replace('/\?.*$/', '', $_SERVER['REQUEST_URI']);
  $url = 'http://'.$_SERVER['HTTP_HOST'].'/'.ltrim(dirname($url), '/');
  return $url;
}


}


// ---------------------------------------------------------------------
// VersionComparator class
// ---------------------------------------------------------------------
class VersionComparator {

/**
  * Compares two file names in format "setup.major-ver.minor-ver.release-ver.build-ver.exe"
  *
  * @param $file1 name of first file to compare
  * @param $file2 name of second file to compare
  *
  * @return 0 - if versions are equal, 
  *         1 - if $file1 version is newer
  *        -1 - if $file2 version is newer
  */
public static function compareVersionNames($file1, $file2){
  list($name, $major_ver1, $minor_ver1, $release_ver1, $build_ver1, $ext) = split('[.]', $file1);
  list($name, $major_ver2, $minor_ver2, $release_ver2, $build_ver2, $ext) = split('[.]', $file2);


  // compare major version
  if($major_ver1 > $major_ver2){
    return 1;
  } else if ($major_ver1 < $major_ver2){
    return -1;
  }
 

  // compare minor, release and build versions
  if($minor_ver1 > $minor_ver2){
    return 1;
  } else if ($minor_ver1 < $minor_ver2){
    return -1;
  } 

  // compare release and build versions
  if($release_ver1 > $release_ver2){
    return 1;
  } else if ($release_ver1 < $release_ver2){
    return -1;
  }
 
 // compare build versions
  if($build_ver1 > $build_ver2){
    return 1;
  } else if ($build_ver1 < $build_ver2){
    return -1;
  }

  return 0;

}


/**
  * Compares current product version and file name with version 
  * in format "setup.major-ver.minor-ver.release-ver.build-ver.exe"
  *
  * @param $current_ver version to compare with
  * @param $latest_file name of file to get version from
  *
  * @return 0 - if versions are equal, 
  *         1 - if $current_ver version is newer
  *        -1 - if $latest_file version is newer
  */
public static function compare($current_ver, $latest_file){
  $currentFile = "setup.".$current_ver.".exe"; 

  // build file name for passed product version and compare file names
  return VersionComparator::compareVersionNames($currentFile, $latest_file);
}

/**
  * Checks if parameter matches format 
  * "major-ver.minor-ver.release-ver.build-ver"
  *
  * @param $version to check format
  *
  * @return true - if version match format,
  *         false - otherwise 
  */
public static function checkFormat($version){
  return preg_match("([0-9]+(.)[0-9]+(.)[0-9]+(.)[0-9]+)", $version);
}

/**
  * Checks if parameter matches format 
  * "setup.major-ver.minor-ver.release-ver.build-ver.exe"
  *
  * @param $file to check name format
  *
  * @return true - if version match format,
  *         false - otherwise 
  */
public static function checkFileFormat($file){
  return preg_match("(setup.[0-9]+(.)[0-9]+(.)[0-9]+(.)[0-9]+(.exe))", $file);
}


}

// ---------------------------------------------------------------------
// UpdatesService class
// ---------------------------------------------------------------------

class UpdatesService {
  public static $PARAM_NAME = "version";
  private $current_version;

  public function __construct(){
    $this->current_version = Util::getParam(UpdatesService::$PARAM_NAME);
  }


// private:

/**
  * Analyze files which fit
  * "setup.major-ver.minor-ver.release-ver.build-ver.exe" pattern
  * and return one with latest version
  *
  * @param $files array of files
  *
  * @return file name which has latest version or 
  *         empty string if any file does not fit pattern 
  *
  */
private function getNevestFile($files){
  $max_file = "";
  if( count($files) == 0){
    return $max_file;                                                                       
  }

  $max_file = $files[0];

  for($index = 1; $index < count($files); $index++) {

    // test for pattern
    if(!VersionComparator::checkFileFormat($files[$index]))
      continue;

    if (VersionComparator::compareVersionNames($max_file, $files[$index]) < 0){
      $max_file = $files[$index]; 
    }
  }
  return $max_file;
 
}

/**
  * Calculates latest product version file inside current directory 
  * and if passed version is older then build URL to download latest product
  *
  * @return URL to latest product file 
  */
private function getNewestURL(){
  $result = "";

  // calculates latest file from directory 
  // based on file name pattern 
  $newest_file = $this->getNevestFile(Util::getFiles("setup.*.exe")); 

  if(VersionComparator::compare($this->current_version, $newest_file) < 0){
    $result = Util::getScriptPathURL()."/".$newest_file;
  }
  return $result;

}


/**
  * @return service help information 
  *
  */
private function buildHelp(){
  return "<b>Service usage: </b><br>"
    .Util::getScriptURL()."?version=major-ver.minor-ver.release-ver.build-ver<br>"
    ."<hr><b>Example:</b>:<br>"
    .Util::getScriptURL()."?version=1.0.0.132";
}

          
// public: 


/**
  * Handle service functionality
  *
  */
public function doService(){

  // test if version match pattern
  if(VersionComparator::checkFormat($this->current_version)){
    return $this->getNewestURL();
  } else {
    return $this->buildHelp();
  }
}

}


$service = new UpdatesService();
print $service->doService();

?>