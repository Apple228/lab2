#include <iostream>
#include<conio.h>
#include<iomanip>
#include "utmatr4.h"
#include "matrix.h"
using namespace std;
void main(){
	TMatrix<int> a(5), b(5), c(5);
	int i, j;
	setlocale(LC_ALL, "Rus");
	cout << "Тестирование программ поддержки представления треугольных матриц" << endl;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			a[i][j] = i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	
	cout << "Matrix a = " << endl << a << endl;
	//cout << "Matrix b = " << endl << b << endl; 
	//cout << "Matrix c = " << endl << c+b << endl; // сумму уже не считает
	cout << "" << endl;
}

