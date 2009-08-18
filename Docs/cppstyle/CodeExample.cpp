// Copyright 2004-2008 Facebook. All Rights Reserved.
//
// See Canonical Style Document at:
//
//   http://www.dev.facebook.com/intern/wiki/index.php/CppStyle
//
// See additional comments in: fbcode/cppstyle/ExampleCode.h
//
// Note the #include order: First our related .h file, then C-style stdlib
// includes, C++ includes, boost includes, then fbcode/ includes in quotes
// ("").
//
// @author Mark Rabkin (mrabkin@facebook.com)

#include "cppstyle/CodeExample.h"

#include <stdio.h>
#include <ctype.h>

#include <functional>

#include <boost/utility.hpp>
#include <boost/scoped_ptr.hpp>

#include "common/base/Base.h"
#include "common/base/Hash.h"
#include "common/time/Time.h"

namespace facebook { namespace example {

const string kCmDefaultKey = "hi";   // default key for complicated map
const pair<double, string> kCmDefaultVal = make_pair(1.5, "hi!11");

// ---------------------------------------------------------------------
// class ExampleClass
// ---------------------------------------------------------------------

// This additional comment is not in the javadoc style, as it's supposed to
// describe more concrete implementation details.  Any comments that may be
// useful to the class API "customer" (as opposed to someone who might modify
// this class) should instead be in JavaDoc style in ExampleCode.h.
ExampleClass::ExampleClass(int counterValue)
    : counterValue_(counterValue),
      name_("blah") {
  // add a default value to the complicated map
  complicatedMap_.insert(
    make_pair(kCmDefaultKey, kCmDefaultVal));

  for (ComplicatedMap::iterator it = complicatedMap_.begin();
       it != complicatedMap_.end(); ++it) {
    ComplicatedMap::value_type& val = (*it);
    valueList_.push_back(static_cast<int64_t>(val.second.first));
  }

  FOR_EACH(it, valueList_) {
    // TODO(mrabkin): this is useless code, fix it (but not really since this
    // is an example :P)
    int64_t val = (*it);
    val *= 2;
  }
}

const vector<int64_t>&
ExampleClass::funcWithManyArgs(int64_t count,
                               EnumType value,
                               const string& name,
                               const vector<string>& list,
                               const vector<string>* maybeList,
                               vector<double>* outVector) {
  // -------------------------------------------------------------------------
  // The body of this function is used to demonstrate common code constructs so
  // that the indentation, braces, and spacing styles for them are immediately
  // apparent.
  // -------------------------------------------------------------------------

  // This section demonstrates different kinds of if() blocks, including
  // long/short if() blocks, complicated if() expressions, and validity
  // checks on pointer/handle variables.

  if (count < 0) {
    ++count;
  } else if (count == 0) {
    --count;
  } else {
    count *= 2;
  }

  if (complicatedMap_.find(name) != complicatedMap_.end() &&
      complicatedMap_.size() > 10 &&
      (count < 0 || count > 5)) {
    valueList_.push_back(count);
  }

  if (!name.empty()) {
    count += name.size();
  }

  boost::scoped_ptr<int> scopedPtr;
  int* realPtr = NULL;
  if (!scopedPtr && !realPtr) {
    scopedPtr.reset(new int(10));
  }

  if (realPtr == NULL && scopedPtr.get() != NULL) {
    realPtr = scopedPtr.get();
  }

  // This section demonstrates looping constructs.
  for (vector<string>::const_iterator it = list.begin();
       it != list.end(); ++it) {
    count += it->size();
  }

  FOR_EACH(it, list) {
    count += it->size();
  }

  int i = 10;
  while (i > 0) {
    --i;
  }

  do {
   ++i;
  } while (i <= 10);

  // This section demonstrates formatting for basic expressions, operators, and
  // initializations.

  string s("startvalue");
  size_t someSize = sizeof(*realPtr);
  int val = count / 2;
  count = (count + val) & ((val << 3) + count * val);


  // Example of use of nested scope to limit lifetime of a mutex guard,
  // scoped ptr, or some other class with a non-trivial destructor.
  {
    scoped_ptr<int> ptr(new int(10));
    *ptr += 10;
  }

  return valueList_;
}

/* static */
ExampleClass* ExampleClass::getInstance() {
  return new ExampleClass();
}

} } // !namespace facebook::example
