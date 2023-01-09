#include<iostream>
#include<Windows.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	

	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	const int n = 20;
	char str[n] = {};
	cout << "¬ведите строку: "; 
	SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	cout << str << endl;
}