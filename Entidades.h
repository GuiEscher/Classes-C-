#include <string.h>
#include <stdbool.h>

class Entidade{
public:
    Entidade(const char *nome,int HpAtual, int maxHp, int manaAtual, int maxMana, bool Envenenado);
    //~Entidade();
    int getHpAtual();
    int getManaAtual();
    bool getEnvenenado(bool);
    int getMaxHp();
    int getMaxMana();
    const char* getNome();
    

private:
    char* nome;
    int HpAtual;
    int maxHp;
    int manaAtual;
    int maxMana;
    bool Envenenado;
};
Entidade::Entidade(const char* nome, int HpAtual, int maxHp, int manaAtual, int maxMana, bool Envenenado){
    this->nome = new char[strlen(nome)+1];//passando a string alocada dinamicamente para variavel nome
    strcpy(this->nome, nome);
    this->HpAtual = 100;
    this->maxHp = 100;
    this->manaAtual = 100;
    this->maxMana = 100;
    this->Envenenado = false;
}
const char* Entidade::getNome(){
    return nome;
}
int Entidade::getHpAtual(){
    return HpAtual;
}
int Entidade::getManaAtual(){
    return manaAtual;
}
int Entidade::getMaxHp(){
    return maxHp;
}
int Entidade::getMaxMana(){
    return maxMana;
}
bool Entidade::getEnvenenado(bool EstaEnvenenado){
    EstaEnvenenado = true;
    return EstaEnvenenado;
}
class Player : public Entidade{
public:
    Player(const char*, int, int, int, int, bool);
private:
};
Player::Player(const char *nome,int HpAtual, int maxHp, int manaAtual, int maxMana, bool Envenenado) : Entidade(nome, HpAtual, maxHp, manaAtual, maxMana, Envenenado){

}
class Enemy : public Entidade{
public:
    Enemy(const char*, int, int, int, int, bool);
private:

};
Enemy::Enemy(const char *nome,int HpAtual, int maxHp, int manaAtual, int maxMana, bool Envenenado) : Entidade(nome, HpAtual, maxHp, manaAtual, maxMana, Envenenado){

}
