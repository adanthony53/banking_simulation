//
// Created by ad on 3/23/20.
//

#include "Date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

namespace {
    const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
}

int Date::getMaxDay() const {
    if (isLeapYear() && month == 2) {
        return 29;
    } else {
        return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month-1];
    }
}

void Date::show() const {
    cout << getYear() << "-" << getMonth() << "-" << getDay() << endl;
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    if (day <= 0 | day > getMaxDay()) {
        cout << "invalid date" << endl;
        exit(1);
    }
    int years = year - 1;
    totalDays = years * 365 + years / 4 - years / 100 + years / 400
                + DAYS_BEFORE_MONTH[month - 1] + day;
    if (isLeapYear() && month > 2) totalDays++;
}

Date Date::read() {
    int year, month, day;
    char c1, c2;
    cin >> year >> c1 >> month >> c2 >> day;
    return Date(year, month, day);
}
