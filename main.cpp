#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
//Прототипи функцій//
int inp_num(const char*);
int inp_element(const char*, const char*, const char*, int, int);
void generate_array(int**&, int&, int&, const char*, const char*);
void output_array(int**, int, int, const char*);
void findminmax(int**, int, int, int&, int&);
void changerows(int**, int, int, int);
void cleaner(int**&, int);
int main()
{
	//Ініціалізація масиву
	int** arr;
	int n, m;
	int minrow = 0;
	int maxrow = 0;
	generate_array(arr, n, m, "n", "m");
	output_array(arr, n, m, "Your array:");
	findminmax(arr, n, m, minrow, maxrow);
	changerows(arr, minrow, maxrow, m);
	output_array(arr, n, m, "Modified array:");
	cleaner(arr, m);
	return 0;
}
//Фукнкція вводу числа
int inp_num(const char* msg)
{
	char num[10];
	cout << "\ninput " << msg<< "=";
	fgets(num, 10, stdin);
	return atoi(num);
}
//Функція генерування елементів заданого масиву//
void generate_array(int**& arr, int& size1, int& size2, const char* msg1, const char* msg2)
{
	do
	{
		cout << msg1 << " > " << 0;
		size1 = inp_num(msg1);
	} while (size1 <= 0);
	do
	{
		cout << msg2 << " > " << 0;
		size2 = inp_num(msg2);
	} while (size2 <= 0);
	arr = new int* [size1];
	for (int i = 0; i < size1; i++)
	{
		*(arr+i) = new int[size2];
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
				*(*(arr+i)+j) = inp_element("[", "][", "]=", i, j);
		}
	}
	cout << endl;
}
//Функція виводу масиву//
void output_array(int** arr, int size1, int size2, const char* msg)
{
	cout << msg << endl;
	if (!size1 || !size2)
	{
		cout << "array is empty\n";
		return;
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			cout << setw(3) << *(*(arr+i)+j);
		}
		cout << endl;
	}
	cout << endl;
}
//Функція для вводу елемента масиву//
int inp_element(const char* msg1, const char* msg2, const char* msg3, int i, int j)
{
	char num[10];
	cout << "\ninput " << msg1 << i << msg2 << j << msg3;
	fgets(num, 10, stdin);
	return atoi(num);
}
//Функція знаходження рядка з мінімальним та  рядка з максимальним елементом//
void findminmax(int** arr, int n, int m, int& mini, int& maxi)
{
	int maxval, minval;
	maxval = **arr;
	minval = **arr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(arr + i) + j) > maxval)
			{
				maxval = *(*(arr + i) + j);
				maxi = i;
			}
			else
				if (*(*(arr + i) + j) < minval)
				{
					minval = *(*(arr + i) + j);
					mini = i;
				}
		}
	}
}
//Функція заміни рядка з мінімальним елементом та рядка з максимальним елементом місцями//
void changerows(int** arr, int minrow, int maxrow, int row)
{
	for (int j = 0; j < row; j++)
	{
		int tmp = *(*(arr + maxrow) + j);
		*(*(arr + maxrow) + j) = *(*(arr + minrow) + j);
		*(*(arr + minrow) + j) = tmp;
	}
}
void cleaner(int**& arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		delete[] *(arr+i);
	}
	delete[] arr;
}
