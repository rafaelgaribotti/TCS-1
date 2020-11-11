#include "unity.h"
#include "unity_fixture.h"

#include "../src/sort.h"
#include "utils.c"

#define SIZE_ARRAY 1000

TEST_GROUP(SortArray);

static int* ARRAY1;

TEST_SETUP(SortArray){
  ARRAY1 = malloc(sizeof(int)*SIZE_ARRAY);
  initArray(ARRAY1, SIZE_ARRAY);
}

TEST_TEAR_DOWN(SortArray){
  free(ARRAY1);
}

TEST(SortArray, TestSelectionSort){
  sort_array(ARRAY1, SIZE_ARRAY, SELECTION);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

TEST(SortArray, TestInsertionSort){
  sort_array(ARRAY1, SIZE_ARRAY, INSERTION);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

TEST(SortArray, TestShellSort){
  sort_array(ARRAY1, SIZE_ARRAY, SHELL);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

TEST(SortArray, TestQuickSort){
  sort_array(ARRAY1, SIZE_ARRAY, QUICK);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

TEST(SortArray, TestHeapSort){
  sort_array(ARRAY1, SIZE_ARRAY, HEAP);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

TEST(SortArray, TestMergeSort){
  sort_array(ARRAY1, SIZE_ARRAY, MERGE);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}
