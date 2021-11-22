#include <iostream>

using namespace std;

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
            hp = 20;
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
        }

        void decHp(int hp) {
            this->hp -= hp;
        }

        
};
