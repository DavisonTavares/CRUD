#include "Gerente.h"

Gerente::Gerente() : Funcionario(1){

}


Gerente::Gerente(string c, string nom, string ende, string tel, string date, float sal, string super) : Funcionario(1){
    Funcionario::setAtributos(c, nom, ende, tel, date, sal);
    nomeSupervisao = super;
}


string Gerente::exibeFuncionario(){
    string data = Funcionario::exibeFuncionario();
    data += nomeSupervisao+"\n";
    return data;
}

