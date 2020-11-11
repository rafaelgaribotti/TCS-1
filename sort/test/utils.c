#include <stdlib.h>
#include <stdbool.h>

// init two identical arrays with interleaved positive and negative values
static void initArrays(int* array1, int* array2, int size)
{
    for(int i=0;i<size;i++){
      array1[i] = size-1-i;
      array1[i] = i%2 == 0 ? array1[i] : array1[i]*-1; // interleaves positive and negative values
      array2[i] = array1[i];
    }
}

// check if all elemets in array1 are in array2
static bool checkArraysElements(int* array1, int* array2, int size)
{
  bool usedIndexes[size];
  bool flag = true;
  for(int i=0; i<size; i++)
    usedIndexes[i]=false;

  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      if(array1[i]==array2[j] && !usedIndexes[j]){
        usedIndexes[j]=true;
        break;
      }

  for(int i=0; i<size; i++)
    if(!usedIndexes[i]){
      flag = false;
      break;
    }
  return flag;
}

/*
// test the checkArraysElements function
void testCompareArraysFunc(void)
{
  array2[0] = array1[size-1];
  array2[size-1] = array1[0];
  TEST_ASSERT_MESSAGE(checkArraysElements(),"Error in compareArray function");
}
*/

// check if array1 is in the correct order
static bool isArrayInCorrectOrder(int* array1, int size){
  for(int i=0; i<size-1; i++)
    if(array1[i]>array1[i+1])
      return false;

  return true;
}
