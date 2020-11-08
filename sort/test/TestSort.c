#include "unity.h"
#include "unity_fixture.h"

#define SIZEARRAY 6

void merge_sort(int* vet, int n);

TEST_GROUP(Sort);

TEST_SETUP(Sort){
}

TEST_TEAR_DOWN(Sort){
}

TEST(Sort, firstTest){
  TEST_ASSERT_EQUAL(0,0);
}

TEST(Sort, QuickSort_EmptyArray){
  int arr[4] = {4,3,2,1};
  int expected[4] = {1,2,3,4};
  merge_sort(arr,4);

  for(int i=0;i<4;i++)
  {
    TEST_ASSERT_EQUAL(expected[i],arr[i]);
  }
}

TEST(Sort, test_sort_duplicatedValues){
  int list[] = {1,4,1,6,9,7};
  int expectedList[] = {1,1,4,6,7,9};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_negativeValues){
  int list[] = {1,4,-3,6,9,7};
  int expectedList[] = {-3,1,4,6,7,9};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_OneValue){
  int list[] = {1};
  int expectedList[] = {1};

  merge_sort(list, 1);

  for(int i=0;i<1;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_OneValueDifferent){
  int list[] = {9,9,9,9,1,9};
  int expectedList[] = {1,9,9,9,9,9};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_OnlyNegativeValues){
  int list[] = {-9,-5,-7,-69,-14,-79};
  int expectedList[] = {-79,-69,-14,-9,-7,-5};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_BigArray){
  int list[] = {40,3,2,4,5,6,7,8,9,10,11,12,23,34,15,16,27,18,19,20,21,22,13,24,25,26,17,28,39,30,31,32,33,14,35,36,37,38,29,1};
  int expectedList[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};

  merge_sort(list, 40);

  for(int i=0;i<40;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_With0Values){
  int list[] = {1,4,-3,6,0,7};
  int expectedList[] = {-3,0,1,4,6,7};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_WithDifferentSizes){
  int list[SIZEARRAY] = {6,5,4,3,2,1};
  int expectedList[SIZEARRAY] = {3,4,5,6,2,1};

  merge_sort(list, 4);

  for(int i=0;i<4;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}


TEST(Sort, test_sort_ArrayOfChars){
  int list[SIZEARRAY] = {'a','b','d','g','c','e'};
  int expectedList[SIZEARRAY] = {'a','b','c','d','e','g'};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_BigAndWorstCase){
  int list[51] = {50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
  int expectedList[51] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

  merge_sort(list, 51);

  for(int i=0;i<51;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_BigAndBestCase){
  int list[51] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
  int expectedList[51] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

  merge_sort(list, 51);

  for(int i=0;i<51;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_EmptyArray){
  int list[] = {};
  int expectedList[] = {};
  int size = sizeof(list)/sizeof(int);
  merge_sort(list, size);

  for(int i=0;i<size;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_DecimalValues){
  float list[SIZEARRAY] = {0.1,0.6,4,2.5,9.5,6.1};
  float expectedList[SIZEARRAY] = {0.1,0.6,2.5,4,6.1,9.5};
  
  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    TEST_ASSERT_EQUAL(expectedList[i],list[i]);
  }
}

TEST(Sort, test_sort_NullArray){
    int list[SIZEARRAY] = {0, 0, 0, 0, 0, 0};

  merge_sort(list, SIZEARRAY);

  for(int i=0;i<SIZEARRAY;i++)
  {
    if(list[i] != 0)
    {
      //Force error
      TEST_ASSERT_EQUAL(1,2);
    }
  }
}
