
//          Copyright Joakim Karlsson & Kim Gräsman 2010-2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_SELF_TEST_H
#define IGLOO_SELF_TEST_H

#include <igloo/igloo.h>

#define AssertTestFails(assertion, expected_error_text) \
  std::string IGLOO_INTERNAL_expected_error = "Test did not fail"; \
  try \
  { \
    assertion; \
  }  \
  catch(const AssertionException& exception_from_igloo_assertion)  \
  {  \
  IGLOO_INTERNAL_expected_error = exception_from_igloo_assertion.GetMessage();  \
  }  \
  Assert::That(IGLOO_INTERNAL_expected_error, Is().Containing(expected_error_text));

#endif
