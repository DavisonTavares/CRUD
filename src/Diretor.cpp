#include "Diretor.h"

Diretor::Diretor() : Funcionario(2){

}

Diretor::Diretor(string c, string nom, string ende, string tel, string date, float sal,string supervisoa, string area) : Funcionario(2){
    Funcionario::setAtributos(c, nom, ende, tel, date, sal);
    nomeSupervisao = supervisoa;
    areaFormacao = area;
}

string Diretor::exibeFuncionario(){
    string data = Funcionario::exibeFuncionario();
    data += nomeSupervisao +"\n" + areaFormacao +"\n";
    return data;
}
