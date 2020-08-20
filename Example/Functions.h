#pragma once
#include <iostream>
#include<fstream>
#include <ctime>
#include<iomanip>
#include<vector>
using namespace std;
const double EPS = 1E-9;//��������� ��� ����������� ����� �������
using namespace System;
class Solution;

string& Convert_String_to_string(String^ s);// � String �� string
String^ Convert_string_to_String(string& os);// � string �� String 
string& Convert_String_to_string(String^ s, string os);// � String �� string
String^ Convert_string_to_String(string& os, String^ s);// � string �� String 

//���� ����-���� "����������", ���� ���� ������ ������ ������ ����(���,���� �����(��������/����),����������/���� �������)
class SLAR
{
public:
	SLAR();
	~SLAR();
	SLAR(const SLAR& other);
	//���� ����� ����'����
	double* Menu(Solution Functional);

	double** Matrix;					
	double* Result;		
	double* answer;
	//���������� ����� ����'����
	void setmethod(string way);
	//���������� �����
	void setsize(int size);
	//����� �����
	int getsize();
	//��������� �������
	double** createMatrix(int size);
	double* createResult(int size);
	double* createanswer(int size);
	//��������� ��������� ����������
	double** RandomMatrix(int size);
	double* RandomResult(int size);
	//������
	void vuvid2();
	void vuvid3();
	//����������
	double determ(double** Arr, int size);
	//����
	int compute_rank(double** A, int NumOfRofs, int NumOfCol);
	
	
private:

	int NumOfEquation;
	string method;
	int count = 0;
					
	
};


//���� Solution-���� "����'����"-
class Solution
{       //����
	double* gauss(double** Matrix, double* Result, int size);
	//���� � ������� ��������
	double* gaussM(double** Matrix, double* Result, int size);
	//�����̲����
	double determ(double** Arr, int size);
	//�̲�ު�� ������� ²���²���
	void glavelem(int k, double** mas, int n, int* otv);
	//������
	double* Kramer(double** Matrix, double* Result, int size);
public:friend double* SLAR::Menu(Solution Functional);

};