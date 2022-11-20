#include "Presidente.h"

Presidente::Presidente() : Funcionario(3){

}

Presidente::Presidente(string c, string nom, string ende, string tel, string date, float sal,string areaFom, string areaMax) : Funcionario(3){
    Funcionario::setAtributos(c, nom, ende, tel, date, sal);
    areaFormacao = areaFom;
    formacaoMax = areaMax;
}

/*Presidente::~Presidente()
{
    //dtor
}*/


string Presidente::exibeFuncionario(){
    string data = Funcionario::exibeFuncionario();
    data += areaFormacao + "\n" + formacaoMax + "\n";
    return data;
}
