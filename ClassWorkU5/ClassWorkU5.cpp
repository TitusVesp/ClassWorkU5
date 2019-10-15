// ClassWorkU5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void InitMatrix(int** matrix, int m, int n)
{
	srand(time(NULL));

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() % 100 - 30;
}


void main()
{
	setlocale(LC_ALL, "ukr");
	cout << "M and N - rows and colums!" << endl;
	int n = 0, m = 0, k = 0, max = 0, g = 0;
	cout << "Input M: " << endl;
	cin >> m;
	cout << "Input N: " << endl;
	cin >> n;
	if (!(1 <= n && 1 <= m)) { cout << "Incorrect input!" << endl; return; }

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++)
		matrix[i] = new int[n];
	InitMatrix(matrix, m, n);

	int* chark = new int[n];
	for (int j = 0; j < n; j++) chark[j] = 0;

	cout << endl << "Until: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) max = matrix[i][j];
			cout << matrix[i][j] << " ";
			
			if (matrix[i][j] < 0 && abs(matrix[i][j]) % 2 != 0) 
				chark[j] += abs(matrix[i][j]);

			if (max < abs(matrix[i][j])) max = abs(matrix[i][j]);
		}
		cout << endl;
	}

	max += 100;
	int** matrix2 = new int* [m];
	for (int i = 0; i < m; i++)
		matrix2[i] = new int[n];

	for (int temp = 0; temp < n; temp++)
	{
		int num_max = 0;
		for (int i = 0; i < n; i++)
		{
			if (chark[num_max] < chark[i]) num_max = i;
		}

		for (int i = 0; i < m; i++)
		{
			matrix2[i][g] = matrix[i][num_max];
		}
		g++;
		chark[num_max] = max * -1;
	}
	

	int* sumEl = new int[n];
	for (int j = 0; j < n; j++) sumEl[j] = 0;

	for (int i = 0, j = 0; i < n; i++)
	{
		bool flag = true;
		for (int k = 0; k < m; k++)
		{
			sumEl[j] += matrix[k][j];
			if (matrix[k][j] < 0) flag = false;
		}
		if (flag) sumEl[j] = 0;
		j++;
	}

	cout << "After: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix2[i][j] << " ";
		cout << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Sum of colum " << i + 1 << " = " << sumEl[i] << endl;
	}

	for (int i = 0; i < m; i++)
		delete[]matrix[i];
	delete[] matrix;
	for (int i = 0; i < m; i++)
		delete[]matrix2[i];
	delete[] matrix2;
	delete[] chark;
	delete[] sumEl;
	cout << endl << endl;
}

