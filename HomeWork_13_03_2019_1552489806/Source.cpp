#include<iostream>
#include<fstream>			// библиотека работы с файлами
#include<Windows.h>
#include<locale.h>




// VladimirOrlovA /HomeWork_13_03_2019_1552489806

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

	ifstream fin("Text.txt");
	ofstream fout("OutTask1.txt");

	int count0 = 0;	// кол-во строчек
	int count1 = 0;	// все символы кроме букв
	int count2 = 0;	// все гласные буквы
	int count3 = 0;	// все цифры
	int count4 = 0;	// все символы
	int count5 = 0;	// все согласные буквы

	char str[50][150];
	
	while (!fin.eof())
	{
		fin.getline(str[count0], 150);
		count0++;
	}

	

	for (int i = 0; i < count0; i++)
	{
		for (int j = 0; j < strlen(str[i]); j++)
		{
			// все символы кроме букв

			if (str[i][j] >= ' ' && str[i][j]<'A' || str[i][j]>'Z' && str[i][j]<'a' || str[i][j]>'z')
				count1++;
			
			//  все гласные буквы латинского алфавита Aa - Ee - Ii - Oo - Uu - Yy

			else if (str[i][j] == 'A' || str[i][j] == 'E' || str[i][j] == 'I' || str[i][j] == 'O' || str[i][j] == 'U' || str[i][j] == 'Y' ||
				str[i][j] == 'a' || str[i][j] == 'e' || str[i][j] == 'i' || str[i][j] == 'o' || str[i][j] == 'u' || str[i][j] == 'y')
				count2++;
			
			// все цифры

			if (str[i][j] >= '0' && str[i][j] <= '9')
				count3++;
			
			count4++;
		}
	}

	count5 = count4 - count2 - count1;

	fin.close();
	fin.open("Text.txt");

	
	fout << "Статистика по файлу Text.txt :\n" << endl;
	fout << "количество символов		\t-> " << count4 << endl;
	fout << "количество строк		\t-> " << count0 << endl;
	fout << "количество гласных букв	\t-> " << count2 << endl;
	fout << "количество согласных букв \t-> " << count5 << endl;
	fout << "количество цифр.		\t-> " << count3 << endl;

	cout << "Статистика по файлу Text.txt записана в файле OutTask1.txt" << endl;
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

	ifstream fin("Task2dataSource.txt");
	ofstream fout("OutTask2encryptedText.txt");

	
	char str[50][150];
	int count(0);
	int k;

	cout << "Шифруем текст в файле Task2dataSource.txt \n\nВведите ключ шифрования -> ";
	cin >> k;
	
	while (!fin.eof())
	{
		fin.getline(str[count], 150); 
		count++; 
	}
	
	fout << "Оригинальный текст:\n\n";
	
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < strlen(str[i]); j++)
		{
			fout << char(str[i][j]);
		}
		fout << endl;
	}
	
	fout << "\n\nЗашифрованный текст:\n\n";

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < strlen(str[i]); j++)
		{
			if (str[i][j] == ' ')				// исключаю пробелы в шифоровании, чтобы исключить легкий взлом шифра путем поиска пробелов и тем самым побора ключа
				fout << str[i][j];
			else
				fout << char(str[i][j] + k);
		}
		fout << endl;
	}

	cout << "\nРезультат шифрования в файле OutTask2encryptedText.txt";
	
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