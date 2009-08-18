// Copyright 2004-2008 Facebook. All Rights Reserved.
//
// See Canonical Style Documents at:
//
//   http://www.dev.facebook.com/intern/wiki/index.php/CppStyle
//   http://www.dev.facebook.com/intern/wiki/index.php/CppConventions
//
// Example header that demonstrates our current CppStyle.  The goal of this
// code, while nonsensical, is to show a visual example of as many of our
// style rules/guidelines as possible.
//
// Note the #include order: C-style stdlib includes, C++ includes, boost
// includes, then fbcode/ includes in quotes ("").
//
// @author Mark Rabkin (mrabkin@facebook.com)

#ifndef __CPPSTYLE_CODEEXAMPLE_H__
#define __CPPSTYLE_CODEEXAMPLE_H__

#include <stdio.h>
#include <ctype.h>

#include <functional>

#include <boost/utility.hpp>
#include <boost/scoped_ptr.hpp>

#include "common/base/Base.h"
#include "common/base/Hash.h"
#include "thrift/lib/cpp/concurrency/Mutex.h"
#include "thrift/lib/cpp/server/TServer.h"
#include "common/time/Time.h"

namespace facebook { namespace example {

// maximum size of a buffer
const int kMaxBufferSize = 1024;
const uint64_t kThirtyMegs = 30 * (1 << 20);
const char* const kStrConstant = "needs two consts: 'const char* CONST'!";

// Note: it's ok to use 'using namespace' if you're yanking into your own
// private namespace (here, into namespace facebook::example).  It is _not_ OK
// to do it at the top level or the 'namespace facebook' level.
using namespace facebook::thrift::concurrency;

using facebook::thrift::server::TServer;

/**
 * struct ExampleStruct
 *
 * Shows how to format struct definitions.
 */
struct ExampleStruct {
  int64_t valOne;        // value #1
  int64_t valTwo;        // value #2

  /*** adds the two values */
  int64_t inlineSumFunc() {
    return valOne + valTwo;
  }
};

/**
 * class ExampleClass
 *
 * Shows how to format class definitions, including public/private sections,
 * comments, accessors, members, inheritance, making a class noncopyable, etc.
 */
class ExampleClass : boost::noncopyable  {
 public:
  enum EnumType {
    VALUE_ONE = 1,
    VALUE_TWO,
    END_VALUE,
  };

  // map:  name -> (score, keyword)
  typedef map<string, pair<double, string> > ComplicatedMap;

  /*** trivial constructor */
  ExampleClass() : counterValue_(0), name_("none") { }

  /**
   * Constructor with argument; can often make these explicit if you
   * don't want conversions.
   */
  explicit ExampleClass(int counterValue);

  /*** one-line accessor; these don't always need javadoc comments */
  int64_t getCounterValue() const { return counterValue_; }

  const string& getName() const { return name_; }
  ComplicatedMap* getMap() { return &complicatedMap_; }
  void setValue(int val) { counterValue_ = val; }

  /**
   * Takes lots of arguments, but doesn't do much that's useful with them.
   *
   * @param count an integer input (by value)
   * @param value an enum input (by value)
   * @param name a string input (by const-ref)
   * @param list an STL container input (by const-ref)
   * @param maybeList an _option_ STL container input (by pointer)
   * @param outVector output STL container arg (by pointer)
   */
  const vector<int64_t>& funcWithManyArgs(int64_t count,
                                          EnumType value,
                                          const string& name,
                                          const vector<string>& list,
                                          const vector<string>* maybeList,
                                          vector<double>* outVector);

  /**
   * static function that creates an instance of <code>ExampleClass</code>
   */
  static ExampleClass* getInstance();

 private:
  template<class T>
  T myPrivateTemplateFunc(const T& foo);

 private:
  int64_t counterValue_;        // int member
  string name_;                 // string member; notice no need for std::string
  vector<int64_t> valueList_;   // simple STL container; also not std::vector

  ComplicatedMap complicatedMap_;  // my fancy map
};


// Trivial template function defintion; this is in the header file because it's
// templated and short. If it were longer, or if we had more of these, we'd put
// this in a file called 'CodeExample-inl.h'.  Notice definitions aren't
// autodoc style.
template<class T>
T ExampleClass::myPrivateTemplateFunc(const T& foo) {
  return foo;
}


} } // namespace facebook::example


#endif   // __CPPSTYLE_CODEEXAMPLE_H__
