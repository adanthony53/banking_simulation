//
// Created by ad on 3/23/20.
//

#ifndef BANKING_SIMULATION_DATE_H
#define BANKING_SIMULATION_DATE_H


class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;

public:
    Date(int year, int month, int day);
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
};


#endif //BANKING_SIMULATION_DATE_H
