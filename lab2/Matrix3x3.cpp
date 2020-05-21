#pragma once
#include "Matrix3x3.h"
#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

Matrix3x3::Matrix3x3()
{
	for (auto& x : matrix)
	{
		for (auto& y : x)
			y = 0;
	}
}

void Matrix3x3::printMatrix() {
	for (auto& x : Matrix3x3::matrix) {
		for (auto& y : x)
			cout << y << '\t';
		cout << '\n';
	}
}

int Matrix3x3::element(const int i, const int j) const
{
	assert(!(i <= 0 || i > count || j <= 0 || j > count) && "Some index is out of range");
	return Matrix3x3::matrix[i - 1][j - 1];
}

void Matrix3x3::setElement(const int i, const int j, const int value) {
	Matrix3x3::matrix[i - 1][j - 1] = value;
}

//Заполнитель матрицы псевдослучайными значениями в промежутке
void Matrix3x3::fillRandomElements(const int minVal, const int MaxVal) {
	srand(unsigned(time(0)));
	for (auto& x : Matrix3x3::matrix)
	{
		for (auto& y : x)
			y = rand() % (MaxVal - minVal) + minVal;
	}
}

//Вывод суммы элементов главной диагонила
int Matrix3x3::sumPrincipialDiag() const {
	int sum = 0;
	for (int i = 0; i < count; ++i)
		sum += Matrix3x3::matrix[i][i];
	return sum;
}

//Вывод суммы элементов побочной диагонали
int Matrix3x3::sumSecondaryDiag() const {
	int sum = 0;
	for (int i = 0; i < count; ++i)
		sum += Matrix3x3::matrix[i][2 - i];
	return sum;
}

//Вывод произведения элементов главной диагонали
int Matrix3x3::productPrincipialDiag() const {
	int product = 1;
	for (int i = 0; i < count; ++i)
		product *= Matrix3x3::matrix[i][i];
	return product;
}

//Вывод произведения элементов побочной диагонали 
int Matrix3x3::productSecondaryDiag() const {
	int product = 1;
	for (int i = 0; i < count; ++i)
		product *= Matrix3x3::matrix[i][2 - i];
	return product;
}

//Сумма элементов i-ой строки
int Matrix3x3::sumRow(const int iRow) const {
	int sum = 0;
	for (int i = 0; i < count; ++i)
		sum += Matrix3x3::matrix[iRow][i];
	return sum;
}

//Минимальный элемент в j-ом столбце
int Matrix3x3::minColumn(const int j) const {
	int min = INT16_MAX;
	for (int i = 0; i < count; ++i)
		if (min > Matrix3x3::matrix[i][j]) min = Matrix3x3::matrix[i][j];
	return min;
}

//Максимум в j-ом столбце 
int Matrix3x3::maxColumn(const int j) const {
	int max = INT16_MIN;
	for (int i = 0; i < count; ++i)
		if (max < Matrix3x3::matrix[i][j]) max = Matrix3x3::matrix[i][j];
	return max;
}