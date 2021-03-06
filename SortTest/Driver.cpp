#include "Sort.h"

int main() {

	Sort arr(10000);
	arr.set_seed(10);
	
	arr.init_array();
	cout << "selection sort" << endl;
	clock_t start = clock();
	arr.selectionSort();
	clock_t end = clock();
	clock_t diff = end - start;
	cout << "time taken= " << diff << " ticks or milliseconds" <<"\n" << endl;
	
	arr.init_array();
	cout << "insertion sort" << endl;
	clock_t start2 = clock();
	arr.insertionSort();
	clock_t end2 = clock();
	clock_t diff2 = end2 - start2;
	cout << "time taken= " << diff2 << " ticks or milliseconds" << "\n" << endl;
	
	arr.init_array();
	cout << "merge sort" << endl;
	clock_t start3 = clock();
	arr.mergeSort();
	clock_t end3 = clock();
	clock_t diff3 = end3 - start3;
	cout << "time taken= " << diff3 << " ticks or milliseconds" << "\n" << endl;

	arr.init_array();
	cout << "quick sort" << endl;
	clock_t start4 = clock();
	arr.quickSort();
	clock_t end4 = clock();
	clock_t diff4 = end4 - start4;
	cout << "time taken= " << diff4 << " ticks or milliseconds" << "\n\n\n" << endl;
	//-------------------------------------------------------------
	//**************PROOF******************************************
	//-------------------------------------------------------------
	Sort arr1(10);
	arr1.set_seed(10);

	arr1.init_array();
	cout << "Selection Sort Proof:" << endl;
	cout << arr1;
	arr1.selectionSort();
	cout << arr1 << "\n" << endl;

	arr1.init_array();
	cout << "Insertion Sort Proof:" << endl;
	cout << arr1;
	arr1.insertionSort();
	cout << arr1 << "\n" << endl;

	arr1.init_array();
	cout << "Merge Sort Proof:" << endl;
	cout << arr1;
	arr1.mergeSort();
	cout << arr1 << "\n" << endl;

	arr1.init_array();
	cout << "Quick Sort Proof:" << endl;
	cout << arr1;
	arr1.quickSort();
	cout << arr1 << "\n" << endl;

	system("PAUSE");
}