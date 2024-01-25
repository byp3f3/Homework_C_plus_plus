#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	int a, b, d;
	double res;
	res = 1;
	while(true){
		cout << "Выберите действие:\n1.Сложение\n2.Вычитание\n3.Умножение\n4.Деление\n5.Возведение в степень\n6.Нахождение квадратного корня\n7.Нахождение 1 процента от числа\n8.Найти факториал числа\n9.Выход" << endl;
		cin >> d;
		
			res = 1;
			if (d > 0 && d < 5) {
				cout << "Введите первое число: ";
				cin >> a;
				cout << "Введите второе число: ";
				cin >> b;
				if (d == 1)
					cout << "Сумма равна: " << a + b << endl;
				else if (d == 2)
					cout << "Разность равна: " << a - b << endl;
				else if (d == 3)
					cout << "Произведение равно: " << a * b << endl;
				else if (d == 4)
				{
					if (b == 0)
						cout << "На ноль делить нельзя!!!";
					else
						cout << "Частное равно: " << a / b << endl;
				}
			}
			else if (d == 5) {
				cout << "Введите число: ";
				cin >> a;
				cout << "Введите степень: ";
				cin >> b;
				for (int i = 1; i <= b; i++) {
					res *= a;
				}
				cout << "Результат: " << res << endl;
			}
			else if (d > 5 && d < 9) {
				cout << "Введите число: ";
				cin >> a;
				if (d == 6) {
					if (a > 0)
						cout << "Результат: " << sqrt(a) << endl;
					else cout << "Введите положительное число" << endl;
				}
				else if (d == 7) {
					cout << "Результат: " << a /100 << endl;
				}
				else if (d == 8) {
					long int f = 1;
					if (a > 0){
						for (int i = 1; i <= a; i++) {
							f *= i;
						}
						cout << "Результат: " << f << endl;
					}
					else cout << "Введите положительное число" << endl;
				}
			}
			else if (d == 9) break;
			else cout << "Выбранной команды не существует" << endl;
			
	}
}