#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
	Matrix2D matrix2D1, matrix2D2;
	Matrix3D matrix3D1;
	matrix2D1 += matrix2D2;
	matrix3D1 *= 2;
	cout << "here 2d martix: \n" << matrix2D1 << '\n';
	cout << "here 3d martix: \n" << matrix3D1 << '\n';
}
