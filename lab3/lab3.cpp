#include <iostream>
#include "BinaryTree.h"
#include <random>
#include <time.h>

BinaryTree* CreateMinimalBST(int* arr, const int first, const int last);
int main()
{
	srand(time(NULL));
	BinaryTree tree;
	for (int i = 1; i <= 10; ++i)
		tree.Insert(rand()%(100-1));


	int array[6] = { 1,2,3,4,5,6 };
	auto test = CreateMinimalBST(array, 0, 5);
}

BinaryTree* CreateMinimalBST(int* arr, const int first, const int last) {
	auto const middle = (last + first) / 2;
	BinaryTree* tree = new BinaryTree(arr[middle]);
	for (int i = 1; i <= middle; i++) {
		tree->Insert(arr[middle - i]);
		tree->Insert(arr[middle + i]);
	}
	if (last % 2 != 0) tree->Insert(arr[last]);
	return tree;
}