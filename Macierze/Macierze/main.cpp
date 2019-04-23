#include <iostream>
#include <fstream>
#include <chrono>
#include "Matrix.h"
#include "methods.h"



//172223


int main() {
	//std::ofstream myFile;
	int a1 = 5 + 2;
	int a2 = -1;
	int a3 = -1;
	int it_jcb = 0;
	int it_gau = 0;
	//int a1 = 3;
	//int a2 = 3;
	//int a3 = -1;
	int tablica[5] = { 923 , 500,1000,2000,3000 };
	//myFile.open("test.csv", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < 1; i++) {
		int N = tablica[i];
		Matrix A(N); // Matrix A
		Matrix b(N, 1); // Wektor kolumnowy b 
		A.setDiagonals(a1, a2, a3);
		b.setVector();
		//		 METODA JACOBIEGO
		auto start = std::chrono::steady_clock::now(); // MIERNIK CZASU
		it_jcb = jacobi(A, b, N).iterations;
		auto end = std::chrono::steady_clock::now();
		auto time_jacobi = end - start;

		//		METODA GAUSSA
		start = std::chrono::steady_clock::now();
		it_gau = gauss(A, b, N).iterations;
		end = std::chrono::steady_clock::now();
		auto time_gauss = end - start;

		// METODA BEZPOSREDNIA
		start = std::chrono::steady_clock::now();
		lu(A, b, N);
		end = std::chrono::steady_clock::now();
		auto time_bezp = end - start;

		printf("Iteracje JACOBI: %i \n", it_jcb);
		printf("Iteracje GAUSS: %i \n", it_gau);
		std::cout << "Czas JACOBI: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_jacobi).count() << " ms " << std::endl;
		std::cout << "Czas GAUSS: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_gauss).count() << " ms " << std::endl;
		std::cout << "Czas BEZPOSREDNIA: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_bezp).count() << " ms " << std::endl;
		/*myFile << N << "," << std::chrono::duration_cast<std::chrono::milliseconds>(time_jacobi).count()
			<< "," << N << "," << std::chrono::duration_cast<std::chrono::milliseconds>(time_gauss).count()
			<< "," << N << "," << std::chrono::duration_cast<std::chrono::milliseconds>(time_bezp).count()
			<< std::endl;
		   */
	}
	//myFile.close();
	return 0;

}