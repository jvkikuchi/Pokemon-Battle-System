#include "item.cpp"

#define VALUE 10

#pragma once
//HERANÇA
class Potion: public Item {

    private:
        int healingValue;
        int usedValue;

    public:
        Potion() {
            healingValue = VALUE;
            
        }

        //SOBRECARGA
        int getHealingValue() {
            return healingValue;
        }
};