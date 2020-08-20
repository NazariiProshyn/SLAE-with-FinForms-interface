#pragma once
#include <iostream>
#include<fstream>
#include <ctime>
#include<iomanip>
#include<vector>
using namespace std;
const double EPS = 1E-9;//константа для знаходження рангу матриці
using namespace System;
class Solution;

string& Convert_String_to_string(String^ s);// з String до string
String^ Convert_string_to_String(string& os);// з string до String 
string& Convert_String_to_string(String^ s, string os);// з String до string
String^ Convert_string_to_String(string& os, String^ s);// з string до String 

//КЛАС СЛАР-клас "інформації", клас який містить основні методи СЛАР(Ввід,вивід даних(програма/файл),детермінант/ранг матриці)
class SLAR
{
public:
	SLAR();
	~SLAR();
	SLAR(const SLAR& other);
	//вибір шляху розв'язку
	double* Menu(Solution Functional);

	double** Matrix;					
	double* Result;		
	double* answer;
	//встановити метод розв'язку
	void setmethod(string way);
	//встановити розмір
	void setsize(int size);
	//взяти розмір
	int getsize();
	//створення матриць
	double** createMatrix(int size);
	double* createResult(int size);
	double* createanswer(int size);
	//створення рандомних результатів
	double** RandomMatrix(int size);
	double* RandomResult(int size);
	//виводи
	void vuvid2();
	void vuvid3();
	//детермінант
	double determ(double** Arr, int size);
	//ранг
	int compute_rank(double** A, int NumOfRofs, int NumOfCol);
	
	
private:

	int NumOfEquation;
	string method;
	int count = 0;
					
	
};


//Клас Solution-клас "розв'язків"-
class Solution
{       //ГАУС
	double* gauss(double** Matrix, double* Result, int size);
	//ГАУС З ВИБОРОМ ЕЛЕМЕНТА
	double* gaussM(double** Matrix, double* Result, int size);
	//ДЕТЕРМІНАНТ
	double determ(double** Arr, int size);
	//ЗМІНЮЄМО ПОРЯДОК ВІДПОВІДЕЙ
	void glavelem(int k, double** mas, int n, int* otv);
	//КРАМЕР
	double* Kramer(double** Matrix, double* Result, int size);
public:friend double* SLAR::Menu(Solution Functional);

};