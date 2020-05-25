#include "Matrix3D.h"


Matrix3D::Matrix3D()
{
	this->setSize(3);
	this->fillMatrixNatutalNumbers(1);
}

int Matrix3D::element(unsigned int i, unsigned int j) const
{
	return matrix[i][j];
}

int& Matrix3D::element(unsigned int i, unsigned int j)
{
	return matrix[i][j];
}
