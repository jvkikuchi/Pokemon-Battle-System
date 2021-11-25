#include <iostream>
#include "potion.cpp"

using namespace std;

#define MAXHP 30

class Pokemon {

    private:
        string name;  
        int atk;
        int def;
        int hp;

    public:
        Pokemon() {
            atk = 10;
            def = 5;
            hp = MAXHP;
        }

        string getName() {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }

        int getAtk() {
            return atk;
        }

        void setAtk(int atk) {
            this->atk = atk;
        }

        int getDef() {
            return def;
        }

        void setDef(int def) {
            this->def = def;
        }

        int getHp() {
            return hp;
        }

        void setHp(int hp) {
            this->hp = hp;
        }

        void incHp(int hp) {
            this->hp += hp;
            if ( this->hp > MAXHP ) {
                this->hp = MAXHP;
            }
        }

        void decHp(int hp) {
            this->hp -= hp;
            if ( this->hp < 0 ) {
                this->hp = 0;
            }
        }

        void usePotion() {
            Item *hibrido;
            Potion referencia;
            hibrido = &referencia;
            incHp(hibrido->getHealingValue());
        }

        int getMaxHp() {
            return MAXHP;
        }
};
