#pragma once
#include "MatrixXnX.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


MatrixXnX::MatrixXnX(const int iDim)
{
	matrix = new int[iDim*iDim];
	for (int i = 0; i < iDim; ++i)
		for (int j = 0; j < iDim; ++j)
			matrix[i * iDim + j] = 0;
	MatrixXnX::size = iDim;
}

MatrixXnX::~MatrixXnX()
{
	delete[] matrix;
}

void MatrixXnX::printMatrix() {
	for (int i = 0; i < size * size; ++i) {
		if (i % size == 0) cout << '\n';
		cout << matrix[i] << '\t';
	}

}

int MatrixXnX::element(const int i, const int j) const
{
	return MatrixXnX::matrix[(i - 1) * size + (j-1)];
}

void MatrixXnX::setElement(const int i, const int j, const int value) {
	MatrixXnX::matrix[(i - 1) * size + (j - 1)] = value;
}

//Заполнитель матрицы псевдослучайными значениями в промежутке
void MatrixXnX::fillRandomElements(const int minVal, const int MaxVal) {
	srand(unsigned(time(0)));
	for (int i = 0; i < size*size; ++i)
			matrix[i] = rand() % (MaxVal - minVal) + minVal;;
}


//Вывод суммы элементов главной диагонила
int MatrixXnX::sumPrincipialDiag() const {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += MatrixXnX::matrix[i* size + i];
	return sum;
}

//Вывод суммы элементов побочной диагонали
int MatrixXnX::sumSecondaryDiag() const {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += MatrixXnX::matrix[i*size + size-1 - i];
	return sum;
}

//Вывод произведения элементов главной диагонали
int MatrixXnX::productPrincipialDiag() const {
	int product = 1;
	for (int i = 0; i < size; ++i)
		product *= MatrixXnX::matrix[i*size + i];
	return product;
}

//Вывод произведения элементов побочной диагонали 
int MatrixXnX::productSecondaryDiag() const {
	int product = 1;
	for (int i = 0; i < size; ++i)
		product *= MatrixXnX::matrix[i*size + size -1 - i];
	return product;
}

//Сумма элементов i-ой строки
int MatrixXnX::sumRow(const int iRow) const {
	int sum = 0;
	for (int i = 0; i < size; ++i)
		sum += MatrixXnX::matrix[iRow*size + i];
	return sum;
}

//Минимальный элемент в j-ом столбце
int MatrixXnX::minColumn(const int j) const {
	int min = INT16_MAX;
	for (int i = 0; i < size; ++i)
		if (min > MatrixXnX::matrix[i*size + j]) min = MatrixXnX::matrix[i*size + j];
	return min;
}

//Максимум в j-ом столбце 
int MatrixXnX::maxColumn(const int j) const {
	int max = INT16_MIN;
	for (int i = 0; i < size; ++i)
		if (max < MatrixXnX::matrix[i*size + j]) max = MatrixXnX::matrix[i*size + j];
	return max;
}

