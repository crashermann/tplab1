#include "romans.h"
#include <iostream>

using namespace std;
/*Для каждой птицы определено:
порода, окрас, чем питается, где обитает.*/
void romans::data()
{
	cout << "ФИО: " << kindofbird << endl;
	cout << "Годы жизни: " << color << endl;
	cout << "Произведения: " << typeoffood << endl;
	cout << "Кратная биография: " << habitat << endl;
	
}

void romans::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите породу птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> kindofbird;
		if (exception(kindofbird) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите окрас птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> color;
		if (exception(color) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип питания птицы(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
		cin >> typeoffood;
		if (exception(typeoffood) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите место обитания(Вместо пробелов, вводите нижнее подчеркивание _ ): ";
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
	kindofbird = "Нет информации";
	color = "Нет информации";
	typeoffood = "Нет информации";
	habitat = "Нет информации";

}

romans::romans(string k, string с, string t, string h)
{
	kindofbird = k;
	color = с;
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
			cout << "Данное поле не может быть пустым!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "Что-то пошло не так!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}