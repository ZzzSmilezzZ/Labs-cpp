#pragma once
#include <iostream>

using namespace std;

class MatrixBase
{
protected:
	explicit MatrixBase(unsigned int iSize);
	void setSize(unsigned int iSize);
public: 
	explicit MatrixBase();
	unsigned int size();
	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;
	void operator *= (int iMult);
	void operator += (MatrixBase& iAdd);
	void fillMatrixNatutalNumbers(const int startNumber);
	friend ostream& operator<< (ostream& stream, const MatrixBase& iMatrix);

private:
	unsigned int m_size;
	//hello will u work today??!?!??!?!
};

