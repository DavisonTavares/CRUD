#pragma once

#include "Funcionario.h"
#include <fstream>

class GerenciaFuncionarios{
    public:
        GerenciaFuncionarios();
        virtual ~GerenciaFuncionarios();
        void adicionaFuncionario(Funcionario *func);
        void buscaFuncionario(int busca);
        void salvarFuncionarios(fstream &fp);
        void editaAtributos(string c, string d, string n, string e, string t, unsigned short int des, float s);

        int demitirFuncionario();
        string localizarFuncionario(string cod);
        vector<Funcionario*> listFuncionario();

    private:
        vector<Funcionario*> funcionarios;
};
