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
	cout << "������� ������ ��� �����:";
	cin >> size;
	cout << "�������� ��� �����:\n1-���������������\n2-�����������������\n";
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "�������� ������ ����� ����:\n1-�� �����\n2-������� ��������� ����"<<endl;
		cin >> x;
		if (x == 1)
			orient_2(size);
		else
			orient(size);
		break;
	case 2:
		cout << "�������� ������ ����� ����:\n1-�� �����\n2-������� ��������� ����" << endl;
		cin >> x;
		if (x == 1)
			neo_2(size);
		else
			neo(size);
		break;
	}

	return 0;
}