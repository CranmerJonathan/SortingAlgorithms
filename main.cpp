/*Main file: takes in command line checks to make sure every is formatted correctly then it will open the text file and execute the sorting algorithm specified
 */

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using std::string;
using std::ifstream;
using std::cout;

void printArrays(int**, int);

int main(int argc, char* argv[])
{
  int *array, printComparison, input, size, printResult, printArray;
  string letterEater;

  if(argc != 3 || (strcmp(argv[1], "InsertionSort") != 0 && strcmp(argv[1], "MergeSort") != 0 && strcmp(argv[1], "QuickSort") != 0) || (strcmp(argv[2], "0") != 0 && strcmp(argv[2], "1") != 0))
    {
      printf("Usage: ./PJ1 alg flag");
      printf("\n       alg should be in {InsertionSort, MergeSort, QuickSort}");
      printf("\n       flag should be in {0, 1}\n");
      return 1;
    }

  printComparison = *argv[2] - '0';

  ifstream file;

  file.open("INPUT.txt");

  if(!file.is_open())
    {
      printf("Error: cannot open file INPUT.txt\n");
    }

  else
    {

      file >> printResult;
      file >> printArray;
      file >> size;

      array = new int[size + 1];

      for(int i = 1; i <= size; i++)
	{
	  file >> input;

	  array[i] = input;
	}

      if(strcmp(argv[1], "InsertionSort") == 0)
	{
	  InsertionSort* sort = new InsertionSort(array, printArray, printComparison, size);
	  array = sort->getArray();

	  if(printResult == 1)
	    {
	      printf("A[1:%d] after sorting:", size);
	      printArrays(&array, size);
	    }

            printf("Number of EWCs: %d\n", array[0]);
	}

      if(strcmp(argv[1], "MergeSort") == 0)
        {
          MergeSort* sort = new MergeSort(array, printArray, printComparison, size);
          array = sort->getArray();

          if(printResult == 1)
            {
              printf("A[1:%d] after sorting:", size);
              printArrays(&array, size);
            }

	  printf("Number of EWCs: %d\n", array[0]);
        }

      if(strcmp(argv[1], "QuickSort") == 0)
        {
          QuickSort* sort = new QuickSort(array, printArray, printComparison, size);
          array = sort->getArray();

          if(printResult == 1)
            {
              printf("A[1:%d] after sorting:", size);
              printArrays(&array, size);
            }

          printf("Number of EWCs: %d\n", array[0]);
        }

      delete array;
      }

  file.close();

  return 1;
}

void printArrays(int** array, int size)
{
  for(int i = 1; i<=size; i++)
    {
      printf(" %d", (*array)[i]);
    }   
  printf("\n");
}

