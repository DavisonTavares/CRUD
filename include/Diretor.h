#pragma once

#include "Funcionario.h"

class Diretor : public Funcionario{
    public:
        Diretor();
        Diretor(string c, string nom, string ende, string tel, string date, float sal,string supervisoa, string area);
        string exibeFuncionario();

    private:
        string nomeSupervisao;
        string areaFormacao;
};
