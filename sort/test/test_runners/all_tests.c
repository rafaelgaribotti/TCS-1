#include "unity_fixture.h"

static void RunAllTests(void)
{
  //printf("\n");
  RUN_TEST_GROUP(SortArray);
  //printf("\n");
  RUN_TEST_GROUP(SelectionSort);
  //printf("\n");
  RUN_TEST_GROUP(InsertionSort);
  //printf("\n");
  RUN_TEST_GROUP(ShellSort);
  //printf("\n");
  RUN_TEST_GROUP(QuickSort);
  //printf("\n");
  RUN_TEST_GROUP(HeapSort);
  //printf("\n");
  RUN_TEST_GROUP(MergeSort);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
