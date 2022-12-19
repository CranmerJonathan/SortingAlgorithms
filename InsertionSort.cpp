#include "InsertionSort.h"
#include <iostream>

void print(int**, int);
int* sort(int**, int, int, int);

InsertionSort :: InsertionSort(int* array, int printArray, int printComparison, int size)
{
  this->array = array;
  this->printArray = printArray;
  this->printComparison = printComparison;
  this->size = size;
  this->array = sort(&(this->array), this->printArray, this->printComparison, this->size);
}

int* InsertionSort :: getArray()
{
  return this->array;
}

int* sort(int** array, int printArray, int printComparison, int size)
{
  int i;
  int key;
  int j;
  (*(array)[0] = 0);
  if(printComparison == 0)
    {
      if(printArray == 0)
	{
	  for(i = 2; i <= size; i++)
	    {
	      key = (*array)[i];
	      j = i - 1;
	      while(j > 0 && ++(*(array)[0]) && (*array)[j] > key)
		{
		  (*array)[j+1] = (*array)[j];
		  j = j - 1;
		}
	      (*array)[j+1] = key;
	    }
	}

      if(printArray == 1)
	{
	  for(i = 2; i <= size; i++)
            {
              key = (*array)[i];
              j = i - 1;
              while(j > 0 && ++(*(array)[0]) && (*array)[j] > key)
		{
                  (*array)[j+1] = (*array)[j];
                  j = j - 1;
		  print(array, size);
		}
	      (*array)[j+1] = key;
	      print(array, size);
            }
	}
    }

  if(printComparison == 1)
    {
      if(printArray == 0)
        {
          for(i = 2; i <= size; i++)
            {
              key = (*array)[i];
              j = i - 1;
              while(j > 0 && ++(*(array)[0]) && printf("EWC: %d > %d?\n", (*array)[j], key) && (*array)[j] > key)
                {
                  (*array)[j+1] = (*array)[j];
                  j = j - 1;
                }
              (*array)[j+1] = key;
            }
        }

      if(printArray == 1)
        {
	  for(i = 2; i <= size; i++)
            {
              key = (*array)[i];
              j = i - 1;
              while(j > 0 && ++(*(array)[0]) && printf("EWC: %d > %d?\n", (*array)[j], key) && (*array)[j] > key)
                {
                  (*array)[j+1] = (*array)[j];
                  j = j - 1;
                  print(array, size);
                }
              (*array)[j+1] = key;
              print(array, size);
            }
        }
    }
  return *array;
}

void print(int** array, int size)
{
  printf("A[1:%d]:", size);
  for(int i = 1; i<=size; i++)
    {
      printf(" %d", (*array)[i]);
    }
  printf("\n");
}
