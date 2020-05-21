#pragma once

class Matrix3x3
{

	
public:
	static constexpr int count = 3;
	Matrix3x3();
	void printMatrix();
	int element(const int i, const int j) const;
	void setElement(const int i, const int j, const int value);
	void fillRandomElements(const int minVal, const int maxVal);
	int sumPrincipialDiag() const;
	int sumSecondaryDiag() const;
	int productPrincipialDiag() const;
	int productSecondaryDiag() const;
	int sumRow(const int iRow) const;
	int minColumn(const int j) const;
	int maxColumn(const int j) const;
private:
	int matrix[count][count];
};

