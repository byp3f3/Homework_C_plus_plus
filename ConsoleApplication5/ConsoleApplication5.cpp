#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	setlocale(0, "");
	
	float sum;
	const int rows = 3, columns = 5;
	float num[rows][columns];

	for (int i = 0; i < rows; i++) {
		cout << "Введите пять элементов строки: " << endl;
		for (int j = 0; j < columns; j++) {
			cin >> num[i][j];
		}
	}
	for (int i = 0; i < rows; i++) {
		sum = 0;
		for (int j = 0; j < columns; j++) {
			sum += num[i][j];
		}
		cout <<"Среднее значение строки "<< i+1 <<": " << sum / 5 << endl;
	}
	return 0;

}