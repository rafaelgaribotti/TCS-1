#include "unity_fixture.h"

static void RunAllTests(void)
{
  printf("\n --- Selection Sort ---\n");
  RUN_TEST_GROUP(SelectionSort);
  printf("\n --- Insertion Sort ---\n");
  RUN_TEST_GROUP(InsertionSort);
  printf("\n --- Shell Sort ---\n");
  RUN_TEST_GROUP(ShellSort);
  printf("\n --- Quick Sort ---\n");
  RUN_TEST_GROUP(QuickSort);
  printf("\n --- Heap Sort ---\n");
  RUN_TEST_GROUP(HeapSort);
  printf("\n --- Merge Sort ---\n");
  RUN_TEST_GROUP(MergeSort);
}

int main(int argc, const char * argv[])
{
  return UnityMain(argc, argv, RunAllTests);
}
