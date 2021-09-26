#include <iostream>
#include <iomanip>

#include "omp.h"
const int DIM = 10000;
const int THREADS = 4;
using namespace std;

void transpose(int n, int m)
{
	srand(81589);

	float **matrix = new float *[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new float[m];

	for (int i = 0; i < n; i++)

	for (int j = 0; j < m; j++)
	{
		matrix[i][j] = rand();
	}

	int i, j, t;
	double dt, timein, timeout;

	omp_set_num_threads(THREADS);
	timein = omp_get_wtime();

#pragma omp parallel for private (j, i, t)

	for (i = 0; i < DIM; ++i)
	{
		for (j = i; j < DIM; ++j)
		{
			t = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = t;
		}
	}
	timeout = omp_get_wtime();
	dt = timeout - timein;
	cout << "Время: " << dt << " секунд" << endl;
	delete[] matrix;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	transpose(DIM,DIM);
	system("pause");
	return 0;
}