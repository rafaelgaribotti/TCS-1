#include "unity.h"
#include "unity_fixture.h"

#include "../src/sort.h"
#include "utils.c"

#define SIZE_ARRAY 1000

TEST_GROUP(MergeSort);

static int* ARRAY1;
static int* ARRAY2;

TEST_SETUP(MergeSort){
  ARRAY1 = malloc(sizeof(int)*SIZE_ARRAY);
  ARRAY2 = malloc(sizeof(int)*SIZE_ARRAY);
  initArrays(ARRAY1, ARRAY2, SIZE_ARRAY);
}

TEST_TEAR_DOWN(MergeSort){
  free(ARRAY1);
  free(ARRAY2);
}

/************************/
/* SORT FUNCTIONS TESTS */
/************************/

// check if the sort function changed any value of the array
TEST(MergeSort, testCheckIfValuesWereChanged)
{
  merge_sort(ARRAY1,SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(checkArraysElements(ARRAY1, ARRAY2, SIZE_ARRAY),"Sort function changed the values");
}

// check if the restult array is in the correct order
TEST(MergeSort, testArrayOrder)
{
  merge_sort(ARRAY1,SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

// check if the sort function changed a single value array
TEST(MergeSort, testSingleValue)
{
  merge_sort(ARRAY1,1);
  TEST_ASSERT_EQUAL_MESSAGE(ARRAY2[0],ARRAY1[0],"Sort function changes single value array");
}

// check if the sort function works with only zeros array
TEST(MergeSort, testOnlyZerosValues)
{
    for(int i=0; i<SIZE_ARRAY; i++){
      ARRAY1[i]=0;
      ARRAY2[i]=0;
    }
    merge_sort(ARRAY1,SIZE_ARRAY);
    TEST_ASSERT_MESSAGE(checkArraysElements(ARRAY1, ARRAY2, SIZE_ARRAY),"Sort function changed a zero value");
}

// check if the sort function works with duplicated values
TEST(MergeSort, testDuplicatedValues){

  ARRAY1[0]=ARRAY1[SIZE_ARRAY-1];

  merge_sort(ARRAY1, SIZE_ARRAY);

  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

// check if the sort function works with only one different value
TEST(MergeSort, testOneValueDifferent){
  for(int i=0;i<SIZE_ARRAY;i++){
    ARRAY1[i] = 1;
  }
  ARRAY1[SIZE_ARRAY-1] = -5;
  merge_sort(ARRAY1, SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

// check if the sort function works with only negative values
TEST(MergeSort, testOnlyNegativeValues){
  for(int i=0;i<SIZE_ARRAY;i++){
    ARRAY1[i] = i-SIZE_ARRAY;
  }

  merge_sort(ARRAY1, SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

// check if the sort function works in the worse case scenario
TEST(MergeSort, testWorstCase){
  for(int i=0; i<SIZE_ARRAY; i++){
    ARRAY1[i]=SIZE_ARRAY-i;
  }

  merge_sort(ARRAY1, SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}

// check if the sort function works in the best case scenario
TEST(MergeSort, testBestCase){
  for(int i=0; i<SIZE_ARRAY; i++){
    ARRAY1[i]=i;
  }

  merge_sort(ARRAY1, SIZE_ARRAY);
  TEST_ASSERT_MESSAGE(isArrayInCorrectOrder(ARRAY1, SIZE_ARRAY), "Array is not in order");
}
