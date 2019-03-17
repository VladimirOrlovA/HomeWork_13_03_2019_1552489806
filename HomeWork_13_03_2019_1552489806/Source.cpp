#include<iostream>
#include<fstream>			// библиотека работы с файлами
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_13_03_2019_15524898068

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


using namespace std;

void Task1()
{
	/*1.	Дан текстовый файл. Необходимо создать новый файл и записать в него следующую статистику по исходному файлу:
	количество символов
	количество строк
	количество гласных букв
	количество согласных букв
	количество цифр.
*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	ifstream fin("Source.cpp");
	ofstream fout("OutTask1.txt");

	char str[50][300];					// объявляем массив из 50 строк с 300 символами
	int count = 0;						// объявляем переменную для счетчика строк
	int max = 0;
	int tmp;


	while (!fin.eof())					// пока не достигнем конца файла --- eof -> end of file
	{
		fin.getline(str[count], 300);	// записывем считанные из файла строки в массив
		count++;

	}

	for (int i = 0; i != count; i++)	// ищем самую длинную строку
	{
		tmp = strlen(str[i]);

		if (tmp > max)
			max = tmp;

	}

	cout << "Task 1 -Длина самой длинной строки в файле DataSource1.txt -> " << max << " знаков" << endl;
	fout << "\nTask 1 - Длина самой длинной строки в файле DataSource1.txt -> " << max << " знаков" << endl;
}


void Task2()
{
	/* 2.	Шифр Цезаря — один из древнейших шифров. При шифровании каждый символ заменяется другим, отстоящим от него 
			в алфавите на фиксированное число позиций.
Пример
Шифрование с использованием ключа : 3
Оригинальный текст: Съешь же ещё этих мягких французских булок, да выпей чаю.
Шифрованный текст: Фэзыя йз зьи ахлш пвёнлш чугрщцкфнлш дцосн, жг еютзм ъгб.
Дан текстовый файл. Зашифровать его, используя шифр Цезаря. Результат записать в другой файл.
*/

	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);



}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_27_02_2019_1551281479 \n\n";
	SetConsoleTextAttribute(hConsole, 7);

	/*SetConsoleCP(1251);
	SetConsoleOutputCP(1251);*/

	setlocale(LC_ALL, "");

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;
		
		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO press any keys => ";
		cin >> flag;

	} while (flag == 'y');
}