#pragma once
class Matrix
{
private:
	int rows; 
	int columns;
public:
	double **tab;

public:
	Matrix(int wiersze, int kolumny);
	Matrix(int rozmiar);
	Matrix(const Matrix &m); // konstruktor kopiujacy
	~Matrix();
	void setDiagonals(int a1, int a2, int a3); // stworz 5 przekatnych dla A
	void setVector(); // ustaw wektor b zaleznie od cosinusa
	void ones(); // wypelnij samymi 1 
	void write(); // wypisz macierz
	double norm(); // wylicza norme z wektora pionowego
	Matrix lowerHalf(); // tworzy macierz ponizej diagonali , reszta 0
	Matrix upperHalf(); // tworzy macierz powyzej diagonali, reszta 0
	Matrix diag(); // sama przekatna , reszta 0

	void eye(); // Macierz jednostkowa
	Matrix inverseDiag(); // odwraca przekatna macierzy STOSUJEMY TYLKO W MACIERZY GDZIE JEST TYLKO PRZEKATNA RESZTA 0





	//GETTERS
	int getRows();
	int getColumns();
	int getRows()const;
	int getColumns()const;

	//SETTERS

	//OPERATORS
	Matrix operator= (const Matrix& m);
	Matrix operator+(const Matrix &dodawana); // dodawanie macierzy
	Matrix operator*(const Matrix &mnozona); // mnozenie macierzy
	Matrix operator-();// wymnozenie wszystkich elementow macierzy * -1
	Matrix operator-(const Matrix &odejmowana); // odejmowanie
	Matrix operator/(const Matrix &subst); // forward substitution (macierz dolna)
	Matrix operator%(const Matrix &subst); // backward substitution (macierz gorna)
};



