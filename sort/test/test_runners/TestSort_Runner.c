#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(SelectionSort)
{
  RUN_TEST_CASE(SelectionSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(SelectionSort, testArrayOrder);
  RUN_TEST_CASE(SelectionSort, testSingleValue);
  RUN_TEST_CASE(SelectionSort, testOnlyZerosValues);
  RUN_TEST_CASE(SelectionSort, testDuplicatedValues);
  RUN_TEST_CASE(SelectionSort, testOneValueDifferent);
  RUN_TEST_CASE(SelectionSort, testOnlyNegativeValues);
  RUN_TEST_CASE(SelectionSort, testWorstCase);
  RUN_TEST_CASE(SelectionSort, testBestCase);
}

TEST_GROUP_RUNNER(InsertionSort)
{
  RUN_TEST_CASE(InsertionSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(InsertionSort, testArrayOrder);
  RUN_TEST_CASE(InsertionSort, testSingleValue);
  RUN_TEST_CASE(InsertionSort, testOnlyZerosValues);
  RUN_TEST_CASE(InsertionSort, testDuplicatedValues);
  RUN_TEST_CASE(InsertionSort, testOneValueDifferent);
  RUN_TEST_CASE(InsertionSort, testOnlyNegativeValues);
  RUN_TEST_CASE(InsertionSort, testWorstCase);
  RUN_TEST_CASE(InsertionSort, testBestCase);
}

TEST_GROUP_RUNNER(ShellSort)
{
  RUN_TEST_CASE(ShellSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(ShellSort, testArrayOrder);
  RUN_TEST_CASE(ShellSort, testSingleValue);
  RUN_TEST_CASE(ShellSort, testOnlyZerosValues);
  RUN_TEST_CASE(ShellSort, testDuplicatedValues);
  RUN_TEST_CASE(ShellSort, testOneValueDifferent);
  RUN_TEST_CASE(ShellSort, testOnlyNegativeValues);
  RUN_TEST_CASE(ShellSort, testWorstCase);
  RUN_TEST_CASE(ShellSort, testBestCase);
}

TEST_GROUP_RUNNER(QuickSort)
{
  RUN_TEST_CASE(QuickSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(QuickSort, testArrayOrder);
  RUN_TEST_CASE(QuickSort, testSingleValue);
  RUN_TEST_CASE(QuickSort, testOnlyZerosValues);
  RUN_TEST_CASE(QuickSort, testDuplicatedValues);
  RUN_TEST_CASE(QuickSort, testOneValueDifferent);
  RUN_TEST_CASE(QuickSort, testOnlyNegativeValues);
  RUN_TEST_CASE(QuickSort, testWorstCase);
  RUN_TEST_CASE(QuickSort, testBestCase);
}

TEST_GROUP_RUNNER(HeapSort)
{
  RUN_TEST_CASE(HeapSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(HeapSort, testArrayOrder);
  RUN_TEST_CASE(HeapSort, testSingleValue);
  RUN_TEST_CASE(HeapSort, testOnlyZerosValues);
  RUN_TEST_CASE(HeapSort, testDuplicatedValues);
  RUN_TEST_CASE(HeapSort, testOneValueDifferent);
  RUN_TEST_CASE(HeapSort, testOnlyNegativeValues);
  RUN_TEST_CASE(HeapSort, testWorstCase);
  RUN_TEST_CASE(HeapSort, testBestCase);
}

TEST_GROUP_RUNNER(MergeSort)
{
  RUN_TEST_CASE(MergeSort, testCheckIfValuesWereChanged);
  RUN_TEST_CASE(MergeSort, testArrayOrder);
  RUN_TEST_CASE(MergeSort, testSingleValue);
  RUN_TEST_CASE(MergeSort, testOnlyZerosValues);
  RUN_TEST_CASE(MergeSort, testDuplicatedValues);
  RUN_TEST_CASE(MergeSort, testOneValueDifferent);
  RUN_TEST_CASE(MergeSort, testOnlyNegativeValues);
  RUN_TEST_CASE(MergeSort, testWorstCase);
  RUN_TEST_CASE(MergeSort, testBestCase);
}
