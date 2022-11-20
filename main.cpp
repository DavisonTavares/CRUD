#include "Funcionario.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Gerente.h"
#include "GerenciaFuncionarios.h"
#include <fstream>

void menu(){
    system("cls");
    cout << "|-------------------------------------------------|\n";
    cout << "|            Genrencia Tech LTDA                  |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "|                                                 |\n";
    cout << "|               MENU DE OPCOES                    |\n";
    cout << "|                                                 |\n";
    cout << "|           01  LISTAR FUNCIONARIOS               |\n";
    cout << "|           02  LISTAR FUNCIONARIO POR TIPO       |\n";
    cout << "|           03  BUSCAR FUNCIONARIO POR CODIGO     |\n";
    cout << "|           04  ADICIONAR FUNCIONARIOS            |\n";
    cout << "|           05  DEMITIR FUNCIONARIOS              |\n";
    cout << "|           06  EDITAR FUNCIONARIOS               |\n";
    cout << "|           07  SAIR E SALVAR FUNCIONARIOS        |\n";
    cout << "|                                                 |\n";
    cout << "|-------------------------------------------------|\n";
}
void addFuncionario(GerenciaFuncionarios &gerfunc){
    int opcaoMenu;
    string nome;
    string endereco;
    string telefone;
    string dataIngresso;
    string nomeSupervisao;
    string areaFormacao;
    string formacaoMax;
    string cod;
    float salario;

    system("cls");
    cout << "|-------------------------------------------------|\n";
    cout << "|            Genrencia Tech LTDA                  |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "|                                                 |\n";
    cout << "|               MENU DE OPCOES                    |\n";
    cout << "|                                                 |\n";
    cout << "|                01  GERENTE                      |\n";
    cout << "|                02  DIRETOR                      |\n";
    cout << "|                03  PRESIDENTE                   |\n";
    cout << "|                04  VOLTAR                       |\n";
    cout << "|                                                 |\n";
    cout << "|-------------------------------------------------|\n";
    cout << endl << "OPCAO: ";
    cin >> opcaoMenu;
    cin.ignore();
    system("cls");
    if(opcaoMenu == 4){
        return;
    }
    cout << "Codigo: ";
    getline(cin, cod);
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

    switch(opcaoMenu){
        case 1:
            cout << "\nSupervisao: ";
            getline(cin, nomeSupervisao);
            gerfunc.adicionaFuncionario(new Gerente(cod, nome, endereco, telefone, dataIngresso, salario, nomeSupervisao));
            break;

        case 2:
            cout << "\nSupervisao: ";
            getline(cin, nomeSupervisao);
            cout << "\nArea de Formacao: ";
            getline(cin, areaFormacao);
            gerfunc.adicionaFuncionario(new Diretor(cod, nome, endereco, telefone, dataIngresso, salario, nomeSupervisao, areaFormacao));
            break;

        case 3:
            cout << "\nArea de Formacao: ";
            getline(cin, areaFormacao);
            cout << "\nFormacao academica maxima: ";
            getline(cin, formacaoMax);
            gerfunc.adicionaFuncionario(new Presidente(cod, nome, endereco, telefone, dataIngresso, salario, areaFormacao, formacaoMax));
            break;
    }

}

int main(){
    GerenciaFuncionarios gerfunc;
    string deletFuncionario, data;
    string nome, endereco, telefone, dataIngresso, supervisao, salario, areaFormacao, areaFormMax, cod;
    unsigned short int designacao;
    fstream fp;
    int opcaoMenu, id = 0;
    float salarioFloat;
    string confirmar;

    vector<Funcionario*> funcionarios;

    fp.open("funcionarios.txt", fstream::in);
    if(!fp.is_open()){
        cout << "Não foi possivel abrir o arquivo\n";
        return 1;
    }

    while(1){
        fp >> designacao;
        if(fp.eof()){
            fp.close();
            break;
        }

        fp.ignore();
        getline(fp, cod);
        getline(fp, nome);
        getline(fp, endereco);
        getline(fp, telefone);
        getline(fp, dataIngresso);
        getline(fp, salario);

        if(designacao == 1){
            getline(fp, supervisao);
            gerfunc.adicionaFuncionario(new Gerente(cod, nome, endereco, telefone, dataIngresso, stof(salario), supervisao));
        }
        if(designacao == 2){
            getline(fp, supervisao);
            getline(fp, areaFormacao);
            gerfunc.adicionaFuncionario(new Diretor(cod, nome, endereco, telefone, dataIngresso, stof(salario), supervisao, areaFormacao));
        }
        if(designacao == 3){
            getline(fp, supervisao);
            getline(fp, areaFormMax);
            gerfunc.adicionaFuncionario(new Presidente(cod, nome, endereco, telefone, dataIngresso, stof(salario), supervisao, areaFormMax));
        }
    }


    while(id != -10){
        menu();
        cin >> opcaoMenu;
        switch(opcaoMenu){
            case 1:
                system("cls");
                funcionarios = gerfunc.listFuncionario();
                for(int x = 0; x < funcionarios.size(); x++){
                    cout << "\nFuncionario ";
                    cout << (x + 1) << endl;
                    cout << funcionarios[x]->exibeFuncionario();
                }
                system("pause");
                break;

            case 2:
                system("cls");
                cout << "QUAL TIPO VOCE QUER EXIBIR?\n";
                cout << "1 GERENTE\n";
                cout << "2 DIRETOR\n";
                cout << "3 PRESIDENTE\n";
                cout << "OPCAO: ";
                cin >> opcaoMenu;
                cout << endl;
                system("cls");
                gerfunc.buscaFuncionario(opcaoMenu);
                system("pause");
                break;

            case 3:
                system("cls");
                cin >> nome;
                cout << gerfunc.localizarFuncionario(nome);
                system("pause");
                break;

            case 4:
                addFuncionario(gerfunc);
                system("cls");
                break;

            case 5:{
                cin >> nome;
                string func = gerfunc.localizarFuncionario(nome);
                if(!func.size()){
                    system("cls");
                    cout << "Não foi possivel localizar o funcionario\n";
                    break;
                }
                cout << "Funcionario:"<<endl<<func<<endl;
                cout << "Você tem certeza que quer demitir S/n?";
                cin >> deletFuncionario;
                if(deletFuncionario == "S" || deletFuncionario == "s"){
                    if(gerfunc.demitirFuncionario()){
                        system("cls");
                        cout << "\nFuncionario removido com sucesso!\n";
                        break;
                    }
                    system("cls");
                    cout << "\nNão é possivel demitir o funcionario!\n\n";
                }
                break;
            }

            case 6:{
                system("cls");
                cout << "Digite o codigo do funcionario: ";
                cin >> cod;
                string funcionario = gerfunc.localizarFuncionario(cod);
                system("cls");
                if(!funcionario.size()){
                    system("cls");
                    cout << "Código inválido";
                    break;
                }

                if(funcionario.size()){
                    cout << "Codigo: ";
                    cin >> cod;
                    cin.ignore();
                    cout << cod;
                    cout << "\nNome: ";
                    getline(cin, nome);
                    cout << "\nEndereco: ";
                    getline(cin, endereco);
                    cout << "\nTelefone: ";
                    getline(cin, telefone);
                    cout << "\nData de ingresso: ";
                    getline(cin, dataIngresso);
                    cout << "\nSalario: ";
                    cin >> salarioFloat;
                    cout << "\nDesignacao: ";
                    cin >> designacao;
                    cin.ignore();
                    gerfunc.editaAtributos(cod, dataIngresso, nome, endereco, telefone, designacao, salarioFloat);
                }
                system("cls");
                break;
            }

            case 7:
                gerfunc.salvarFuncionarios(fp);
                id = -10;
                break;
        }
    }

    return 0;
}
