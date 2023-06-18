#include <iostream>
#include <fstream>
#include <limits>
#include <Windows.h>
using namespace std;

struct pessoa{
	string nome;
	string cpf;
	string tipoSanguineo;
	int porcentVermelho;
	int porcentBranco;
    float densidade;
};


int cadastro(fstream& arquivo, pessoa cadastros[]){
    string lixo;

    cout << "** Homogramas Cadastrados **" << endl;
    for(int i=0; i<5; i++){
        getline(arquivo, cadastros[i].nome, ';');
        getline(arquivo, cadastros[i].cpf, ';');
        getline(arquivo, cadastros[i].tipoSanguineo, ';');
        arquivo >> cadastros[i].porcentVermelho;
        arquivo >> lixo;
        arquivo >> cadastros[i].porcentBranco;
        arquivo >> lixo;
        arquivo >> cadastros[i].densidade;
        arquivo.ignore();

        cout << cadastros[i].nome << endl;
        cout << cadastros[i].cpf << endl;
        cout << cadastros[i].tipoSanguineo << endl;
        cout << cadastros[i].porcentVermelho << "%" << endl;
        cout << cadastros[i].porcentBranco << "%" << endl;
        cout << cadastros[i].densidade << endl;
        cout << endl;
    }

    return 0;
}


void cadastrarNovaPessoa(fstream& arquivoOut) {
    pessoa novaPessoa;

    cout << "** CADASTRO DE PESSOA **" << endl;
    cout << "Nome: " << endl;
    getline(cin, novaPessoa.nome);
    cout << "CPF: " << endl;
    getline(cin, novaPessoa.cpf);
    cout << "Tipo Sanguineo: "<< endl;
    getline(cin, novaPessoa.tipoSanguineo);
    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin>> novaPessoa.porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> novaPessoa.porcentBranco;
    cout << "Densidade do sangue: " << endl;
    cin >> novaPessoa.densidade;


    arquivoOut.open("output/animais_exoticos.txt", ios::out | ios::app);

    if (!arquivoOut) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    arquivoOut << novaPessoa.nome << " " << novaPessoa.cpf << " " << novaPessoa.tipoSanguineo<< " " << novaPessoa.porcentVermelho << " " << novaPessoa.porcentBranco << " " << novaPessoa.densidade<< endl;
    arquivoOut.close();
    cout << "Cadastro realizado!" << endl;
}


void buscarpessoa(fstream& arquivo, pessoa nomeProcurado[]){
	bool encontrar = false;
    int indice;
	string nome;
	cout<< "Digite o nome da pessoa: ";
	cin>> nome;

    for(int i=0; i<5; i++){
        while ((!encontrar) and (arquivo >> nomeProcurado[i].nome >> nomeProcurado[i].cpf >> nomeProcurado[i].tipoSanguineo >> nomeProcurado[i].porcentVermelho >> nomeProcurado[i].porcentBranco >> nomeProcurado[i].densidade)) {
            cout << "Lendo pessoa: " << nomeProcurado[i].nome << endl;
            if (nomeProcurado[i].nome == nome) {
                encontrar = true;
                indice = i;
            } 
            
        }
    }

	if (encontrar){
		cout << "** PESSOA ENCONTRADA **" << endl;
        cout << "Nome: " << nomeProcurado[indice].nome << endl;
        cout << "CPF: " << nomeProcurado[indice].cpf << endl;
        cout << "Tipo Sanguineo: " << nomeProcurado[indice].tipoSanguineo << endl;
        cout << "Porcentagem Globulos Vermelhos: " << nomeProcurado[indice].porcentVermelho <<"%"<< endl;
        cout << "Porcentagem Globulos Brancos: " << nomeProcurado[indice].porcentBranco <<"%"<< endl;
        cout << "Densidade do Sangue: " << nomeProcurado[indice].densidade << endl;
	}
	else{
		cout << endl << "Pessoa não encontrada" << endl;
	}

}


void alterarpessoa(fstream& arquivo, pessoa nomeParaTrocar[]){
	bool encontrar = false;
    int indice;
	string cpf;
	cout<< "Digite o CPF do paciente a ser alterado: ";
	cin>> cpf;

    for(int i=0; i<5; i++){
        while(!encontrar and (arquivo >> nomeParaTrocar[i].nome >> nomeParaTrocar[i].cpf >> nomeParaTrocar[i].tipoSanguineo >> nomeParaTrocar[i].porcentVermelho >> nomeParaTrocar[i].porcentBranco)){
            if(nomeParaTrocar[i].cpf == cpf){
                encontrar=true;
                indice = i;
            }
        }
    }
	if (encontrar){
		cout << "PESSOA ENCONTRADA" << endl;
        cout << "Nome: " << nomeParaTrocar[indice].nome << endl;
        cout << "CPF: " << nomeParaTrocar[indice].cpf << endl;
        cout << "Tipo Sanguineo: " << nomeParaTrocar[indice].tipoSanguineo << endl;
        cout << "Porcentagem de Globulos Vermelhos: " << nomeParaTrocar[indice].porcentVermelho <<"%" << endl;
        cout << "Porcentagem de Globulos Brancos: " << nomeParaTrocar[indice].porcentBranco <<"%"<<  endl;
        cout << "Densidade do Sangue: " << nomeParaTrocar[indice].densidade << endl;
	}


    cout << "** ALTERAÇÃO DE HeMOGRAMA **" << endl;
    cout << "Nome: " << endl;
    getline(cin, nomeParaTrocar[indice].nome);
    cout << "CPF: ";
    getline(cin, nomeParaTrocar[indice].cpf);
    cout << "Tipo Sanguineo: "<< endl;
    cin.ignore();
    getline(cin, nomeParaTrocar[indice].tipoSanguineo);
    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin>> nomeParaTrocar[indice].porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> nomeParaTrocar[indice].porcentBranco;
    cout << "Densidade do sangue: " << endl;
    cin >> nomeParaTrocar[indice].densidade;

}


void excluirpessoa(fstream& arquivo, pessoa cadastros[]){

}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    fstream arquivo("animais_exoticos.txt");
    pessoa cadastros[5];

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }else {
        cadastro(arquivo, cadastros);
    }

    int opcao;
    do {
        cout << "** CADASTRO DE HOMOGRAMA **" << endl;
        cout << "1. Cadastrar nova pessoa" << endl;
        cout << "2. Buscar pessoa" << endl;
        cout << "3. Alterar dados de uma pessoa" << endl;
        cout << "4. Excluir dados de uma pessoa" << endl;
	    cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarNovaPessoa(arquivo);
                break;
            case 2:
                buscarpessoa(arquivo, cadastros);
                break;
            case 3:
                alterarpessoa(arquivo, cadastros);
                break;
            case 4:
                excluirpessoa(arquivo, cadastros);
                break;
            case 5:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Digite novamente." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 5);

    arquivo.close();

    return 0;
}
