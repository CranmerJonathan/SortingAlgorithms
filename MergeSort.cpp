#include "MergeSort.h"
#include <iostream>

void printSort(int**, int, int);
void sort(int**, int, int, int, int);
void Merge(int**, int, int, int, int, int);

MergeSort :: MergeSort(int* array, int printArray, int printComparison, int size)
{
  this->array = array;
  this->printArray = printArray;
  this->printComparison = printComparison;
  this->size = size;
  (this->array)[0] = 0;
  sort(&(this->array), 1, this->size, this->printArray, this->printComparison);
}

int* MergeSort :: getArray()
{
  return this->array;
}

void printSort(int** array, int start, int size)
{
  printf("A[%d:%d]:", start, size);
  for(int i = start; i<=size; i++)
    {
      printf(" %d", (*array)[i]);
    }
  printf("\n");
}

void Merge(int** array, int p, int q, int r, int printArray, int printComparisons)
{
  int i;
  int j;
  int k = p;

  int nL = q - p + 1;
  int nR = r - q;

  int* L = new int[nL+1];
  int* R = new int[nR+1];

  
  for(i = 1; i < nL + 1; i++)
    {
      L[i] = (*array)[p + i - 1];
    }

  for(j = 1; j < nR + 1; j++)
    {
      R[j] = (*array)[q+j];
    }

  i = 1;
  j = 1;

  if(printArray == 0)
    {
      if(printComparisons == 0)
	{
	  while(i < nL + 1 && j < nR + 1)
	    {
	      if(L[i] <= R[j])
		{
		  (*array)[0]++;
		  (*array)[k] = L[i];
		  i++;
		}
	      else
		{
		  (*array)[0]++;
		  (*array)[k] = R[j];
		  j++;
		}
	      k++;
	    }
	  while(i < nL + 1)
	    {
	      (*array)[k] = L[i];
	      i++;
	      k++;
	    }
	  while(j < nR + 1)
	    {
	      (*array)[k] = R[j];
	      j++;
	      k++;
	    }
	}
      if(printComparisons == 1)
	{
	  while(i < nL + 1 && j < nR + 1)
	    {
	      if(L[i] <= R[j])
		{
		  (*array)[0]++;
		  printf("EWC: %d <= %d?\n", L[i], R[j]);
		  (*array)[k] = L[i];
		  i++;
		}
	      else
		{
		  (*array)[0]++;
		  printf("EWC: %d <= %d?\n", L[i], R[j]);
		  (*array)[k] = R[j];
		  j++;
		}
	      k++;
	    }
	  while(i < nL + 1)
	    {
	      (*array)[k] = L[i];
	      i++;
	      k++;
	    }
	  while(j < nR + 1)
	    {
	      (*array)[k] = R[j];
	      j++;
	      k++;
	    }
	}
    }

  if(printArray == 1)
    {
      if(printComparisons == 0)
        {
          while(i < nL + 1 && j < nR + 1)
            {
              if(L[i] <= R[j])
                {
                  (*array)[0]++;
		  (*array)[k] = L[i];
                  i++;
		  printSort(array, p, r);
                }
              else
                {
                  (*array)[0]++;
		  (*array)[k] = R[j];
                  j++;
                  printSort(array, p, r);
                }
              k++;
            }
          while(i < nL + 1)
            {
              (*array)[k] = L[i];
              i++;
              k++;
	      printSort(array, p, r);
            }
	  while(j < nR + 1)
            {
              (*array)[k] = R[j];
              j++;
              k++;
	      printSort(array, p, r);
            }
	}
      if(printComparisons == 1)
	{
	  while(i < nL + 1 && j < nR + 1)
	    {
	      if(L[i] <= R[j])
		{
		  (*array)[0]++;
		  printf("EWC: %d <= %d?\n", L[i], R[j]);
		  (*array)[k] = L[i];
		  i++;
		  printSort(array, p, r);
		}
	      else
		{
		  (*array)[0]++;
		  printf("EWC: %d <= %d?\n", L[i], R[j]);
		  (*array)[k] = R[j];
		  j++;
		  printSort(array, p, r);
		}
	      k++;
	    }
	  while(i < nL + 1)
	    {
	      (*array)[k] = L[i];
	      i++;
	      k++;
	      printSort(array, p, r);
	    }
	  while(j < nR + 1)
            {
              (*array)[k] = R[j];
              j++;
              k++;
	      printSort(array, p, r);
            }
        }
    }

  delete[] L;
  delete[] R;
}

void sort(int** array, int p, int r, int printArray, int printComparison)
{
  if(p >= r)
    {
      return;
    }

  int q = (p+r)/2;
  sort(array, p, q, printArray, printComparison);
  sort(array, q+1, r, printArray, printComparison);
  Merge(array, p, q, r, printArray, printComparison);
}
