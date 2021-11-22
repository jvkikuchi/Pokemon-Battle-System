#include <iostream>
#include "pokemon.cpp"
#include "utils.h"

using namespace std;

int main() {
    Pokemon pokemon1 = Pokemon();
    Pokemon pokemon2 = Pokemon();
    Utils utils;
    while (pokemon1.getHp() > 0 && pokemon2.getHp() > 0 ) {
        int dice1 = utils.dice();
        int atk1 = pokemon1.getAtk() + dice1;
        int dano1 = atk1 - pokemon2.getDef();
        cout << "Pokemon 1 causou " << dano1 << " pontos de dano!" << endl;
        pokemon2.decHp( dano1 );
        cout << "Pokemon 2 possui " << pokemon2.getHp() << " pontos de vida." << endl;
        if ( pokemon2.getHp() <= 0 ) {
            cout << "Pokemon 1 venceu!" << endl;
            break;
        }

        int dice2 = utils.dice();
        int atk2 = pokemon2.getAtk() + dice2;
        int dano2 = atk2 - pokemon1.getDef();
        cout << "Pokemon 2 causou " << dano2 << " pontos de dano!" << endl;
        pokemon1.decHp( dano2 );
        cout << "Pokemon 1 possui " << pokemon1.getHp() << " pontos de vida." << endl;
        if ( pokemon1.getHp() <= 0 ) {
            cout << "Pokemon 2 venceu!" << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}

void attack(){
    

}