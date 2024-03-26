#include <iostream>
#include <string>
#include <Windows.h>
#pragma execution_character_set("utf-8")

using namespace std;


class BankAccount{
	friend  bool transfer();
private:
	int accountNumber;
	double balance;
	double interestRate;
public:
	BankAccount(int acNum, double balance) {
		this->accountNumber = acNum;
		this->balance = balance;
		this->interestRate = 0;
	}

	double deposit(double amount){
		if (amount > 0) {
			balance += amount;
			return balance;
		}
		else cout << "Введено неверное количество" << endl;
	}

	double withdraw(double amount) {
		if (amount > 0 && amount < balance) {
			balance -= amount;
			return balance;
		}
		else cout << "Введено неверное количество" << endl;
	}

	double getBalance() {
		return balance;
	}

	double getInterest() {
		return balance * interestRate * (1.0/ 12);
	}

	double setInterestRate() {
		double intRate;
		cout << "Введите новую процентную ставку: " << endl;
		cin >> intRate;
		if (intRate > 0) {
			interestRate = intRate;
			return interestRate;
		}
		else cout << "Введено неверное число" << endl;
	}

	void getAccountNumber() {
		cout <<"Номер Вашего счета: "<< accountNumber << endl;
	}
};


bool transfer(BankAccount &from, BankAccount &to, double amount) {
	if (from.getBalance() >= amount) {
		cout << "Баланс отправителя: " << from.getBalance() << endl;
		cout << "Баланс получателя: " << to.getBalance() << endl;
		cout << "Сумма перевода: " << amount << endl;
		from.withdraw(amount);
		to.deposit(amount);
		return true;
	}
	else {
		cout << "Введено слишком большое число" << endl;
		return false;
	}
}

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	BankAccount acc1(1, 567.33);
	BankAccount acc2(23, 10000);
	cout << "Ваш баланс(1 аккаунт): " << acc1.getBalance() << endl;
	cout << "Ваш баланс(2 аккаунт): " << acc2.getBalance() << endl;
	cout << "Текущий баланс(1 аккаунт +30): " << acc1.deposit(30) << endl;
	cout << "Текущий баланс(2 аккаунт -3.7): " << acc2.withdraw(3.7) << endl;
	cout << "Проценты(1 аккаунт): " << acc1.getInterest() << endl;
	cout << "Проценты(2 аккаунт): " << acc2.getInterest() << endl;
	cout << "Процентная ставка обновлена(1 аккаунт): " << acc1.setInterestRate() << "%" << endl;
	cout << "Процентная ставка обновлена(2 аккаунт): " << acc2.setInterestRate() << "%" << endl;
	acc1.getAccountNumber();
	acc2.getAccountNumber();
	cout << transfer(acc2, acc1, 33.33);
}
