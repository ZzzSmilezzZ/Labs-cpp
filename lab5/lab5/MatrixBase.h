#pragma once
class MatrixBase
{
public: 
	unsigned int size();
	abstract int element(unsigned int i, unsigned int j) const;
	abstract int& element(unsigned int i, unsigned int j);
	operator*= (int iMult);
	operator+=(MatrixBase& iAdd)
protected: 
	MatrixBase(unsigned int iSize);
private:
	const unsigned int m_size;
	//hello will u work today??!?!??!?!
};

