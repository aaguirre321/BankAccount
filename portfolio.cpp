/*
Arely Aguirre
UID: 605505030
Disc:1C
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Portfolio
{
	public:
		Portfolio(double amount, string account);
		void deposit(double amount, string account);
		void withdraw(double amount, string account);
		void transfer(double amount, string account);
		void print_balances();
	private:
		double savings;
		double checking;
		double* start_account = nullptr;
		double* end_account = nullptr;
		void set_accounts(string account);
		int x1, x2, y1, y2;
		 
};

Portfolio::Portfolio(double amount,string account)
{
	savings = 10000;
	checking = 2500;
	//savings and checkings are initialized with user input
	x1 = 0;
	x2 = 0;
	y1 =  0;
	y2 = 0;
}

void Portfolio::set_accounts(string account)
{
	/*in cases of deposit or withdraw, start_account points to the 
	account that will be manipulated and end_account points to account that
	will be untouched*/
	/*in case of a transfer, start_account points to account that will
	be decreased and end_account points to account that with be increased*/
	if (account == "S")
	{
		start_account = &savings;
		end_account = &checking;
	}
	else
	{
		start_account = &checking;
		end_account = &savings;
	}
}

void Portfolio::deposit(double amount, string account)
{
	set_accounts(account);
	*start_account = *start_account + amount;
	//adds user given amount to selected account
}

void Portfolio:: withdraw(double amount, string account)
{
	set_accounts(account);
	*start_account = *start_account - amount;
	// subtracts user given amount to selected account
}

void Portfolio::transfer(double amount, string account)
{
	set_accounts(account);
	*start_account = *start_account - amount;
	*end_account = *end_account + amount;
	/* subtracts user given ammount from selected account
	and adds it to the other*/
}

void Portfolio::print_balances()
{
	x1 = checking;
	x2 = (checking + .99);
	if (x1==x2)
	//if double checking is a flat dollar amount x1 and x2 will be the same int
	//print without decimal values
	{
		cout << "Checking Now: " << checking << endl;
	}
	else
	//if double checking has cents, use setprecision to print out two decimal values
	{
		cout << "Checking Now: " << fixed << setprecision(2) << checking << endl;
		cout.copyfmt(ios(NULL));
		//clears setprecision 
	}

	y1 = savings;
	y2 = (savings + .99);
	if (y1 == y2)
	//if double savings is a flat dollar amount y1 and y2 will be the same int
	//print without decimal values
	{
		cout << "Savings Now: " << savings << endl;
	}
	else
	// if double savings has cents, then use setprecision to print out two decimal values
	{
		cout << "Savings Now: " << fixed << setprecision(2) <<savings << endl;
	}
}


int main()
{
	string account, action;
	double amount;
	cout << "Account: ";
	cin >> account;
	cout << "Action: ";
	cin >> action;
	cout << "Amount: ";
	cin >> amount;

	Portfolio BankAccount(amount, account);
	//uses if statements to determine which member function will be called
	if (action == "D")
	{
		BankAccount.deposit(amount, account);
	}
	else if (action == "W")
	{
		BankAccount.withdraw(amount, account);
	}
	else
	{
		BankAccount.transfer(amount, account);
	}
	BankAccount.print_balances();

	return 0;
}