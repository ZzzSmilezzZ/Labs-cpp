#include "MatrixBase.h"
#include <iostream>

using namespace std;

MatrixBase::MatrixBase(unsigned int iSize)
{
	this->m_size = iSize;
}

void MatrixBase::setSize(unsigned int iSize)
{
	this->m_size = iSize;
}


MatrixBase::MatrixBase()
{
}

unsigned int MatrixBase::size()
{
	return m_size;
}

void MatrixBase::operator*=(int iMult) {
	for (int i = 0; i < this->m_size; ++i)
		for (int j = 0; j < this->m_size; ++j)
			element(i, j) *= iMult;
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (int i = 0; i < this->m_size; ++i)
		for (int j = 0; j < this->m_size; ++j)
			this->element(i, j) += iAdd.element(i, j);
}

void MatrixBase::fillMatrixNatutalNumbers(const int startNumber)
{
	int filler = startNumber;
	for (int i = 0; i < this->size(); ++i)
		for (int j = 0; j < this->size(); ++j) {
			this->element(i, j) = filler;
			++filler;
		}
}

ostream& operator<<(ostream& stream, const MatrixBase& iMatrix)
{
	for (int i = 0; i < iMatrix.m_size; ++i) {
		for (int j = 0; j < iMatrix.m_size; ++j)
			stream << iMatrix.element(i, j) << '\t';
		stream << '\n';
	}
		
	return stream;
}




