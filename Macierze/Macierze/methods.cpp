#include "methods.h"
#include <iostream>


Data gauss( Matrix & A, Matrix & b, int &size)
{	
		Matrix L(size); // Dolna czesc A; Matrix U(size); // Gorna czesc A
		Matrix U(size); // Gorna czesc Matrix
		Matrix DL(size); // D + L
		Matrix D(size); // Diagonala
		Matrix x(size, 1); // Wektor kolumnowy rozwiazan
		Matrix res(size);
		int it_gau = 0; // liczba iteracji
		D = A.diag();
		U = A.upperHalf();
		L = A.lowerHalf();
		double pass = 0.000000001;// 10 ^-9
		x.ones();
		DL = D + L;
		res = (A*x) - b;
		while (res.norm() > pass) {
			x = DL / (-U * x + b); // zamiast odwracania macierzy -> forward substitution
			res = (A*x) - b;
			it_gau++;
		}
		Data data = { it_gau,x };
	return data;
}

Data jacobi( Matrix &A, Matrix &b, int &size)
{
	Matrix L(size); // Dolna czesc A; Matrix U(size); // Gorna czesc A
	Matrix U(size); // Gorna czesc Matrix
	Matrix LU(size); // L + U
	Matrix D(size); // Diagonala
	Matrix D_inv(size); // Diagonala odwrocona
	Matrix x(size, 1); // Wektor kolumnowy rozwiazan
	Matrix res(size);
	int it_jcb = 0;
	double pass = 0.000000001;// 10 ^-9
	x.ones();
	D = A.diag();
	D_inv = D.inverseDiag();
	U = A.upperHalf();
	L = A.lowerHalf();
	LU = L + U;
	res = (A * x) - b;
	while (res.norm() > pass) {
		x = D_inv * (b - (LU*x)); // metoda z wiki
		it_jcb++;
		res = (A * x) - b;
	}
	Data data = { it_jcb,x };

	return data;
}

Matrix lu(Matrix &A, Matrix &b, int &size) { 
	Matrix U(A);
	Matrix I(size);
	I.eye();
	Matrix L(I);
	Matrix y(size, 1); // wektor pomocniczy
	Matrix x(size, 1); // Wektor kolumnowy rozwiazan
	Matrix res(size);
	x.ones();
	int m = size;
	for (int k = 0; k < m - 1; k++) { // algorytm z wykladow
		for (int j = k + 1; j < m; j++) {
			I.tab[j][k] = U.tab[j][k] / U.tab[k][k];
			for (int i = k; i < m; i++) {
				U.tab[j][i] = U.tab[j][i] - (I.tab[j][k] * U.tab[k][i]);
			}
		}
	}
	L = I;
	y = L/b;
	x = U % y;
	res = (A * x) - b;
	std::cout << res.norm() << std::endl;

	
	
	return x;


	
	
}

