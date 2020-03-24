#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    Date date(2000,1,1);

    //create accounts
    SavingsAccount s1(date, "s1", 0.015);
    SavingsAccount s2(date, "s2", 0.015);
    CreditAccount c1(date, "c1", 5000, 0.003, 50);

    Account *accounts[] = {&s1, &s2, &c1};
    const int n = sizeof(accounts) / sizeof(accounts[0]);
    cout << n << endl;

    cout << "(d)deposit (w)withdraw (s)show (c)change day (n)next month (e)exit" << endl;
    char cmd;
    do {
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand > ";
        int index, day;
        double amount;
        string desc;

        cin >> cmd;
        switch(cmd) {
            case 'd':
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->deposit(date, amount, desc);
                break;
            case 'w':
                cin >> index >> amount;
                getline(cin, desc);
                accounts[index]->withdraw(date, amount, desc);
                break;
            case 's':
                for (int i = 0; i < n; i++) {
                    cout << "[" << i << "]";
                    accounts[i]->show();
                    cout << endl;
                }
                break;
            case 'c':
                cin >> day;
                if (day < date.getDay()) {
                    cout << "cannot change to previous day";
                } else if (day > date.getMaxDay()) {
                    cout << "invalid day";
                } else {
                    date = Date(date.getYear(), date.getMonth(), day);
                }
                break;
            case 'n':
                if (date.getMonth() == 12) {
                    date = Date(date.getYear()+1, 1, 1);
                } else {
                    date = Date(date.getYear(), date.getMonth()+1, 1);
                }
                for (int i = 0; i < n; i++) {
                    accounts[i]->settle(date);
                }
                break;
        }
    } while (cmd != 'e');

    return 0;
}
