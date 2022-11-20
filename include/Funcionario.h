#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Funcionario{
    public:
        Funcionario(unsigned short int designacao);
        void setAtributos(string cod, string nom, string ende, string tel, string date, float sal, unsigned short int des = 0);
        virtual void adicionaAtributos();
        //virtual void editaAtributos(string c, string d, string n, string e, string t, unsigned short int des, float s);
        virtual string exibeFuncionario();
        virtual void exibeListaFuncionarios();
        virtual void exibeListaFuncionariosTipo();
        string getCod();
        int getTipo();

    protected:
        string cod;
        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        unsigned short int designacao;
        float salario;
};
