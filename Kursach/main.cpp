#include <iostream>
using namespace std;
void orient(int size);
void neo(int size);
void orient_2(int size);
void neo_2(int size);
int main()
{
	setlocale(0, "");
	int x, size;
	cout << "Введите размер для графа:";
	cin >> size;
	cout << "Выберите тип графа:\n1-Ориентированный\n2-Неориентированный\n";
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "Выберите откуда взять граф:\n1-Из файла\n2-Создать случайный граф"<<endl;
		cin >> x;
		if (x == 1)
			orient_2(size);
		else
			orient(size);
		break;
	case 2:
		cout << "Выберите откуда взять граф:\n1-Из файла\n2-Создать случайный граф" << endl;
		cin >> x;
		if (x == 1)
			neo_2(size);
		else
			neo(size);
		break;
	}

	return 0;
}