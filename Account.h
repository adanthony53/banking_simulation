//
// Created by ad on 3/23/20.
//

#ifndef BANKING_SIMULATION_ACCOUNT_H
#define BANKING_SIMULATION_ACCOUNT_H

#include "Date.h"
#include "Accumulator.h"
#include <string>
#include <map>
#include <istream>
#include <stdexcept>

class Account;

class AccountRecord {
private:
    Date date;
    const Account *account;
    double amount;
    double balance;
    std::string desc;

public:
    AccountRecord(const Date &date, const Account *account, double amount, double balance, const std::string& desc);
    void show() const;
};

typedef  std::multimap<Date, AccountRecord> RecordMap;

class Account {
private:
    std::string id;
    double balance;
    static double total;
    static RecordMap recordMap;

protected:
    Account(const Date &date, const std::string &id);
    void record(const Date &date, double amount, const std::string &desc);
    void error(const std::string &msg) const;

public:
    const std::string &getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    virtual void deposit(const Date &date, double amount, const std::string &desc) = 0;
    virtual void withdraw(const Date &date, double amount, const std::string &desc) = 0;
    virtual void settle(const Date &date) = 0;
    virtual void show(std::ostream &out) const;
    static void query(const Date& begin, const Date& end);
};

inline std::ostream & operator << (std::ostream &out, const Account &account) {
    account.show(out);
    return out;
}

class SavingsAccount : public Account {
private:
    Accumulator acc;
    double rate;

public:
    SavingsAccount(const Date &date, const std::string &id, double rate);
    double getRate() const { return rate; }

    virtual void deposit(const Date &date, double amount, const std::string &desc);
    virtual void withdraw(const Date &date, double amount, const std::string &desc);
    virtual void settle(const Date &date);
};

class CreditAccount : public Account {
private:
    Accumulator acc;
    double credit;
    double rate;
    double fee;

    double getDebt() const {
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }

public:
    CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {
        if (getBalance() < 0) {
            return credit + getBalance();
        } else {
            return credit;
        }
    }

    virtual void deposit(const Date &date, double amount, const std::string &desc);
    virtual void withdraw(const Date &date, double amount, const std::string &desc);
    virtual void settle(const Date &date);

    virtual void show(std::ostream &out) const;
};

class AccountException : public  std::runtime_error {
private:
    const Account *account;

public:
    AccountException(const Account *account, const std::string &msg) : runtime_error(msg), account(account) {}
    const Account *getAccount() const { return account; }
};

#endif //BANKING_SIMULATION_ACCOUNT_H
