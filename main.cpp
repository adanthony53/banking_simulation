#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    Date date(2000,1,1);

    SavingsAccount s1(date, "s1", 0.015);
    SavingsAccount s2(date, "s1", 0.015);
    CreditAccount c1(date, "c1", 5000, 0.003, 50);
    CreditAccount c2(date, "c2", 15000, 0.004, 50);

    cout << "Transaction in Jan." << endl;
    s1.deposit(Date(2000,1,5), 5000, "salary");

    cout << "Transaction in Feb." << endl;
    s1.deposit(Date(2000,2,5), 5000, "salary");
    s2.deposit(Date(2000,2,5), 15000, "sell stock");
    c1.withdraw(Date(2000, 2, 1), 2000, "buy a stock");

    cout << "Transaction in Mar." << endl;
    c1.settle(Date(2000, 3, 1));
    c1.deposit(Date(2000, 3, 1), 2174, "pay credit card dept");

    cout << "settle all accounts on 3-1-2000" << endl;
    s1.settle(Date(2000, 3, 1));
    s2.settle(Date(2000, 3, 1));
    c1.settle(Date(2000, 3, 1));

    cout << endl;
    s1.show(); cout << endl;
    s2.show(); cout << endl;
    c1.show(); cout << endl;

    cout << "Total: " << Account::getTotal() << endl;
    return 0;
}
