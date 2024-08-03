#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file;
	file.open("D:\\INPUT.txt");
	string a;
	int count = 0;
	while (!file.eof())
	{
		file >> a;
		count++;
	}
	file.clear();
	file.seekg(0);
	string* s = new string[count];
	for (int i = 0; i < count; i++)
	{
		file >> s[i];
	}
	cout << "Файл до сортировки: \n";
	for (int i = 0; i < count; i++)
	{
		cout << s[i] << " ";
		cout << '\n';
	}
	cout << "\n";
	file.close();
	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count; j++)
		{
			if (s[i] > s[j])
			{
				swap(s[i], s[j]);
			}
		}
	}
	file.open("D:\\OUTPUT.txt");
	for (int i = 0; i < count; i++)
	{
		file << s[i];
	}
	cout << "Файл после сортировки: \n";
	for (int i = 0; i < count; i++)
	{
		cout << s[i] << " ";
		cout << '\n';
	}
	delete[] s;
	file.close();
	return 0;
}
