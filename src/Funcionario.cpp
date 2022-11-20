#include "Funcionario.h"

Funcionario::Funcionario(unsigned short int designacao){
    if(designacao >= 1 && designacao <= 3)
        this->designacao = designacao;

    else
        this->designacao = 0;

}

void Funcionario::setAtributos(string c, string nom, string ende, string tel, string date, float sal, unsigned short int des){
    cod = c;
    nome = nom;
    endereco = ende;
    telefone = tel;
    dataIngresso = date;
    salario = sal;

    if(des){
        designacao = des;
    }

}

void Funcionario::adicionaAtributos(){
    cout << "Nome: ";
    getline(cin, nome);
    cout << "\nEndereco: ";
    getline(cin, endereco);
    cout << "\nTelefone: ";
    getline(cin, telefone);
    cout << "\nData de ingresso: ";
    getline(cin, dataIngresso);
    cout << "\nSalario: ";
    cin >> salario;
    cin.ignore();
}

/*
void Funcionario::editaAtributos(string c, string d, string n, string e, string t, unsigned short int des, float s){
    cod = c;
    nome = nom;
    endereco = ende;
    telefone = tel;
    dataIngresso = date;
    salario = sal;
    designacao = des;

}
*/

string Funcionario::exibeFuncionario(){
    string data = to_string(designacao) + "\n"+ cod + "\n"+  nome + "\n" + endereco + "\n" + telefone + "\n" + dataIngresso + "\n" + to_string(salario) + "\n";
    return data;
}

void Funcionario::exibeListaFuncionarios(){

}

void Funcionario::exibeListaFuncionariosTipo(){

}
string Funcionario::getCod(){
    return cod;
}
int Funcionario::getTipo(){
    return designacao;
}
