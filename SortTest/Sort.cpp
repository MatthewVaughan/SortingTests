#include "Sort.h"

Sort::Sort(int sizeArray)
{
	size = sizeArray;
	data = new int[sizeArray];
}

void Sort::set_seed(int seed)
{
	srand(seed);
}

Sort::~Sort()
{
}

void Sort::init_array()
{
	for (int i = 0; i < size; i++)
	{
		*(data + i) = rand() % size;
	}
}

void swap(int &tempOne, int &tempTwo)
{
	int temp = tempOne;
	tempOne = tempTwo;
	tempTwo = temp;
}

void Sort::selectionSort()
{
	int i,
		j,
		indexOfLargest = 0;
	int largest;

	if (size == 0)
	{
		return;
	}

	for (i = size-1; i > 0; i--)
	{
		largest = data[0];
		indexOfLargest = 0;
		for (j = 1; j <= i; ++j)
		{
			if (data[j] > largest)
			{
				largest = data[j];
				indexOfLargest = j;
			}
		}
		swap(data[i], data[indexOfLargest]);
	}
}

void Sort::insertionSort()
{
	
	for (int i = 0; i < size - 1; i++)
	{
		int j = i;
		while (data[j + 1] < data[j] && (data + j) != nullptr)
		{
			swap(data[j + 1], data[j]);
			j--;
		}
	}
}

