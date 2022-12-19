#include "QuickSort.h"
#include <iostream>

void printQuick(int**, int, int);
void sortQuick(int**, int, int, int, int);
int Partition(int**, int, int, int, int);

QuickSort :: QuickSort(int* a, int printArray, int printComparison, int size)
{
  array = a;
  this->printArray = printArray;
  this->printComparison = printComparison;
  this->size = size;
  array[0] = 0;
  int one = 1;
  sortQuick(&array, one, size, printArray, printComparison);
}


int* QuickSort :: getArray()
{
  return this->array;
}

void sortQuick(int** array, int p, int r, int printArray, int printComparison)
{
  if(p < r)
    {
      int q = Partition(array, p, r, printArray, printComparison);
      sortQuick(array, p, q-1, printArray, printComparison);
      sortQuick(array, q+1, r, printArray, printComparison);
    }
}

int Partition(int** array, int p, int r, int printArray, int printComparison)
{
  int temp;
  int x = (*array)[r];
  int i = p-1;
  
  if(printArray == 0)
    {
      if(printComparison == 0)
    	{
	      for(int j = p; j < r; j++)
	      {
          (*array)[0]++;
          if((*array)[j]<=x)
		      {
	      	  i++;
		        temp = (*array)[i];
	      	  (*array)[i] = (*array)[j];
        	  (*array)[j] = temp;
        	}
	      }
	      temp = (*array)[i+1];
	      (*array)[i+1] = (*array)[r];
        (*array)[r] = temp;
      }
      
      if(printComparison == 1)
	{
	  for(int j = p; j < r; j++)
            {
              printf("EWC: %d <= %d?\n", (*array)[j], x);
              (*array)[0]++;
              if((*array)[j]<=x)
                {
                  i++;
                  temp = (*array)[i];
                  (*array)[i] = (*array)[j];
                  (*array)[j] = temp;
                }
            }
          temp = (*array)[i+1];
          (*array)[i+1] = (*array)[r];
          (*array)[r] = temp;
        }
    }

  if(printArray == 1)
    {
      if(printComparison == 0)
        {
          for(int j = p; j < r; j++)
            {
              (*array)[0]++;
              if((*array)[j]<=x)
                {
                  i++;
                  temp = (*array)[i];
                  (*array)[i] = (*array)[j];
                  printQuick(array, p, r);
                  (*array)[j] = temp;
                  printQuick(array, p, r);
                }
            }
          temp = (*array)[i+1];
          (*array)[i+1] = (*array)[r];
          printQuick(array, p, r);
          (*array)[r] = temp;
          printQuick(array, p, r);
        }

      if(printComparison == 1)
        {
          for(int j = p; j < r; j++)
            {
              printf("EWC: %d <= %d?\n", (*array)[j], x);
              (*array)[0]++;
              if((*array)[j]<=x)
		            {
                  i++;
                  temp = (*array)[i];
                  (*array)[i] = (*array)[j];
                  printQuick(array, p, r);
                  (*array)[j] = temp;
                  printQuick(array, p, r);
                }
            }
          temp = (*array)[i+1];
          (*array)[i+1] = (*array)[r];
          printQuick(array, p, r);
          (*array)[r] = temp;
          printQuick(array, p, r);
	}
    }

  return i+1;
}

void printQuick(int** array, int start, int size)
{
  if(start > size)
    {
      return;
    }
  printf("A[%d:%d]:", start, size);
  for(int i = start; i<=size; i++)
    {
      printf(" %d", (*array)[i]);
    }
  printf("\n");
}
