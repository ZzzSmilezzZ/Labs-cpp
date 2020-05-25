#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
	Matrix2D matrix2D1, matrix2D2;
	Matrix3D matrix3D1;
	cout << "2D1 martix: \n" << matrix2D1 << '\n';
	cout << "2D2 martix: \n" << matrix2D2 << '\n';
	matrix2D1 += matrix2D2;
	cout << "2D1 + 2D2 martix: \n" << matrix2D1 << '\n';
	cout << "Origianl 3D martix: \n" << matrix3D1 << '\n';
	matrix3D1 *= 2;
	cout << "3D matrix multiplied by 2: \n" << matrix3D1 << '\n';
}
