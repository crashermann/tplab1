#include "romans.h"
#include <iostream>

using namespace std;
/*��� ������ ����� ����������:
������, �����, ��� ��������, ��� �������.*/
void romans::data()
{
	cout << "���: " << kindofbird << endl;
	cout << "���� �����: " << color << endl;
	cout << "������������: " << typeoffood << endl;
	cout << "������� ���������: " << habitat << endl;
	
}

void romans::set()
{
	while (1)
	{
		system("cls");
		cout << "������� ������ �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> kindofbird;
		if (exception(kindofbird) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> color;
		if (exception(color) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ��� ������� �����(������ ��������, ������� ������ ������������� _ ): ";
		cin >> typeoffood;
		if (exception(typeoffood) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "������� ����� ��������(������ ��������, ������� ������ ������������� _ ): ";
		cin >> habitat;
		if (exception(habitat) == -2)
			continue;
		break;
	}
}

void romans::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 4; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			kindofbird = line;
			break;
		}
		case 1:
		{
			color = line;
			break;
		}
		
		case 2:
		{
			typeoffood = line;
			break;
		}
		case 3:
		{
			habitat = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void romans::save(ofstream& out)
{
	out << 2 << endl;
	out << kindofbird << endl;
	out << color << endl;
	out << typeoffood << endl;
	out << habitat << endl;
}

romans::romans()
{
	kindofbird = "��� ����������";
	color = "��� ����������";
	typeoffood = "��� ����������";
	habitat = "��� ����������";

}

romans::romans(string k, string �, string t, string h)
{
	kindofbird = k;
	color = �;
	typeoffood = t;
	habitat = h;
}

romans::romans(const romans& romans) :
	kindofbird(romans.kindofbird), color(romans.color), typeoffood(romans.typeoffood), habitat(romans.habitat) {}

romans::~romans() {}

int romans::exception(string line)
{
	try
	{
		if (line.empty())
			throw -2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "������ ���� �� ����� ���� ������!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "���-�� ����� �� ���!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}