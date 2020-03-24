#include <iostream>
#include "Account.h"
using namespace std;

int main() {
    Date date(2000,1,1);
    SavingsAccount accounts[] = {
            SavingsAccount(date, "S333222111", 0.015),
            SavingsAccount(date, "T000111222", 0.015)
    };
    const int n = sizeof(accounts)/sizeof(accounts[0]);

    accounts[0].deposit(Date(2000,1,3), 5000, "salary");
    accounts[1].deposit(Date(2000,2,3), 15000, "sell stock");
    accounts[0].deposit(Date(2000,2,3), 5500, "salary");
    accounts[1].withdraw(Date(2000,12,3), 3000, "buy stock");
    cout << endl;

    for (int i = 0; i < n; i++) {
        accounts[i].settle(Date(2001, 1, 1));
        accounts[i].show();
        cout << endl;
    }


    cout << "Total: " << SavingsAccount::getTotal() << endl;
    return 0;
}
