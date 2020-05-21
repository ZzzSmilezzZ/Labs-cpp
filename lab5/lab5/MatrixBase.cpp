#include "MatrixBase.h"

MatrixBase(unsigned int iSize) {
	this.m_size = iSize;
}

unsigned int size()
{
	return m_size;
}

MatrixBase::operator*=(int iMult) {

}
