#include"Functions.h"
using namespace System;
using namespace System::Windows::Forms;


SLAR::SLAR(const SLAR& other) {

	this->NumOfEquation = other.NumOfEquation;
	this->Result = new double[NumOfEquation];
	this->Matrix = new double* [NumOfEquation];

	for (int i = 0; i < NumOfEquation; i++) {

		this->Matrix[i] = new double[NumOfEquation];

	}
	for (int i = 0; i < NumOfEquation; i++) {

		this->Result[i] = other.Result[i];

	}
	for (int i = 0; i < NumOfEquation; i++) {
		for (int j = 0; j < NumOfEquation; j++) {

			this->Matrix[i][j] = other.Matrix[i][j];

		}
	}
}
double* SLAR::Menu(Solution Functional)
{

	double* ans;
	if (determ(Matrix, NumOfEquation) != 0) {
		if (compute_rank(Matrix, NumOfEquation, NumOfEquation) == NumOfEquation) {
			if (method == "Kramer") { ans = Functional.Kramer(Matrix, Result, NumOfEquation); }
			else if (method == "gauss") { ans = Functional.gauss(Matrix, Result, NumOfEquation); }
			else if (method == "gaussM") { ans = Functional.gauss(Matrix, Result, NumOfEquation); }
			else { ans = Functional.Kramer(Matrix, Result, NumOfEquation); }
		}
		else { MessageBox::Show("Ранг матриці менщий за розмір матриці", "Помилка!"); }
	}
	else { MessageBox::Show("Детермінант ==0", "Помилка!"); }
	return ans;
}

void SLAR::setmethod(string way)
{
	method = way;
}

void SLAR::setsize(int size)
{
	NumOfEquation = size;
}

int SLAR::getsize()
{
	return NumOfEquation;
}



SLAR::SLAR()
{
}

//ДЕСТРУКТОР
SLAR::~SLAR()
{

	delete[] Matrix;
	delete[] Result;

}

//СТВОРЕННЯ МАТРИЦЬ
double** SLAR::createMatrix(int size)
{
	double** matr = new double* [size];
	for (int i = 0; i < size; i++) {

		matr[i] = new double[size];

	}
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) { matr[i][j] = 0; }

	}
	return matr;
}

double* SLAR::createResult(int size)
{
	double* res = new double[size];

	for (int i = 0; i < size; i++) {

		res[i] = 0;

	}
	return res;
}

double* SLAR::createanswer(int size)
{
	double* answ = new double[size];

	for (int i = 0; i < size; i++) {

		answ[i] = 0;
	}
	return answ;
}


//ЗБЕРЕЖЕННЯ 
void SLAR::vuvid2()
{
	ofstream fout("Result.txt");
	fout << "Початковi дані" << endl;

	for (int i = 0; i < NumOfEquation; i++) {
		fout << "|";
		for (int j = 0; j < NumOfEquation; j++) {
			fout << setw(3) << Matrix[i][j];
		}
		fout << "|=" << Result[i] << endl;
	}

	fout << "Вiдповiдь" << endl;

	for (int i = 0; i < NumOfEquation; i++) {

		fout << answer[i] << " ";

	}
	fout.close();
}
//ЗБЕРЕЖЕННЯ У ДВА ФАЙЛИ
void SLAR::vuvid3() {
	string name;

	name = '0' + count;
	name += +"input.txt";

	ofstream fout(name);
	fout << "Початковi дані" << endl;

	for (int i = 0; i < NumOfEquation; i++) {
		fout << "|";
		for (int j = 0; j < NumOfEquation; j++) {
			fout << setw(3) << Matrix[i][j];
		}
		fout << "|=" << Result[i] << endl;
	}

	fout.close();
	name.clear();

	name = '0' + count;
	name += "output.txt";

	ofstream fout1(name);
	fout1 << "Вiдповiдь" << endl;

	for (int i = 0; i < NumOfEquation; i++) {
		fout1 << answer[i] << " ";
	}
	fout1.close();
	count++;
}




//Випадкове заповнення масиву
double** SLAR::RandomMatrix(int size)
{
	srand(time(NULL));

	double** matr = new double* [size];

	for (int i = 0; i < size; i++) {

		matr[i] = new double[size];

	}
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			matr[i][j] = rand() % 5;
		}
	}
	return matr;
}

double* SLAR::RandomResult(int size)
{
	srand(time(NULL));

	double* res = new double[size];

	for (int i = 0; i < size; i++) {
		res[i] = rand() % 5;
	}
	return res;
}

//Визначник
double SLAR::determ(double** Arr, int size)
{
	int i, j;
	double det = 0;
	double** matr;

	if (size == 1)
	{
		det = Arr[0][0];
	}

	else if (size == 2)
	{
		det = Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0];
	}

	else
	{
		matr = new double* [size - 1];
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size - 1; ++j)
			{
				if (j < i)
					matr[j] = Arr[j];
				else
					matr[j] = Arr[j + 1];
			}
			det += pow((double)-1, (i + j)) * determ(matr, size - 1) * Arr[i][size - 1];
		}
		delete[] matr;
	}
	return det;
}
double Solution::determ(double** Arr, int size)
{
	int i, j;
	double det = 0;
	double** matr;

	if (size == 1)
	{
		det = Arr[0][0];
	}

	else if (size == 2)
	{
		det = Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0];
	}
	else
	{
		matr = new double* [size - 1];
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size - 1; ++j)
			{
				if (j < i)
					matr[j] = Arr[j];
				else
					matr[j] = Arr[j + 1];
			}
			det += pow((double)-1, (i + j)) * determ(matr, size - 1) * Arr[i][size - 1];
		}
		delete[] matr;
	}
	return det;
}


//Ранг
int SLAR::compute_rank(double** Matrix, int NumOfCol, int NumOfRofs) {
	double** A = new double* [NumOfCol];

	for (int i = 0; i < NumOfCol; i++) { A[i] = new double[NumOfCol]; }

	for (int i = 0; i < NumOfCol; i++) {
		for (int j = 0; j < NumOfCol; j++) {

			A[i][j] = Matrix[i][j];

		}
	}
	int rank = 0;

	vector<bool> row_selected(NumOfRofs, false);

	for (int i = 0; i < NumOfCol; ++i) {
		int j;
		for (j = 0; j < NumOfRofs; ++j) {
			if (!row_selected[j] && abs(A[j][i]) > EPS)
				break;
		}

		if (j != NumOfRofs) {
			++rank;
			row_selected[j] = true;
			for (int p = i + 1; p < NumOfCol; ++p)
				A[j][p] /= A[j][i];
			for (int k = 0; k < NumOfRofs; ++k) {
				if (k != j && abs(A[k][i]) > EPS) {
					for (int p = i + 1; p < NumOfCol; ++p)
						A[k][p] -= A[j][p] * A[k][i];
				}
			}
		}
	}
	return rank;
}



//Метод крамера
double* Solution::Kramer(double** Matrix, double* Result, int size)
{
	double* vidpodid = new double[size];
	double** matr = new double* [size];
	double* res = new double[size];

	double determinant = determ(Matrix, size);

	for (int i = 0; i < size; i++) {

		matr[i] = new double[size];
		res[i] = Result[i];

	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			matr[i][j] = Matrix[i][j];

		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matr[j][i] = Result[j];
		}
		vidpodid[i] = determ(matr, size) / determinant;

		for (int z = 0; z < size; z++) {

			matr[z][i] = Matrix[z][i];
		}
	}

	return vidpodid;
}


//Метод гауса з одиничною діагоналлю
double* Solution::gauss(double** Matr, double* Vidp, int size) {
	double* Result = new double[size];
	double** Matrix = new double* [size];

	for (int i = 0; i < size; i++) {

		Matrix[i] = new double[size];
		Result[i] = Vidp[i];

	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Matrix[i][j] = Matr[i][j];
		}
	}
	double* x, max;
	int k, index;
	const double eps = 0.00001;  // точность
	x = new double[size];
	k = 0;

	while (k < size)
	{
		// Поиск строки с максимальным a[i][k]
		max = abs(Matrix[k][k]);
		index = k;
		for (int i = k + 1; i < size; i++)
		{
			if (abs(Matrix[i][k]) > max)
			{
				max = abs(Matrix[i][k]);
				index = i;
			}
		}
		// Перестановка строк
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			//cout << "Решение получить невозможно из-за нулевого столбца ";
			//cout << index << " матрицы A" << endl;
			return 0;
		}
		for (int j = 0; j < size; j++)
		{
			double temp = Matrix[k][j];
			Matrix[k][j] = Matrix[index][j];
			Matrix[index][j] = temp;
		}
		double temp = Result[k];
		Result[k] = Result[index];
		Result[index] = temp;
		// Нормализация уравнений
		for (int i = k; i < size; i++)
		{
			double temp = Matrix[i][k];
			if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
			for (int j = 0; j < size; j++)
				Matrix[i][j] = Matrix[i][j] / temp;
			Result[i] = Result[i] / temp;
			if (i == k)  continue; // уравнение не вычитать само из себя
			for (int j = 0; j < size; j++)
				Matrix[i][j] = Matrix[i][j] - Matrix[k][j];
			Result[i] = Result[i] - Result[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = size - 1; k >= 0; k--)
	{
		x[k] = Result[k];
		for (int i = 0; i < k; i++)
			Result[i] = Result[i] - Matrix[i][k] * x[k];
	}
	return x;
}

double* Solution::gaussM(double** Matrix, double* Result, int size)
{
	double* x = new double[size]; //Корни системы
	double* y = new double[size];
	vector<double> arr;
	int* otv = new int[size]; //Отвечает за порядок корней
	int i, j, k;
	int n = size;
	double** mas = new double* [size];
	for (i = 0; i < size; i++) { mas[i] = new double[size + 1]; }
	for (i = 0; i < size; i++) { for (j = 0; j < size + 1; j++) { if (j < size) { mas[i][j] = Matrix[i][j]; } else { mas[i][j] = Result[i]; } } }
	//Сначала все корни по порядку
	for (i = 0; i < n + 1; i++)
	{
		otv[i] = i;
	}
	//Прямой ход метода Гаусса
	for (k = 0; k < n; k++)
	{ //На какой позиции должен стоять главный элемент
		glavelem(k, mas, n, otv); //Установка главного элемента
		for (j = n; j >= k; j--)
			mas[k][j] /= mas[k][k];
		for (i = k + 1; i < n; i++)
			for (j = n; j >= k; j--)
				mas[i][j] -= mas[k][j] * mas[i][k];
	}
	//Обратный ход
	for (i = 0; i < n; i++)
		x[i] = mas[i][n];
	for (i = n - 2; i >= 0; i--)
		for (j = i + 1; j < n; j++)
			x[i] -= x[j] * mas[i][j];
	//Вывод результата
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i == otv[j])
			{ //Расставляем корни по порядку
				arr.push_back(x[j]);
				//printf("%f\n", x[j]);
				break;
			}
	for (i = 0; i < size; i++) { y[i] = arr[i]; }
	return y;
}

void Solution::glavelem(int k, double** mas, int n, int* otv)
{
	int i, j, i_max = k, j_max = k;
	double temp;
	//Ищем максимальный по модулю элемент
	for (i = k; i < n; i++)
		for (j = k; j < n; j++)
			if (fabs(mas[i_max][j_max]) < fabs(mas[i][j]))
			{
				i_max = i;
				j_max = j;
			}
	//Переставляем строки
	for (j = k; j < n + 1; j++)
	{
		temp = mas[k][j];
		mas[k][j] = mas[i_max][j];
		mas[i_max][j] = temp;
	}
	//Переставляем столбцы
	for (i = 0; i < n; i++)
	{
		temp = mas[i][k];
		mas[i][k] = mas[i][j_max];
		mas[i][j_max] = temp;
	}
	//Учитываем изменение порядка корней
	i = otv[k];
	otv[k] = otv[j_max];
	otv[j_max] = i;
}



string& Convert_String_to_string(System::String^ s)
{
	std::string os;
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ Convert_string_to_String(string& os)
{
	System::String^ s = gcnew String(os.c_str());
	return s;
}

string& Convert_String_to_string(System::String^ s, std::string os)
{
	using namespace Runtime::InteropServices;
	char* chars =
		(char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}

String^ Convert_string_to_String(string& os, String^ s)
{
	s = gcnew System::String(os.c_str());
	return s;
}
