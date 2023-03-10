#include<iostream>
#include<Windows.h>

using namespace std;

int string_length(const char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrom(const char str[]);
bool is_int_number(const char str[]);
bool is_bin_number(const char str[]);
bool is_hex_number(const char str[]);


void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };


	//char str[] = "Hello";
	//cout << str << endl;
	//cout << sizeof(str) << endl;

	/*cout << (int)'a' << endl;
	cout << (int)'A' << endl;
	cout << 'A' - 'a' << endl;*/

	const int n = 256;
	char str[n];
	////char str[n] = "Хорошо     живет       на      свете     Винни      Пух";
	//char str[n] = "Аргентина манит негра";
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	cin >> str;
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << str << endl;
	//cout << "Вы ввели строку длинной " << string_length(str) << " символов\n";
	//cout << "Длина строки " << strlen(str) << " символов\n";
	to_upper(str);
	to_lower(str);
	shrink(str);
	cout << str << endl;

	//cout << "Строка " << (is_palindrom(str) ? "  " : " НЕ ") << "палиндром" << endl;

	bool is_int_number(const char str[]);
	cout << "Строка" << (is_int_number(str) ? " " : " НЕ ") << "десятичное число" << endl;

	bool is_bin_number(const char str[]);
	cout << "Строка" << (is_bin_number(str) ? " " : " НЕ ") << "двоичное число" << endl;

	bool is_hex_number(const char str[]);
	cout << "Строка" << (is_hex_number(str) ? " " : " НЕ ") << "шестнадцатиричное число" << endl;
}

int string_length(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		//if (str[i] >= 'a' && str[i] <= 'я')str[i] -= ' ';
		str[i] = toupper(str[i]);
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)str[i] = tolower(str[i]);
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++) str[j] = str[j + 1];
		}
	}
}

bool is_palindrom(const char str[])
{
	char* buffer = new char[strlen(str) + 1] {};
	for (int i = 0; i < strlen(str); i++)buffer[i] = str[i];
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	int n = strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])return buffer;
	}
	return true;
}

bool is_int_number(const char str[])
{
	int n = strlen(str);

	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || str[i]>'9')
			return false;
	}

	return true;

}

bool is_bin_number(const char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '1' && str[i] != '0')
		{
			return false;
		}
	}
	return true;
}

bool is_hex_number(const char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i];
		if (
			(str[i] < '0' || str[i] > '9') &&
			(str[i] < 'A' || str[i] > 'F') &&
			(str[i] < 'a' || str[i] > 'f')
			)
		{
			return false;
		}
	}
	return true;
}





