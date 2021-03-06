//
// Created by ad on 3/23/20.
//

#ifndef BANKING_SIMULATION_DATE_H
#define BANKING_SIMULATION_DATE_H

#include <iostream>

class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;

public:
    Date(int year = 1, int month = 1, int day = 1);
    static Date read();
    int getYear() const { return year; };
    int getMonth() const { return month; };
    int getDay() const { return day; }
    int getMaxDay() const;
    int isLeapYear() const {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    void show() const;
    int operator - (const Date& date) const {
        return totalDays - date.totalDays;
    }

    bool operator < (const Date& date) const {
        return totalDays < date.totalDays;
    }
};

std::istream & operator >> (std::istream &in, Date &date);
std::ostream & operator << (std::ostream &out, const Date &date);
#endif //BANKING_SIMULATION_DATE_H
