#pragma once

#include <conio.h>
#include <iomanip>
#include <iostream>

template <class ValType>
class TVector {
protected:
	ValType* pVector;
	int Size;  //������ �������
	int StartIndex; //������ ������� �������� �������
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector &v); //����������� �����������
	~TVector();
	int GetSize() { return Size; }  //������ ������� 
	int GetStartIndex(){return StartIndex} //������ ������� ��������
	ValType& GetValue(int pos); //������ � ��������� �������
	ValType& operator[](int pos); //������
	int operator==(const TVector& v); //���������
	TVector& operator = (const TVector& v);
	//��������� ��������
	TVector operator + (const ValType& val); //��������� ������
	TVector operator - (const ValType& val); //������� ������
	TVector operator * (const TVector& val); //�������� �� ������
	//��������� ��������
	TVector operator + (const TVector& v); //��������
	TVector operator - (const TVector& v); //���������
	TVector operator* (const TVector& v); //��������� ������������\
	//����-�����
	friend istream& operator >> (istream& in, TVector& v) {
		for (int i = 0; i < v.Size; i++) 
			in >> v.pTVector[i];
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
TVector<ValType>::TVector(const TVector<ValType>& v) { //����������� �����������
	pVector = new ValType[v.Size];
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
	{
		p.Vector[i] = v.pVector[i];
	}
}
//template <class ValType>
//TVectror<ValType>::~Tvector() {
//	delete[] pVector;
//}

template <class ValType>
ValType& TVector<ValType>::operator[] (int pos) {//������� ��� �������� �������
	return pVector[pos - StartIndex];
}
template <class ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v) {//������������
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