#include "Matrix2D.h"

Matrix2D::Matrix2D()
{
	this->setSize(2);
	this->fillMatrixNatutalNumbers(1);
}

int Matrix2D::element(unsigned int i, unsigned int j) const
{
	return matrix[i][j];
}

int& Matrix2D::element(unsigned int i, unsigned int j)
{
	return matrix[i][j];
}
