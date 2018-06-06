#include <iostream>
#include <time.h>

using namespace std;

const int MAX_SIZE = 20;

void fillArray(int A[], int size, int seed);
void printArray(const int A[], int size);

int bubbleSort(int A[], int size);
int insertionSort(int A[], int size);
int mergeSort(int A[], int first, int last);
int merge(int A[], int first, int mid, int last);
int quickSort(int A[], int first, int last);
int partition(int A[], int first, int last, int &comp);

int main()
{
	int myArray[MAX_SIZE];

	cout << "Array before Bubble Sort:" << endl;
	fillArray(myArray, MAX_SIZE, 5);
	printArray(myArray, MAX_SIZE);
	cout << "Array after Bubble Sort:" << endl;
	int bubComp = bubbleSort(myArray, MAX_SIZE);
	printArray(myArray, MAX_SIZE);
	cout << "Number of comparisons for Bubble Sort = " << bubComp << endl;
	system("pause");
	cout << " " << endl;

	cout << "Array before Insertion Sort:" << endl;
	fillArray(myArray, MAX_SIZE, 7);
	printArray(myArray, MAX_SIZE);
	cout << "Array after Insertion Sort:" << endl;
	int insComp = insertionSort(myArray, MAX_SIZE);
	printArray(myArray, MAX_SIZE);
	cout << "Number of comparisons for Insertion Sort = " << insComp << endl;
	system("pause");
	cout << " " << endl;

	cout << "Array before Merge Sort:" << endl;
	fillArray(myArray, MAX_SIZE, 2);
	printArray(myArray, MAX_SIZE);
	cout << "Array after Merge Sort:" << endl;
	int merComp = mergeSort(myArray, 0, MAX_SIZE-1);
	printArray(myArray, MAX_SIZE);
	cout << "Number of comparisons for Insertion Sort = " << merComp << endl;
	system("pause");
	cout << " " << endl;

	cout << "Array before Quick Sort:" << endl;
	fillArray(myArray, MAX_SIZE, 4);
	printArray(myArray, MAX_SIZE);
	cout << "Array after Quick Sort:" << endl;
	int quiComp = quickSort(myArray, 0, MAX_SIZE - 1);
	printArray(myArray, MAX_SIZE);
	cout << "Number of comparisons for Insertion Sort = " << quiComp << endl;
	system("pause");

	return 1;
}

int bubbleSort(int A[], int size)
{
	int temp = 0;
	int x = 0;
	int y = 0;
	int comp = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				comp++;
			}
		}
	}
	return comp;
}

int insertionSort(int A[], int size)
{
	int j;
	int temp;
	int comp=0;

	for (int i = 0; i < size; i++)
	{
		j = i;

		while (j > 0 && A[j] < A[j - 1])
		{
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
			comp++;
		}
	}
	return comp;
}

int merge(int A[], int first, int mid, int last)
{
	int temp[MAX_SIZE];
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;
	int comp = 0;
	int index = first1;

	while ((first1 <= last1) && (first2 <= last2))
	{
		if (A[first1] < A[first2])
		{
			temp[index] = A[first1];
			first1++;
		}
		else
		{
			temp[index] = A[first2];
			first2++;
		}
		index++;
	}

	while (first1 <= last1)
	{
		temp[index] = A[first1];
		first1++;
		index++;
		comp++;
	}

	while (first2 <= last2)
	{
		temp[index] = A[first2];
		first2++;
		index++;
		comp++;
	}

	for (index = first; index <= last; index++)
	{
		A[index] = temp[index];
		comp++;
	}
	return comp;
}

int mergeSort(int A[], int first, int last)
{
	int count = 0;

	if (first < last)
	{
		int mid = first + (last - first) / 2;
		count += mergeSort(A, first, mid);
		count += mergeSort(A, mid + 1, last);
		count += merge(A, first, mid, last);
	}
	return count;
}

int partition(int A[], int first, int last, int &comp)
{
	int temp[MAX_SIZE];
	int pivotIndex = last;
	int pivot = A[pivotIndex];
	int indexFromLeft = first;
	int indexFromRight = last - 1;
	bool done = false;

	while (!done)
	{
		while (A[indexFromLeft] < pivot)
		{
			indexFromLeft++;
			comp++;
		}

		while (A[indexFromRight] > pivot)
		{
			indexFromRight--;
			comp++;
		}

		if (indexFromLeft < indexFromRight)
		{
			temp[indexFromRight] = A[indexFromRight];
			A[indexFromRight] = A[indexFromLeft];
			A[indexFromLeft] = temp[indexFromRight];
			indexFromLeft++;
			indexFromRight--;
			comp++;
		}
		else done = true;
	}

	temp[pivotIndex] = A[indexFromLeft];
	A[indexFromLeft] = A[pivotIndex];
	A[pivotIndex] = temp[pivotIndex];

	pivotIndex = indexFromLeft;

	return pivotIndex;
}

int quickSort(int A[], int first, int last)
{
	int count = 0;
	
	if (first < last)
	{
		int pivot = partition(A, first, last, count);
		count += quickSort(A, first, pivot - 1);
		count += quickSort(A, pivot + 1, last);
	}
	return count;
}

void fillArray(int A[], int size, int seed)
{
	srand(seed);

	for (int i = 0; i < size; i++)
	{
		A[i] = (rand() % 101);
	}
}

void printArray(const int A[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		cout << A[i] << ", ";
	}
	cout << A[size - 1] << ";" << endl;
}