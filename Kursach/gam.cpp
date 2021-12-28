#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
int* path;
void create(int size, int** mat) {
	int i, j, x;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		mat[i] = (int*)malloc(size * sizeof(int));
		for (j = 0; j < size; j++) {
			mat[i][j] = rand() % 100;
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (mat[i][j] < 70) mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}
}
void createneo(int size, int** mat) {
	int i, j, x=0, n=0;
	srand(time(NULL));
	for (i = 0; i < size; i++) {
		mat[i] = (int*)malloc(size * sizeof(int));
		for (j = 0; j < size; j++) {
			mat[i][j] = rand()%100;
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (mat[i][j] < 70) mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			mat[i][j] = mat[j][i];
			if (i == j) mat[j][i] = 0;
		}
	}
}
void printmatrix(int size, int** mat) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}
void printmass(int size, int* mas) {
	int i;
	for (i = 0; i < size; i++)
		cout << mas[i]+1 << " ";
	cout << mas[0]+1;
	cout << endl;
}
void visitor(int size, int* mas) {
	int i;
	for (i = 0; i < size; i++) {
			mas[i] = -1;
	}
}
int gamilton(int size, int pos, int** mat, int* mas, int count) {
	int i;
	int success = 0;
	for (i = 0; i < size && !success; i++) 
	{
		if (mat[i][path[count - 1]] || mat[path[count - 1]][i])
		{
			if (count == size && i == pos)
			{
				success = 1;
				continue;
			}
			else if (mas[i] == -1)
			{
				mas[i] = count;
				path[count] = i;
				success = gamilton(size, pos, mat, mas, count + 1);
				if (!success) mas[i] = -1;
			}
			else continue;
		}
	}
	return success;
}
int gamilton_2(int size, int pos, int** mat, int* mas, int count) {
	int i;
	int success = 0;
	for (i = 0; i < size && !success; i++)
	{
		if (mat[path[count - 1]][i])
		{
			if (count == size)
			{
				success = 1;
				continue;
			}
			else if (mas[i] == -1)
			{
				mas[i] = count;
				path[count] = i;
				success = gamilton_2(size, pos, mat, mas, count + 1);
				if (!success) mas[i] = -1;
			}
			else continue;
		}
	}
	return success;
}
void orient(int size) {
	int pos, count = 1;
	int* vis;
	int** fmatrix;
	fmatrix = (int**)malloc(size * sizeof(int));
	path = (int*)malloc(size * sizeof(int));
	vis = (int*)malloc(size * sizeof(int));
	create(size, fmatrix);
	printmatrix(size, fmatrix);
	cout << "Гамильтонов цикл для каждой вершины" << endl;
	for (pos = 0; pos < size; pos++)
	{
		visitor(size, vis);
		path[0] = pos;
		vis[pos] = pos;
		if (gamilton_2(size, pos, fmatrix, vis, count))
			printmass(size, path);
		else
			cout << "Для точки: " << pos + 1 << " нет цикла" << endl;
	}
}
void neo(int size) {
	int pos, count = 1;
	int* vis;
	int** fmatrix;
	fmatrix = (int**)malloc(size * sizeof(int));
	path = (int*)malloc(size * sizeof(int));
	vis = (int*)malloc(size * sizeof(int));
	createneo(size, fmatrix);
	printmatrix(size, fmatrix);			
	cout << "Гамильтонов цикл для каждой вершины" << endl;
	for (pos = 0; pos < size; pos++)
	{
		visitor(size, vis);
		path[0] = pos;
		vis[pos] = pos;
		if (gamilton(size, pos, fmatrix, vis, count))
			printmass(size, path);
		else
			cout << "Для точки: " <<pos+1 <<" нет цикла" << endl;
	}
}
void fromfile_1(int size, int** mat)
{
	int i, j;
	ifstream fin;
	fin.open("ori.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка при открытии файла.\n";
		system("pause>>void");
	}
	else
	{
		string str;
		int iin = 0;
		for (i = 0; i < size; i++)
		{
			mat[i] = (int*)malloc(size * sizeof(int));
			for (j = 0; j < size; j++)
			{
				fin >> str;
				for (int m = 0; m < str.length(); m++)
				{
					if (str.at(m) == '1' || str.at(m) == '0')
					{
						iin = stoi(str);
						mat[i][j] = iin;
					}
					else
					{
						cout << "В файл введены некорректные данные.\n";
						system("pause>>void");
					}
				}
			}
		}
		fin.close();
	}

}
void fromfile_2(int size, int** mat)
{
	int i, j;
	ifstream fin;
	fin.open("nem.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка при открытии файла.\n";
		system("pause>>void");
	}
	else
	{
		string str;
		int iin = 0;
		for (i = 0; i < size; i++)
		{
			mat[i] = (int*)malloc(size * sizeof(int));
			for (j = 0; j < size; j++)
			{
				fin >> str;
				for (int m = 0; m < str.length(); m++)
				{
					if (str.at(m) == '1' || str.at(m) == '0')
					{
						iin = stoi(str);
						mat[i][j] = iin;
					}
					else
					{
						cout << "В файл введены некорректные данные.\n";
						system("pause>>void");
					}
				}
			}
		}
		fin.close();
	}
}
void neo_2(int size) {
	int i, pos, count = 1;
	int* vis;
	int** fmatrix;
	ofstream fout;
	fout.open("output.txt");
	fmatrix = (int**)malloc(size * sizeof(int));
	path = (int*)malloc(size * sizeof(int));
	vis = (int*)malloc(size * sizeof(int));
	fromfile_2(size, fmatrix);
	printmatrix(size, fmatrix);
	cout << "Гамильтонов цикл для каждой вершины" << endl;
	for (pos = 0; pos < size; pos++)
	{
		visitor(size, vis);
		path[0] = pos;
		vis[pos] = pos;
		if (gamilton(size, pos, fmatrix, vis, count))
		{
			printmass(size, path);
			for (i = 0; i < size; i++) {
				fout << path[i]+1;
			}
			fout << path[0]+1;
			fout << endl;
		}
		else
			cout << "Для точки: " << pos + 1 << " нет цикла" << endl;
		
	}
	
	fout.close();
}
void orient_2(int size) {
	int i, pos, count = 1;
	int* vis;
	int** fmatrix;
	ofstream fout;
	fout.open("output.txt");
	fmatrix = (int**)malloc(size * sizeof(int));
	path = (int*)malloc(size * sizeof(int));
	vis = (int*)malloc(size * sizeof(int));
	fromfile_1(size, fmatrix);
	printmatrix(size, fmatrix);
	cout << "Гамильтонов цикл для каждой вершины" << endl;
	for (pos = 0; pos < size; pos++)
	{
		visitor(size, vis);
		path[0] = pos;
		vis[pos] = pos;
		if (gamilton_2(size, pos, fmatrix, vis, count))
		{
			printmass(size, path);
			for (i = 0; i < size; i++) {
				fout << path[i] + 1;
			}
			fout << path[0]+1;
			fout << endl;
		}
		else
			cout << "Для точки: " << pos + 1 << " нет цикла" << endl;

	}
	fout.close();
}