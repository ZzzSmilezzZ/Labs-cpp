#pragma once
#include <iostream>
#include <cassert>
#include <ctime>
#include "Matrix3x3.h"
#include "MatrixXnX.h"
#include "LinkedList.h"
#include <vector>

using namespace std;

int main()
{
	#pragma region
	cout << "========================================" << "\nMatrix 3x3\n" << "========================================\n";
	Matrix3x3 matr;
	matr.fillRandomElements(-10, 10);
	matr.printMatrix();
	cout << '\n';
	cout << "Sum of principial daig. elements: " << matr.sumPrincipialDiag() << '\n';
	cout << "Sum of secondary diag. elements: " << matr.sumSecondaryDiag() << '\n';
	cout << "Product of principail diag. elements: " << matr.productPrincipialDiag() << '\n';
	cout << "Product of secondary diag. elements: " << matr.productSecondaryDiag() << '\n';
	cout << "Sum of all rows: ";
	//Сумма элементов всех строк
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		sum += matr.sumRow(i);
	cout << sum << '\n';
	cout << "Min element in 2nd column " << matr.minColumn(1) << '\n';
	cout << "Max element in 2nd column " << matr.maxColumn(1) << '\n';
	#pragma endregion code for calling 3x3 matrix functions (1.1)

	#pragma region	
	cout << "\n========================================"<<"\nMatrix XnX\n" << "========================================\n" ;
	MatrixXnX XnXMatrix(6);
	XnXMatrix.fillRandomElements(-10, 10);
	XnXMatrix.printMatrix();
	cout << '\n';
	cout << "Sum of principial daig. elements: " << XnXMatrix.sumPrincipialDiag() << '\n';
	cout << "Sum of secondary diag. elements: " << XnXMatrix.sumSecondaryDiag() << '\n';
	cout << "Product of principail diag. elements: " << XnXMatrix.productPrincipialDiag() << '\n';
	cout << "Product of secondary diag. elements: " << XnXMatrix.productSecondaryDiag() << '\n';
	cout << "Sum of all rows: ";
	//Сумма элементов всех строк
	sum = 0;
	for (int i = 0; i < XnXMatrix.getSize(); ++i)
		sum += XnXMatrix.sumRow(i);
	cout << sum << '\n';
	cout << "Min element in 4th column " << XnXMatrix.minColumn(3) << '\n';
	cout << "Max element in 4th column " << XnXMatrix.maxColumn(3) << '\n';
	cout << "\n========================================\n";
	#pragma endregion code for calling XnX matrix functions (1.2)

	#pragma region
	cout << "Remove duplicates from LL\n" << "========================================\n";
	LinkedList* list = new LinkedList(); //Create an exemplar of LinkedList(LL)
	srand(unsigned(time(0))); //Put seed to generate pseudorandom numbers
	for (int i = 1; i <= 10; ++i) //Generate pseudorandom LL
		list->addNode(rand() % (15 - 5) + 5);
	cout << "Here is LinkedList: \n";
	list->printAllList();
	cout << '\n' << "Count: " << *&list->count << '\n';
	cout << "Element on k(3) pos from end: " << list->getElementOnPosFromEnd(3)->value << '\n';
	list->removeDuplicates();
	cout << "\nHere is the new LL w/o duplicates\n";
	list->printAllList();
	cout << '\n' << "Count: " << *&list->count << '\n';
	#pragma endregion work with LinkedList duplicates removing and find element on k pos from end (2,3)


}
