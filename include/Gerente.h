#pragma once

#include "Funcionario.h"

class Gerente : public Funcionario{
    public:
        Gerente();
        Gerente(string c, string nom, string ende, string tel, string date, float sal, string super);
        //virtual ~Gerente();
        string exibeFuncionario();

    private:
        string nomeSupervisao;
};
