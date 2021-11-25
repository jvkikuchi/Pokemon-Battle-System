#include <iostream>
#include "pokemon.cpp"
#include "utils.h"

using namespace std;

Pokemon pokemon1 = Pokemon();
Pokemon pokemon2 = Pokemon();
Utils utils;

void attack1();
void attack2();

int main() {
    auto menu = []() {
        cout << "MENU:" << endl;
        cout << "(1) Atacar" << endl;
        cout << "(2) Usar poção" << endl;
        cout << "(0) Sair" << endl;
    };

    int action[3];
    bool usedPotion = false;

    while( pokemon1.getHp() > 0 && pokemon2.getHp() > 0 ) {
        for ( int i = 1; i <= 2; i++ ) {
            menu();
            cout << "Ação do pokemon " << i << ": ";
            cin >> action[i];
            if ( action[i] == 0 ) {
                return 0;
            }
        }

        switch(action[1]) {
            case 1: break;
            case 2: {
                pokemon1.usePotion();
                cout << "Pokemon 1 utilizou poção de cura!" << endl;
            }; break;
            case 0: return 0; break;
        }

        switch(action[2]) {
            case 1: break;
            case 2: {
                pokemon2.usePotion();
                cout << "Pokemon 2 utilizou poção de cura!" << endl;
                usedPotion = false;
            }; break;
            case 0: return 0; break;
        }

        if ( usedPotion && action[2] == 1 ) {
            attack2();
            if ( pokemon1.getHp() <= 0 ) {
                cout << "Pokemon 2 venceu!" << endl;
                break;
            }
            usedPotion = false;
            if ( action[1] == 1 ) {
                attack1();
                if ( pokemon2.getHp() <= 0 ) {
                    cout << "Pokemon 1 venceu!" << endl;
                    break;
                }
            }
        }
        else {
            if ( action[1] == 1 ) {
                attack1();
                if ( pokemon2.getHp() <= 0 ) {
                    cout << "Pokemon 1 venceu!" << endl;
                    break;
                }
            }
            if ( action[2] == 1 ) {
                attack2();
                if ( pokemon1.getHp() <= 0 ) {
                    cout << "Pokemon 2 venceu!" << endl;
                }
            }
        }
        if ( action[1] == 2 ) {
            usedPotion = true;
        }
        cout << "\nPokemon 1 = " << pokemon1.getHp() << "/" << pokemon1.getMaxHp();
        cout << " ; Pokemon 2 = " << pokemon2.getHp() << "/" << pokemon2.getMaxHp() << endl;
    }

    return 0;
}

void attack1() {
    int dice1 = utils.dice();
    int atk1 = pokemon1.getAtk() + dice1;
    int dano1 = atk1 - pokemon2.getDef();
    cout << "Pokemon 1 causou " << dano1 << " pontos de dano!" << endl;
    pokemon2.decHp( dano1 );
};

void attack2() {
    int dice2 = utils.dice();
    int atk2 = pokemon2.getAtk() + dice2;
    int dano2 = atk2 - pokemon1.getDef();
    cout << "Pokemon 2 causou " << dano2 << " pontos de dano!" << endl;
    pokemon1.decHp( dano2 );
};

