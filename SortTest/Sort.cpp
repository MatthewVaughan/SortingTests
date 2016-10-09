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

void Sort::mergeHelper(int data[], size_t inputSize)
{
	size_t sizeOne;
	size_t sizeTwo;

	if (inputSize > 1)
	{
		//Compute sizes of the subarrays
		sizeOne = inputSize / 2;
		sizeTwo = inputSize - sizeOne;

		mergeHelper(data, sizeOne);
		mergeHelper((data + sizeOne), sizeTwo);

		//Merge the two sorted halves
		merge(data, sizeOne, sizeTwo);
	}
}

void Sort::mergeSort()
{
	size_t sizeOne;
	size_t sizeTwo;

	if (size > 1)
	{
		//Compute sizes of the subarrays
		sizeOne = size / 2;
		sizeTwo = size - sizeOne;

		mergeHelper(data, sizeOne);
		mergeHelper((data + sizeOne), sizeTwo);

		//Merge the two sorted halves
		merge(data, sizeOne, sizeTwo);
	}
}

void Sort::merge(int data[], int sizeOne, int sizeTwo)
{
	int *temp,
		copied = 0,
		copied1 = 0,
		copied2 = 0,
		i;

	//Dynamically allocate temp array
	temp = new int[sizeOne + sizeTwo];

	//Merge elements, copying from two halves of data to the temp array
	while ((copied1 < sizeOne) && (copied < sizeTwo))
	{
		if (data[copied1] < (data + sizeOne)[copied2])
		{
			temp[copied++] = data[copied1++];
		}
		else
		{
			temp[copied++] = (data + sizeOne)[copied2++];
		}
	}

	//Copy any remaining entries in the left and right subarrays
	while (copied1 < sizeOne)
	{
		temp[copied++] = data[copied1++];
	}
	while (copied2 < sizeTwo)
	{
		temp[copied++] = (data + sizeOne)[copied2++];
	}

	//copy from temp back to the data array, and release temp's memory
	for (i = 0; i < sizeOne + sizeTwo; ++i)
	{
		data[i] = temp[i];
	}
	delete[] temp;
}

void Sort::quickHelper(int data[], int inputSize)
{
	int pivotIndex,
		left,
		right;

	if (inputSize > 1)
	{
		//Partition the array, and set the pivot index
		partition(data, inputSize, pivotIndex);

		//Compute the sizes of the subarrays
		left = pivotIndex;
		right = inputSize - left - 1;

		//Recursive calls will now sort the subarrays
		quickHelper(data, left);
		quickHelper((data + pivotIndex + 1), right);
	}
}

void Sort::quickSort()
{
	int pivotIndex,
		left,
		right;

	if (size > 1)
	{
		//Partition the array, and set the pivot index
		partition(data, size, pivotIndex);

		//Compute the sizes of the subarrays
		left = pivotIndex;
		right = size - left - 1;

		//Recursive calls will now sort the subarrays
		quickHelper(data, left);
		quickHelper((data + pivotIndex + 1), right);
	}
}

void Sort::partition(int data[], int inputSize, int& pivotIndex)
{
	int pivot = data[0],
		tooBigIndex = 1,
		tooSmallIndex = inputSize - 1;

	while (tooBigIndex <= tooSmallIndex)
	{
		while (tooBigIndex != inputSize && data[tooBigIndex] <= pivot)
		{
			tooBigIndex++;
		}
		while (data[tooSmallIndex] > pivot)
		{
			tooSmallIndex--;
		}
		if (tooBigIndex < tooSmallIndex)
		{
			swap(data[tooBigIndex], data[tooSmallIndex]);
		}
	}
	pivotIndex = tooSmallIndex;
	data[0] = data[pivotIndex];
	data[pivotIndex] = pivot;
}

