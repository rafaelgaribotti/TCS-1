#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, firstTest);
  RUN_TEST_CASE(Sort, QuickSort_EmptyArray);
  RUN_TEST_CASE(Sort, test_sort_duplicatedValues);
  RUN_TEST_CASE(Sort, test_sort_negativeValues);
  RUN_TEST_CASE(Sort, test_sort_OneValue);
  RUN_TEST_CASE(Sort, test_sort_OneValueDifferent);
  RUN_TEST_CASE(Sort, test_sort_OnlyNegativeValues);
  RUN_TEST_CASE(Sort, test_sort_BigArray);
  RUN_TEST_CASE(Sort, test_sort_With0Values);
  RUN_TEST_CASE(Sort, test_sort_EmptyArray);
  RUN_TEST_CASE(Sort, test_sort_ArrayOfChars);
  RUN_TEST_CASE(Sort, test_sort_BigAndWorstCase);
  RUN_TEST_CASE(Sort, test_sort_BigAndBestCase);
  RUN_TEST_CASE(Sort, test_sort_WithDifferentSizes);
  RUN_TEST_CASE(Sort, test_sort_DecimalValues);
  RUN_TEST_CASE(Sort, test_sort_NullArray);
}
