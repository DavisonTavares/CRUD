#include "GerenciaFuncionarios.h"
static int id;
GerenciaFuncionarios::GerenciaFuncionarios(){
}

GerenciaFuncionarios::~GerenciaFuncionarios(){
    for(int i = 0; i < funcionarios.size(); i++){
        delete funcionarios[i];
    }
    funcionarios.clear();
}

void GerenciaFuncionarios::adicionaFuncionario(Funcionario *func){
    funcionarios.push_back(func);
}

void GerenciaFuncionarios::buscaFuncionario(int busca){
    for(int i = 0; i < funcionarios.size(); i++){
        if(funcionarios[i]->getTipo() == busca)
            cout<<funcionarios[i]->exibeFuncionario();
    }
}

void GerenciaFuncionarios::salvarFuncionarios(fstream &fp){
    string data;
    for(int x = 0; x < funcionarios.size(); x++){
        data += funcionarios[x]->exibeFuncionario();
    }
    fp.open("funcionarios.txt", fstream::out);
    fp.write(data.c_str(), data.size());
    fp.close();
}

void GerenciaFuncionarios::editaAtributos(string c, string d, string n, string e, string t, unsigned short int des, float s){
    funcionarios[id]->setAtributos(c, n, e, t, d, s, des);

}

int GerenciaFuncionarios::demitirFuncionario(){
    if(funcionarios[(id)]->getTipo()==1){
        funcionarios.erase(funcionarios.begin()+id);
        return 1;
    }
    return 0;
}

string GerenciaFuncionarios::localizarFuncionario(string nome){
    for(int x = 0; x < funcionarios.size(); x++){
        if(funcionarios[x]->getCod().find(nome) == 0){
            id = (x);
            return funcionarios[x]->exibeFuncionario();
        }
    }
    return "";
}
vector<Funcionario*> GerenciaFuncionarios::listFuncionario(){
    return this->funcionarios;
}
