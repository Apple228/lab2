#pragma once

#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;
template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int Size;  //размер вектора
	int StartIndex; //индекс первого элемента вектора
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); //конструктор копирования
	~TVector();
	int GetSize() { return Size; }  //размер вектора 
	int GetStartIndex(){return StartIndex} //индекс первого элемента
	ValType& GetValue(int pos); //доступ с контролем индекса
	ValType& operator[](int pos); //доступ
	int operator==(const TVector& v); //сравнение
	TVector& operator = (const TVector& v);
	//скалярные операции
	TVector operator + (const ValType& val); //прибавить скаляр
	TVector operator - (const ValType& val); //вычесть скаляр
	TVector operator * (const TVector& val); //умножить на скаляр
	//векторные операции
	TVector operator + (const TVector& v); //сложение
	TVector operator - (const TVector& v); //вычитание
	ValType operator* (const TVector& v); //скалярное произведение\
	//ввод-вывод
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<< (ostream& out, const TVector& v) {
		for (int i = ; i < v.Size; i++) 
			out << v.pTVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si) {
	pVector = new ValType[s];
	Size = s;
	StartIndex = si;
}

template <class ValType>
TVector<ValType>::TVector(const TVector<ValType>& v) { //конструктор копирования
	pVector = new ValType[v.Size];
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
	{
		p.Vector[i] = v.pVector[i];
	}
}
//template <class ValType>
//virtual ~Tvector() {
//	delete[] pVector;
//}

template <class ValType>
ValType& TVector<ValType>::operator[] (int pos) {//достпуп без контроля индекса
	return pVector[pos - StartIndex];
}
template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v) {//присваивание
	if (this != &v) {
		if (Size != v.Size) {
			delete[] pVector;
			pVector = new ValType[v.Size];
		}
		Size = v.Size;
		StartIndex = v.StartIndex;
		for (int i = 0; i < Size; i++){
			pVector[i] = v.pVector[i];
		}
	return *this;
	}
}
template <class ValType>
TVector<ValType> TVector<ValType>::operator+ (const TVector<ValType>& v) {
	TVector temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
}