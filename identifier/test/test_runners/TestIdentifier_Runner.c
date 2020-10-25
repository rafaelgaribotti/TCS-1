#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Identifier)
{
  RUN_TEST_CASE(Identifier, MinSizeAndLetter);
  RUN_TEST_CASE(Identifier, MaxSize);
  RUN_TEST_CASE(Identifier, MinSizeAndNumber);
  RUN_TEST_CASE(Identifier, Empty);
  RUN_TEST_CASE(Identifier, BiggerSize);
  RUN_TEST_CASE(Identifier, SpecialChar);
}
