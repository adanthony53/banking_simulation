//
// Created by ad on 3/23/20.
//
#include <cmath>
#include <iostream>
#include "Account.h"
using namespace std;
using namespace std::rel_ops;

// --------------------------------- AccountRecord ---------------------------------

AccountRecord::AccountRecord(const Date &date, const Account *account, double amount, double balance, const std::string& desc)
        : date(date), account(account), amount(amount), balance(balance), desc(desc) { }

void AccountRecord::show() const {
    date.show();
    cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

double Account::total = 0;
RecordMap Account::recordMap;

// --------------------------------- Account ---------------------------------

Account::Account(const Date &date, const std::string &id) : id(id), balance(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void Account::record(const Date &date, double amount, const std::string &desc) {
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    //date.show();
    //cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
    AccountRecord record(date, this, amount, balance, desc);
    recordMap.insert(make_pair(date, record));
    record.show();
}

void Account::show(ostream &out) const {
    out << id << "\t balance: " << balance;
}

void Account::error(const std::string &msg) const {
    cout << "Error #" << id << " " << msg << endl;
}

void Account::query(const Date &begin, const Date &end) {
    if (begin <= end) {
        RecordMap::iterator iter1 = recordMap.lower_bound(begin);
        RecordMap::iterator iter2 = recordMap.upper_bound(end);
        for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
            iter->second.show();
    }
}

// --------------------------------- SavingsAccount ---------------------------------

SavingsAccount::SavingsAccount(const Date &date, const std::string &id, double rate) :
        Account(date, id), rate(rate), acc(date, 0) { }

void SavingsAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount > getBalance()) {
        error("not enough balance");
    } else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

// calculate interest
void SavingsAccount::settle(const Date &date) {
    if (date.getMonth() == 1) { //calculate interest at every January
        double interest = acc.getSum(date) * rate /
                (date - Date(date.getYear()-1, 1, 1));
        if (interest != 0) {
            record(date, interest, "interest");
        }
        acc.reset(date, getBalance());
    }
}

// --------------------------------- CreditAccount ---------------------------------

CreditAccount::CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee)
    : Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) { }

void CreditAccount::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}

void CreditAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount - getBalance() > credit) {
        error("not enough credit.");
    } else {
        record(date, -amount, desc);
        acc.change(date, getDebt());
    }
}

void CreditAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0) {
        record(date, interest, "interest");
    }
    if (date.getMonth() == 1) {
        record(date, -fee, "annual fee");
    }
    acc.reset(date, getDebt());
}

void CreditAccount::show(ostream &out) const {
    Account::show(out);
    out << "\tAvailable credit: " << getAvailableCredit();
}

