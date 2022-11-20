#pragma once

#include "Funcionario.h"

class Presidente : public Funcionario{
    public:
        Presidente();
        Presidente(string c, string nom, string ende, string tel, string date, float sal,string areaFom, string areaMax);
        string exibeFuncionario();

    private:
        string areaFormacao;
        string formacaoMax;
};
