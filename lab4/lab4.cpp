#include <iostream>
#include <random>
#include <cassert>
#include <time.h>
#include <chrono>

using namespace std;

#pragma region 
int Search(const int value, int* array, const int size);
void quickSortIterative(int* array, int start, int finish);
void _swap(int* x, int* y);
int partition(int* array, const int first, const int last);
void printFirst50(int* array);
void quickSortRecursive(int* arr, const int first, const int last);
int IterativeBSearch(int* sortedArr, const int value, const int left, const int right);
int RecursiveBSearch(int* sortedArr, const int value, const int left, const int right);
void printSeparator();
#pragma endregion Block of pre-initialication methods


int main()
{
#pragma region 
	srand(time(NULL));
	int arrayForIter[50];
	int arrayForReq[50];
	for (int i = 0; i < 50; ++i) {
		auto temp = rand() % (10 + 10) - 10;
		arrayForIter[i] = temp;
		arrayForReq[i] = temp;
	}
	cout << "Here is non-sorted array: \n";
	printFirst50(arrayForIter);
#pragma endregion Create 2 equal arrays and fill by random values

#pragma region
	printSeparator();
	cout << "Sorted by iterativeQS:\n";
	quickSortIterative(arrayForIter, 0, 49);
	printFirst50(arrayForIter);
	cout << "\n\nSorted by recursiveQS:\n";
	quickSortRecursive(arrayForReq, 0, 49);
	printFirst50(arrayForReq);

#pragma endregion Block of sorting by QS and finding elemts
	
#pragma region 
	#pragma region 
	auto startTimerOfLinearSearch = chrono::high_resolution_clock::now();
	auto resultOfLinearSearch = Search(7, arrayForIter, 50);
	auto stopTimerOfLinearSearch = chrono::high_resolution_clock::now();
	printSeparator();
	cout << "Result of finding 7 with Linear search:\n" <<
		"Index: " << resultOfLinearSearch <<
		"\nTime: " << (stopTimerOfLinearSearch - startTimerOfLinearSearch).count() << " milliseconds";
	printSeparator();
#pragma endregion Linear Search

	#pragma region 
	auto startTimerOfIterBSearch = chrono::high_resolution_clock::now();
	auto resultOfIterBSearch = IterativeBSearch(arrayForIter, 7, 0, 49);
	auto stopTimerOfIterBSearch = chrono::high_resolution_clock::now();

	cout << "Index of 7 by IterativeSearch:\n" <<
		"Index: " << resultOfIterBSearch <<
		"\nTime: " << (stopTimerOfIterBSearch - startTimerOfIterBSearch).count() << " millisecons";
	printSeparator();
	#pragma endregion Iterative binary search
	
	#pragma region
	auto startTimerOfReqBSearch = chrono::high_resolution_clock::now();
	auto resultOfReqBSearch = RecursiveBSearch(arrayForReq, 7, 0, 49);
	auto stopTimerOfReqBSearch = chrono::high_resolution_clock::now();

	cout << "Index of 7 by Recursive search:\n" <<
		"Index: " << resultOfReqBSearch <<
		"\nTime: " << (stopTimerOfReqBSearch - startTimerOfReqBSearch).count() << " millisecons";
	printSeparator();
	#pragma endregion Recursive binary search
	
#pragma endregion Block of pinpointing the time of linear and binary search
}

int Search(const int value, int* array , const int size)
{
	for (int i = 0; i < size; ++i)
		if (array[i] == value) return i;
	return -1;
}

void quickSortIterative(int* array, int start, int finish) {
	int** pseudoStack = new int* [finish + 1];
	for (int i = 0; i <= finish; ++i)
		pseudoStack[i] = new int[2];
	int counter = 0;
	pseudoStack[counter][0] = start;
	pseudoStack[counter][1] = finish;
	++counter;
	int pivot;
	int begin, end;
	while (counter > 0) {
		--counter;
		begin = pseudoStack[counter][0];
		end = pseudoStack[counter][1];
		pivot = partition(array, begin, end);
		if (pivot - 1 > begin) {
			pseudoStack[counter][0] = begin;
			pseudoStack[counter][1] = pivot - 1;
			++counter;
		}
		if (pivot + 1 < end) {
			pseudoStack[counter][0] = pivot + 1;
			pseudoStack[counter][1] = end;
			++counter;
		}
	}
	//plugging the holes
	for (int i = 0; i <= finish; ++i)
		delete[] pseudoStack[i];
	delete[] pseudoStack;
}

void quickSortRecursive(int* arr, const int first, const int last) {
	int begin = first;
	int end = last;
	int pivot = partition(arr, begin, end);
	if (pivot - 1 > begin)
		quickSortRecursive(arr, begin, pivot-1);
	if (pivot + 1 < end)
		quickSortRecursive(arr, pivot + 1, end);
}

void _swap(int* x, int* y) {
	auto temp = x;
	*x = *y;
	*y = *temp;
}

int partition(int* array, const int first, const int last)
{
	int pivot = array[last];
	int step = first;
	for (int i = first; i < last; ++i) {
		if (array[i] <= pivot) {
			_swap(array[i], array[step]);
			++step;
		}
	}
	_swap(array[step], array[last]);
	return step;
}

void printFirst50(int* arr) {
	for (int i = 0; i < 50; ++i) {
		if (arr[i] == NULL) assert("Array doesn't exist 50+ elements");
		cout << arr[i] << ' ';
	}
}

int IterativeBSearch(int* sortedArr, const int value, int left, int right) {
	assert(!(sortedArr == nullptr) && "Array doesn't exist any elements");
	if (left == right) {
		if (sortedArr[left] == value)
			return left;
		return -1;
	}
	auto begin = left;
	auto end = right;

	int middleOfSearch;
	while (true) {
		if ((end - begin) == 1) break;
		middleOfSearch = (begin + end) / 2;
		if (sortedArr[middleOfSearch] < value)
			begin = middleOfSearch;
		if (sortedArr[middleOfSearch] > value)
			end = middleOfSearch;
		if (sortedArr[middleOfSearch] == value) 
			return middleOfSearch;
	}
	return begin == value ? begin : end == value ? end : -1;
}

int RecursiveBSearch(int* sortedArr, const int value, const int left, const int right)
{
	return sortedArr[(left + right) / 2] < value && right - left>1 ?
		RecursiveBSearch(sortedArr, value, (left + right) / 2, right) :
		sortedArr[(left + right) / 2] > value&& right - left > 1 ?
		RecursiveBSearch(sortedArr, value, left, (left + right) / 2) :
		sortedArr[(left + right) / 2] == value ? (left + right) / 2 : -1;
}

void printSeparator()
{
	cout << "\n===========================================\n";
}



