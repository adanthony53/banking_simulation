//
// Created by ad on 3/23/20.
//
#include <cmath>
#include <iostream>
#include "Account.h"
using namespace std;

double Account::total = 0;

Account::Account(const Date &date, const std::string &id, double rate) :
        id(id), balance(0), rate(rate), lastDate(date), accumulation(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void Account::record(const Date &date, double amount, const std::string &desc) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

void Account::error(const std::string &msg) const {
    cout << "Error #" << id << " " << msg << endl;
}

void Account::deposit(const Date &date, double amount, const std::string &desc) {
    record(date, amount, desc);
}

void Account::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount > balance) {
        error("not enough balance");
    } else {
        record(date, -amount, desc);
    }
}

void Account::settle(const Date &date) {
    double interest = accumulate(date) * rate / date.distance(Date(date.getYear()-1, 1, 1));
    if (interest != 0) {
        record(date, interest, "interest");
    }
    accumulation = 0;
}

void Account::show() const {
    cout << id << "\tBalance: " << balance;
}
