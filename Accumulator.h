//
// Created by ad on 3/23/20.
//

#ifndef BANKING_SIMULATION_ACCUMULATOR_H
#define BANKING_SIMULATION_ACCUMULATOR_H

#include "Date.h"

class Accumulator {
private:
    Date lastDate;
    double value;
    double sum;

public:
    Accumulator(const Date &date, double value) : lastDate(date), value(value), sum(0) {}

    double getSum(const Date &date) const {
        return sum + value * date.distance(lastDate);
    }

    void change(const Date &date, double value) {
        sum = getSum(date);
        lastDate = date;
        this->value = value;
    }

    void reset(const Date &date, double value) {
        lastDate = date;
        this->value = value;
        sum = 0;
    }
};

#endif //BANKING_SIMULATION_ACCUMULATOR_H
