#pragma once

#include <conio.h>
#include <iomanip>
#include <iostream>

template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int Size;  //размер вектора
	int StartIndex; //индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector $v); //конструктор копирования
	~TVector();
	int GetSize() { return Size; }  //размер вектора 
	int GetStartIndex(){return StartIndex} //индекс первого элемента
	ValType& GetValue(int pos); //доступ с контролем индекса
	ValType& operator[](int pos); //доступ
	int operator==(const TVector& v); //сравнение
	TVector& operator = (const TVector& v);
	//скалярные операции
	TVector operator+ (const ValType& val); //прибавить скаляр
	TVector operator- (const ValType& val); //вычесть скаляр
	

	};