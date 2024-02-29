#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu;
	cout << "Выберите команду: \n1.Слово выводится задом наперед.\n2.Вывод слова без гласных.\n3.Вывод слова без согласных.\n4.Рандомно выводить буквы заданного слова." << endl;
	cin >> menu;
	cout << "Введите слово: " << endl;
	string word = "";
	cin >> word;
	string a = "aeiouyAEIOUY";
	string b = "qwrtpsdfghjklzxcvbnmQWRTPSDFGHJKLZXCVBNM";
	switch (menu)
	{
	case 1:
		reverse(word.begin(), word.end());
		cout << word << endl;
		return 0;
	case 2:
		for (int i = 0; i < word.length(); i++)
		{
			for (int j = 0; j < a.length(); j++) {
				if (word[i] == a[j]) {
					word.erase(word.begin() + i);
				}
			}
		}
		cout << word << endl;
		return 0;
	case 3:
		for (int i = 0; i < word.length(); i++)
		{
			for (int j = 0; j < b.length(); j++) {
				if (word[i] == b[j]) {
					word.erase(word.begin() + i);
				}
			}
		}
		cout << word << endl;
		return 0;
			
	case 4:
		random_shuffle(word.begin(), word.end());
		cout << word << endl;
		return 0;
	default:
		cout << "Такой команды не существует";
		return 0;
	}
}
