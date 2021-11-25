#include "item.cpp"

#define VALUE 10

#pragma once
class Potion: public Item {

    private:
        int healingValue;

    public:
        Potion() {
            healingValue = VALUE;
        }

        int getHealingValue() {
            return healingValue;
        }
};
