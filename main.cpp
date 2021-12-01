#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pokemon.cpp"
#include "utils.h"


using namespace std;

Pokemon pokemon1 = Pokemon();
Pokemon pokemon2 = Pokemon();

Utils utils;

int pokemon1UsedPotions = 3;
int pokemon2UsedPotions = 3;

void attack1();
void attackElemental1();
void attack2();
void attackElemental2();
void menu();
int chooseAttack();
int chooseAttackBot();
int dice();

int main(){


  pokemon1.setElemental(utils.randomType()); //fogo
  pokemon2.setElemental(utils.randomType()); //agua

  int action[3];
  bool usedPotion = false;

  cout << "\n---HORA DA BATALHA!!---\n" << endl;

  cout << "TIPO DO POKEMON 1: " << pokemon1.getElemental() << endl;
  cout << "TIPO DO POKEMON 2: " << pokemon2.getElemental() << endl;


  //CONDICAO DE FINALIZAR A PARTIDA
  while (pokemon1.getHp() > 0 && pokemon2.getHp() > 0){
    for (int i = 1; i <= 2; i++){
      menu();
      cout << "Acao do POKEMON " << i << ": ";
      
      // ANALISA SE O BOT AINDA TEM POSCOES PARA USAR E SE O SEU HP EH MAXIMO
      // NO CASO DO BOT NAO TER MAIS POCOES, ELE EH FORCADO A ATACAR
      // E NO CASO DO HP DELE SER MAXIMO, ELE NAO VAI PODER USAR POCAO, E VAI ATACAR, OU SEJA
      // O BOT SO UTILIZA POCAO DPS DO FINAL DO PRIMEIRO TURNO

      if(i == 2){
        if(pokemon2UsedPotions == 0){
          action[i] = 1;
        } else if(pokemon2.getHp() == pokemon2.getMaxHp()){
          action[i] = 1;
        } else{
          action[i] = chooseAttackBot(); 
        }

        cout << "\n\nBOT ESCOLHEU OPCAO: " << action[i] << "\n" << endl;
      }else{     // PRIMEIRO INPUT DO USUARIO
        cin >> action[i];
      }
     
      if(action[i] == 0){
        return 0;
      }
    }

    //CONDICAO USAR A POÇAO VEM PRIMEIRO QUE O COMBATE, JA QUE A AÇAO SEMPRE SEMPRE VAI OCORRER ANTES DO COMBATE
    switch (action[1]){
      case 2:{
        if(pokemon1UsedPotions == 0){
          cout << "SUAS POCOES ACABARAM, VOCE SO PODE ATACAR" << endl;
          int option = chooseAttack();

         switch (option){
          case 1:{
            attack1();
          } break;

          case 2:{
            attackElemental1();
          } 
         }
        }else {
          pokemon1.usePotion();
          cout << "POKEMON 1 utilizou pocao de cura!" << endl;
          pokemon1UsedPotions--;
        }
      }; break;

      case 0: return 0; break;
    }

    switch (action[2]){
      case 2:{
        pokemon2.usePotion();
        pokemon2UsedPotions--;
        cout << "POKEMON 2 utilizou pocao de cura!" << endl;
        usedPotion = false;
      }; break;
      case 0: return 0; break;
    }

  //CONDICAO DO POKEMON 1 TER USADO POÇAO, ENTAO O POKEMON 2 VAI ATACAR PRIMEIRO NO PROXIMO TURNO
    if (usedPotion && action[2] == 1){
      attack2();
      if (pokemon1.getHp() <= 0){
        cout << "O BOT VENCEU, PRESS F TO PAY RESPECT!" << endl;
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
          cout << "PARABENS, VOCE VENCEU UM BOT!" << endl;
          break;
        }
      }
    }

   // A PARTIR DAQUI SAO AS FUNCOES DE ATAQUE
    else{
      //SE O USUARIO DECIDIR ATACAR
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

        //CONDICIONAL PARA CHEGAR O HP DO POKEMON ADVERSARIO, E TALVEZ ENCERRAR A PARTIDA
        if (pokemon2.getHp() <= 0){
          cout << "PARABENS, VOCE VENCEU UM BOT!" << endl;
          break;
        }
      }
      // SE O BOT DECIDIR ATACAR
      if (action[2] == 1){
        int option = chooseAttackBot();
        pokemon2UsedPotions = pokemon2UsedPotions;
        cout << "BOT ESCOLHEU OPCAO: " << option;

        switch (option){
          case 1:{
            attack2();
          } break;

          case 2:{
            attackElemental2();
          } break; 
          
        }
        //CONDICIONAL PARA CHEGAR O HP DO POKEMON ADVERSARIO, E TALVEZ ENCERRAR A PARTIDA
        if (pokemon1.getHp() <= 0){
          cout << "O BOT VENCEU, PRESS F TO PAY RESPECT!" << endl;
        }
      }
    }

    //SE O USUARIO USAR POCAO, O PROGRAMA IDENTIFICA, E O BOT ATACA PRIMEIRO NO PROXIMO TURNO 
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

  if (pokemon1.getElemental() == 1 && pokemon2.getElemental() == 2){ //agua x fogo
    dano1 *= 2;
  }
  else if (pokemon1.getElemental() == 2 && pokemon2.getElemental() == 3){ //folha x agua
    dano1 *= 2;
  }
  else if (pokemon1.getElemental() == 3 && pokemon2.getElemental() == 1){ //fogo x folha
    dano1 *= 2;
  }
  else{
    dano1 /= 2;
  }

  cout << "POKEMON 1 utilizou um ataque elemental e causou " << dano1 << " pontos de dano!" << endl;
  pokemon2.decHp(dano1);
};

void attack1(){
  int dice1 = utils.dice();
  int atk1 = pokemon1.getAtk() + dice1;
  int dano1 = atk1 - pokemon2.getDef();

  cout << "POKEMON 1 causou " << dano1 << " pontos de dano!\n" << endl;
  pokemon2.decHp(dano1);
};

void attack2(){

  int dice2 = utils.dice();
  int atk2 = pokemon2.getAtk() + dice2;
  int dano2 = atk2 - pokemon1.getDef();

  cout << "\n\nPOKEMON 2 causou " << dano2 << " pontos de dano!" << endl;
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

  cout << "\n\nPOKEMON 2 utilizou um ataque elemental e causou " << dano2 << " pontos de dano!" << endl;
  pokemon1.decHp(dano2);
};

void menu(){
  cout << "\nMENU:" << endl;
  cout << "(1) Atacar" << endl;
  cout << "(2) Usar pocao" << endl;
  cout << "(0) Sair" << endl;
};

int chooseAttack(){
  int attackChoicePlayer;

  cout << "\nEscolha o tipo de ataque: " << endl;
  cout << "(1) Fisico" << endl;
  cout << "(2) Elemental" << endl;
  cout << "Escolha: ";

  cin >> attackChoicePlayer;

  cout << endl;

  return attackChoicePlayer;
}

int chooseAttackBot(){
  int attackChoice;

  attackChoice = utils.randomOption();

  return attackChoice;
}