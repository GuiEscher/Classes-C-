#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//criação da classe
class Computador{
//declarações publicas e privadas
public:
    Computador();//construtor
    void download_arquivo();
    void excluir_arquivo();
    void abrir_app();
    void imprimir();
    string getCor();
    string getModeloProcessador();
    float getMemoriaTotal();
    float getMemoriaUsada();
    float getMemoriaRam();
    bool getLigado();

private:
    string modeloProcessador;
    string cor;
    float memoriaRam;
    float memoriaTotal;
    float memoriaUsada;
    bool Ligado;
    void setCor(string x);
    void setModeloProcessador(string y);
    void setMemoriaTotal(float x);
    void setMemoriaUsada(float x);
    void setMemoriaRam(float x);
    void setLigado(bool x);
    
};
//construtor
Computador::Computador(){
    float memR, memU, memT;
    string modelo, cor;
    bool k;
    //atribuições iniciais
    cout<<"Memoria maxima do computador:"<<endl;
    cin>>memT;
    this->memoriaTotal=memT;
    
    cout<<"Memoria usada:"<<endl;
    cin>>memU;
    this->memoriaUsada=memU;
    
    cout<<"Memoria ram instalada:"<<endl;
    cin>>memR;
    this->memoriaRam=memR;
    
    cout<<"Qual a cor do gabinete?"<<endl;
    cin>>cor;
    this->cor=cor;
    
    cout<<"Qual é o processador?"<<endl;
    cin>>modelo;
    this->modeloProcessador=modelo;
    
    cout<<"O computador está ligado? 1- ligado, 2- desligado."<<endl;
    cin>>k;
    if((k==1)||(k==0)){
        this->Ligado=k;
    }
}
//metodos get
float Computador::getMemoriaTotal(){
    return memoriaTotal;
}
float Computador::getMemoriaUsada(){
    return memoriaUsada;
}
float Computador::getMemoriaRam(){
    return memoriaRam;
}
string Computador::getCor(){
    return cor;
}
string Computador::getModeloProcessador(){
    return modeloProcessador;
}
bool Computador::getLigado(){
    return Ligado;
}
void Computador::setMemoriaTotal(float x){
    memoriaTotal=x;
}
void Computador::setMemoriaUsada(float x){
    memoriaUsada=x;
}
void Computador::setMemoriaRam(float x){
    memoriaRam=x;
}
void Computador::setModeloProcessador(string y){
    modeloProcessador=y;
}
void Computador::setCor(string x){
    cor=x;
}
void Computador::setLigado(bool x){
    Ligado=x;
}
void Computador::download_arquivo(){
    int tamanho;
    if(this->getLigado()==true){
        cout<<"Tamanho do arquivo que deseja baixar:"<<endl;
        cin>>tamanho;
        float x=memoriaUsada+tamanho;
        if(x>memoriaTotal){
            cout<<"\nmemória insuficiente!!!"<<endl;
        }else{
            memoriaUsada+=tamanho;
        }
    }else{
        cout<<"O computador esta desligado, impossivel baixar arquivo"<<endl;
    }
}
void Computador::excluir_arquivo(){
        int tamanho;
    if(this->getLigado()==true){
        cout<<"Tamanho do arquivo que deseja excluir:"<<endl;
        cin>>tamanho;
        float x=memoriaUsada-tamanho;
        if(x<0){
            cout<<"\nEste arquivo e maior que a memoria usada, ou seja, nao existe!!!"<<endl;
        }else{
            memoriaUsada-=tamanho;
        }
    }else{
        cout<<"O computador esta desligado, impossivel baixar arquivo"<<endl;
    }
    
}
void Computador::abrir_app(){
    string x;
    int aux=0;
    int y;
    cout<<"Iniciando abertura de aplicativos."<<endl;
    cout<<"lembre-se, quanto mais apps abertos, mais memoria ram é utilizada e o computador pode travar"<<endl;
    cout<<"é sugerido abrir no máximo 2 apps caso tenha 4gb de ram, 4 caso 8gb e 7 caso 16gb"<<endl;
    cout<<"\nAbra os aplicativos inserindo seus nomes. Caso queira sair digite 'sair'"<<endl;
    cout<<"Aplicativos abertos:"<<endl;
    while(x!="sair"){
        cin>>x;
        if(x=="sair"){
            break;
        }
        aux++;
        //cout<<x<<", ";
        if(this->getMemoriaRam()==4){
            if(aux==3){
                cout<<"Você abriu muitos apps! O computador possui apenas 4gb. Ficou sem ram e travou!"<<endl;
                break;
            }
        }else if(this->getMemoriaRam()==8){
            if(aux==5){
                cout<<"Você abriu muitos apps! O computador possui apenas 8gb. Ficou sem ram e travou!"<<endl;
                break;
            }
        }else if(this->getMemoriaRam()==16){
            if(aux==8){
                cout<<"Você abriu muitos apps! O computador possui apenas 16gb. Ficou sem ram e travou!"<<endl;
                break;
            }
        }
    }
    
}

void Computador::imprimir(){
    
    cout << "\nMemoria Total do PC: " << this->getMemoriaTotal() << endl;
    cout << "Memoria usada atualmente: " << this->getMemoriaUsada() << endl;
    if(this->getMemoriaUsada()>this->getMemoriaTotal()){
        cout<<"Não é possível ter mais memória usada do que disponível para uso! O computador não foi iniciado"<<endl;
        exit(-1);
    }else{
        cout << "Memoria ram: " << this->getMemoriaRam()<< endl;
    }
    cout << "Modelo do processador: " << this->getModeloProcessador() << endl;
    cout << "Cor do gabinete: " << this->getCor() << endl;
    if (this->getLigado() == true)
        cout << "O computador esta ligado!\n\n";
    else
        cout << "O computador esta desligado!\n\n";

}
