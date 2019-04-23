#pragma once
#include "Matrix.h"
#include <iostream>
#include <math.h>
#include <iomanip>





	Matrix::Matrix(int n, int m) // NxM
	{
		this->rows = n;
		this->columns = m;
		tab = new double *[n];
		for (int i = 0; i < n; i++)
			tab[i] = new double[m]; // tworzenie tablicy dwuwymiarowej

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				tab[i][j] = 0;
			}
		} // wypelnienie tablicy zerami 
	}

	Matrix::Matrix(int n) // NxN
	{
		this->rows = n;
		this->columns = n;
		tab = new double *[n];
		for (int i = 0; i < n; i++)
			tab[i] = new double[n]; // tworzenie tablicy dwuwymiarowej

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				tab[i][j] = 0;
			}
		} // wypelnienie tablicy zerami 
	}

	Matrix::Matrix(const Matrix & m) // KONSTRUKTOR KOPIUJACY
	{
		this->rows = m.getRows();
		this->columns = m.getColumns();
		int n = this->getRows();
		int ms = this->getColumns();
		tab = new double *[n];
		for (int i = 0; i < n; i++)
			tab[i] = new double[ms]; // tworzenie tablicy dwuwymiarowej

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < ms; j++)
			{
				tab[i][j] = m.tab[i][j];
			}


		}
	}


	Matrix::~Matrix()
	{
		for (int i = 0; i<rows; i++)
			delete[] this->tab[i];

		delete[]  this->tab;
	}

	void Matrix::setDiagonals(int a1, int a2, int a3) {
		for (int i = 0; i < rows; i++) {
			tab[i][i] = a1; // glowna przekatna
		}
		for (int i = 0; i < rows; i++) { // przekatne a2
			if(i!= rows-1)tab[i][i+1] = a2; // pomijamy ostatni wiersz
			if (i != 0)	tab[i][i - 1] = a2;	// pomijamy pierwszy wiersz
			if (i < rows - 2)tab[i][i + 2] = a3;
			if (i > 1)tab[i][i - 2] = a3;
		}
	}

	void Matrix::eye() {
		for (int i = 0; i < rows; i++) {
			tab[i][i] = 1; // glowna przekatna
		}
	}

	Matrix Matrix::inverseDiag(){
		Matrix newMatrix(this->rows, this->columns);
		for (int i = 0; i < rows; i++)
			newMatrix.tab[i][i] = 1.0 / this->tab[i][i];
		return newMatrix;
	}
			

	void Matrix::setVector() { // Ustawia wektor b z sinusami
		int f = 2;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				tab[i][j] = sin((i+1)*(f+1));
			}
		}
	}


	void Matrix::write() { // wypisz 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << std::setw(6)<< tab[i][j] << " ";
			}
		std::cout << std::endl;
		} 
		std::cout << std::endl;
	}

	double Matrix::norm() {
		double norm = 0;
		for (int i = 0; i < rows; i++) {
			norm += this->tab[i][0] * this->tab[i][0];
		}
		norm = sqrt(norm);
		return norm;

	}

	Matrix Matrix::lowerHalf() {
		Matrix newMatrix(this->rows, this->columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (i > 0 && j < i) newMatrix.tab[i][j] += this->tab[i][j];
			}
		}
		return newMatrix;
	}

	Matrix Matrix::upperHalf() {
		Matrix newMatrix(this->rows, this->columns); 
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (i <rows-1  && j > i) newMatrix.tab[i][j] += this->tab[i][j];
			}
		}
		return newMatrix;
	}

	Matrix Matrix::diag() {
		Matrix newMatrix(this->rows, this->columns); 
		for (int i = 0; i < rows; i++)
			newMatrix.tab[i][i] += this->tab[i][i];
		return newMatrix;
	}

	void Matrix::ones() {
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++) {
				this->tab[i][j] = 1.0;
			}
	}





	//GETTERS

	int Matrix::getRows()
	{
		return this->rows;
	}

	int Matrix::getColumns()
	{
		return this->columns;
	}

	int Matrix::getRows() const
	{
		return this->rows;
	}

	int Matrix::getColumns() const
	{
		return this->columns;
	}


	// OPERATORS

	Matrix Matrix::operator=(const Matrix & m)
	{
		this->rows = m.getRows();
		this->columns = m.getColumns();
		int n = this->getRows();
		int ms = this->getColumns();
		tab = new double *[n];
		for (int i = 0; i < n; i++)
			tab[i] = new double[ms]; // tworzenie tablicy dwuwymiarowej

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < ms; j++)
			{
				this->tab[i][j] = m.tab[i][j];
			}
		}
		return *this;
	}

	Matrix Matrix::operator+(const Matrix &added)
	{
		//if (this->rows == added.getRows() && this->columns == added.getColumns()) {
			Matrix newMatrix(this->rows, this->columns);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					newMatrix.tab[i][j] += this->tab[i][j] + added.tab[i][j];
				}


			}
			return newMatrix;
		}
	//	else {
	//		std::cout << "Macierze musza byc tego samego rozmiaru podczas dodawania";
	//		abort();
	//	}  // zakoncz program ;
	//}

	Matrix Matrix::operator-(const Matrix &sub)
	{
		//if (this->rows == added.getRows() && this->columns == added.getColumns()) {
		Matrix newMatrix(this->rows, this->columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				newMatrix.tab[i][j] += this->tab[i][j] - sub.tab[i][j];
			}


		}
		return newMatrix;
	}




	Matrix Matrix:: operator*(const Matrix &mult) {
		Matrix newMatrix(this->rows, mult.getColumns());
		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < mult.getColumns(); j++) {
				newMatrix.tab[i][j] = 0;
				for (int k = 0; k < mult.getRows(); k++)
				{
					newMatrix.tab[i][j] += this->tab[i][k] * mult.tab[k][j];
				}
			}
		return newMatrix;
	}

	Matrix Matrix:: operator-() {
		Matrix newMatrix(this->rows, this->columns);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				newMatrix.tab[i][j] = this->tab[i][j] * -1.0;
			}
		} 
		return newMatrix;

	}

	Matrix Matrix::operator/(const Matrix & b) // wzor z wikipedii
	{
		Matrix newMatrix(this->getRows(), 1); // wektor rozwiazan (ma tyle samo wierszy co lewy operand
		int m = this->getRows();
		for (int i = 0; i < m; i++) {
			double sum = 0;
			if (i != 0) {
				for (int j = 0; j < m - 1; j++) {
					sum += this->tab[i][j]*newMatrix.tab[j][0];
				}
				newMatrix.tab[i][0] = (b.tab[i][0] - sum) / this->tab[i][i];
			}
			else newMatrix.tab[i][0] = b.tab[i][0] / this->tab[i][0]; // jesli pierwszy elem
		}
		return newMatrix;
	}
	Matrix Matrix::operator%(const Matrix & b) // backward substitution
	{
		Matrix newMatrix(this->getRows(), 1); // wektor rozwiazan (ma tyle samo wierszy co lewy operand
		int m = this->getRows();
		for (int i = m-1; i >= 0; i--) {
			double sum = 0;
			if (i != m-1) { // jesli nie jest pierwszym elementem od dolu 
				for (int j = m-1; j >0; j--) {
					sum += this->tab[i][j] * newMatrix.tab[j][0];
				}
				newMatrix.tab[i][0] = (b.tab[i][0] - sum) / this->tab[i][i];
			}
			else newMatrix.tab[i][0] = b.tab[i][0] / this->tab[i][i];
		}
		return newMatrix;


	}


	/*Matrix operator+(Matrix  matrix1, Matrix  matrix2)
	{
			Matrix newMatrix(matrix1.getRows(), matrix1.getColumns());
			for (int i = 0; i < matrix1.getRows(); i++) {
				for (int j = 0; j < matrix1.getColumns(); j++) {
					newMatrix.tab[i][j] += matrix1.tab[i][j] + matrix2.tab[i][j];
				}


			}
			return newMatrix;
	}*/
