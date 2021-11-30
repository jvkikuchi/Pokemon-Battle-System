#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pokemon.cpp"
#include "utils.h"


using namespace std;

Pokemon pokemon1 = Pokemon();
Pokemon pokemon2 = Pokemon();

Utils utils;

void attack1();
void attackElemental1();
void attack2();
void attackElemental2();
void menu();
int chooseAttack();
int dice();

int main(){

  pokemon1.setElemental(1); //fogo
  pokemon2.setElemental(2); //agua

  int action[3];
  bool usedPotion = false;

  //CONDICAO DE FINALIZAR A PARTIDA
  while (pokemon1.getHp() > 0 && pokemon2.getHp() > 0){
    for (int i = 1; i <= 2; i++){
      menu();
      cout << "Acao do POKEMON " << i << ": ";
      cin >> action[i];
      if (action[i] == 0){
        return 0;
      }
    }

    //CONDICAO USAR A POÇAO VEM PRIMEIRO QUE O COMBATE, JA QUE A AÇAO SEMPRE SEMPRE VAI OCORRER ANTES DO COMBATE
    switch (action[1]){
      case 2:{
        pokemon1.usePotion();
        cout << "POKEMON 1 utilizou pocao de cura!" << endl;
      }; break;

      case 0: return 0; break;
    }

    switch (action[2]){
      case 2:{
        pokemon2.usePotion();
        cout << "POKEMON 2 utilizou pocao de cura!" << endl;
        usedPotion = false;
      }; break;
      case 0: return 0; break;
    }

  //CONDICAO DO POKEMON 1 TER USADO POÇAO, ENTAO O POKEMON 2 VAI ATACAR PRIMEIRO NO PROXIMO TURNO
    if (usedPotion && action[2] == 1){
      attack2();
      if (pokemon1.getHp() <= 0){
        cout << "POKEMON 2 venceu!" << endl;
        break;
      }
      //SETANDO O usedPotion PARA FALSE, DPS DO POKEMON 2 JA TER ATACADO PRIMEIRO
      usedPotion = false;
      if (action[1] == 1){
        int option = chooseAttack();

        switch (option){
          case 1:{
            attack1();
          } break;

          case 2:{
          attackElemental1();
          } break;
        }

        //attack1();
        if (pokemon2.getHp() <= 0){
          cout << "POKEMON 1 venceu!" << endl;
          break;
        }
      }
    }

    else{
      if (action[1] == 1){
        int option = chooseAttack();

        switch (option){
          case 1:{
            attack1();
          } break;

          case 2:{
            attackElemental1();
          }
        }

        if (pokemon2.getHp() <= 0){
          cout << "POKEMON 1 venceu!" << endl;
          break;
        }
      }

      if (action[2] == 1){
        int option = chooseAttack();

        switch (option){
          case 1:{
            attack2();
          } break;

          case 2:{
            attackElemental2();
          } break;
        }

        if (pokemon1.getHp() <= 0){
          cout << "POKEMON 2 venceu!" << endl;
        }
      }
    }

    if (action[1] == 2){
      usedPotion = true;
    }

    cout << "\nPOKEMON 1 = " << pokemon1.getHp() << "/" << pokemon1.getMaxHp();
    cout << " ; POKEMON 2 = " << pokemon2.getHp() << "/" << pokemon2.getMaxHp() << endl;
  }

  return 0;
}

void attackElemental1(){

  int dice1 = utils.dice();
  int atk1 = pokemon1.getAtk() + dice1;
  int dano1 = atk1 - pokemon2.getDef();

  if (pokemon1.getElemental() == 1 && pokemon2.getElemental() == 2){ //fogo x agua
    dano1 *= 2;
  }
  else if (pokemon1.getElemental() == 2 && pokemon2.getElemental() == 3){ //agua x folha
    dano1 *= 2;
  }
  else if (pokemon1.getElemental() == 3 && pokemon2.getElemental() == 1){ //folha x fogo
    dano1 *= 2;
  }
  else{
    dano1 /= 2;
  }

  cout << "POKEMON 1 causou " << dano1 << " pontos de dano!" << endl;
  pokemon2.decHp(dano1);
};

void attack1(){


  int dice1 = utils.dice();
  int atk1 = pokemon1.getAtk() + dice1;
  int dano1 = atk1 - pokemon2.getDef();

  cout << "POKEMON 1 causou " << dano1 << " pontos de dano!" << endl;
  pokemon2.decHp(dano1);
};

void attack2(){

  int dice2 = utils.dice();
  int atk2 = pokemon2.getAtk() + dice2;
  int dano2 = atk2 - pokemon1.getDef();

  cout << "POKEMON 2 causou " << dano2 << " pontos de dano!" << endl;
  pokemon1.decHp(dano2);
};

void attackElemental2(){

  int dice2 = utils.dice();
  int atk2 = pokemon2.getAtk() + dice2;
  int dano2 = atk2 - pokemon1.getDef();

  if (pokemon2.getElemental() == 1 && pokemon1.getElemental() == 2){ //fogo x agua
    dano2 *= 2;
  }
  else if (pokemon2.getElemental() == 2 && pokemon1.getElemental() == 3){ //agua x folha
    dano2 *= 2;
  }
  else if (pokemon2.getElemental() == 3 && pokemon1.getElemental() == 1){ //folha x fogo
    dano2 *= 2;
  }else{
    dano2 /= 2;
  }

  cout << "POKEMON 2 causou " << dano2 << " pontos de dano!" << endl;
  pokemon1.decHp(dano2);
};



void menu(){
  cout << "\nMENU:" << endl;
  cout << "(1) Atacar" << endl;
  cout << "(2) Usar pocao" << endl;
  cout << "(0) Sair" << endl;
};

int chooseAttack(){
  int attackChoice;

  cout << "\nEscolha o tipo de ataque: " << endl;
  cout << "(1) Fisico" << endl;
  cout << "(2) Elemental" << endl;
  cout << "(3) Status" << endl;
  cout << "Escolha: ";

  cin >> attackChoice;

  cout << endl;

  return attackChoice;
}