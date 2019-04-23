#pragma once
#include "Matrix.h"

struct Data {
	int iterations;
	Matrix matrix;
};

Data gauss(Matrix &A, Matrix &b, int &size);
Data jacobi(Matrix &A,Matrix &b, int &size);
Matrix lu(Matrix &A, Matrix &b, int &size);