#include <iostream>
#include <fstream>
#include <locale> //biblioteca com acentos

using namespace std;

struct pessoa{
	string nome;
	string cpf;
	string tipoSanguineo;
	int porcentVermelho;
	int porcentBranco;
    float densidade;
};

//Armazena os dados do arquivo no registro
int cadastro(fstream& arquivo, pessoa cadastros[], int tam){
    char lixo;
    string lixao;


    cout << "** Hemogramas Cadastrados **" << endl;
    getline(arquivo, lixao);
    for(int i=0; i<tam-1; i++){
        if(not(getline(arquivo, cadastros[i].nome, ';'))){
            cout << "Erro na entrada do nome. Linha " << i << endl;
        }
        if(not(getline(arquivo, cadastros[i].cpf, ';')))
            cout << "Erro na entrada do CPF. Linha " << i << endl;
        if(not(getline(arquivo, cadastros[i].tipoSanguineo, ';')))
            cout << "Erro na entrada do tipo sanguíneo. Linha " << i << endl;
        if(not(arquivo >> cadastros[i].porcentVermelho))
            cout << "Erro na entrada da porcentagem de glóbulos vermelhos. Linha " << i << endl;
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].porcentBranco))
            cout << "Erro na entrada da porcentagem de glóbulos brancos. Linha " << i << endl;
        arquivo >> lixo;
        if(not(arquivo >> cadastros[i].densidade))
            cout << "Erro na entrada da densidade do sangue. Linha " << i << endl;
        arquivo.ignore();
    }
    return 0;
}
//Mostra todos os Dados cadastrados
void mostrartodosdados(pessoa cadastros[], bool& continuar, int tam){

    cout << "** Hemogramas Cadastrados **" << endl;

    for(int i=0; i<tam-1; i++) {
    // Exibe os dados na tela
        cout << cadastros[i].nome << endl;
        cout << cadastros[i].cpf << endl;
        cout << cadastros[i].tipoSanguineo << endl;
        cout << cadastros[i].porcentVermelho << "%" << endl;
        cout << cadastros[i].porcentBranco << "%" << endl;
        cout << cadastros[i].densidade << endl;
        cout << endl;
    }
}
//Cadastra dados de uma nova pessoa
void cadastrarNovaPessoa(bool& continuar, int& linhas, pessoa cadastros[]) {
    pessoa novaPessoa;

    cout << " CADASTRO DE PESSOA " << endl;
    cout << "Nome: " << endl;
    cin.ignore();
    getline(cin, novaPessoa.nome);
    cout << "CPF: " << endl;
    getline(cin, novaPessoa.cpf);
    if (novaPessoa.cpf.length() != 11) {
        cout << "O CPF deve conter 11 números." << endl;
        return;
    }
    cout << "Tipo Sanguineo: "<< endl;
    getline(cin, novaPessoa.tipoSanguineo);
    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin>> novaPessoa.porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> novaPessoa.porcentBranco;
    if (novaPessoa.porcentVermelho + novaPessoa.porcentBranco != 100) {
        cout << "A soma das porcentagens de glóbulos vermelhos e brancos deve ser igual a 100%." << endl;
        return;
    }

    cout << "Densidade do sangue: " << endl;
    cin >> novaPessoa.densidade;

    ofstream arquivo("Teste.csv", ios::app); 
    if (arquivo.is_open()) {
        arquivo << endl << novaPessoa.nome << ";"
         << novaPessoa.cpf << ";"
         << novaPessoa.tipoSanguineo << ";"
         << novaPessoa.porcentVermelho << ";"
         << novaPessoa.porcentBranco << ";"
         << novaPessoa.densidade;
    }
        arquivo.close();


    
    cadastros[linhas-1].nome = novaPessoa.nome;
    cadastros[linhas-1].cpf = novaPessoa.cpf;
    cadastros[linhas-1].tipoSanguineo = novaPessoa.tipoSanguineo;
    cadastros[linhas-1].porcentVermelho = novaPessoa.porcentVermelho;
    cadastros[linhas-1].porcentBranco = novaPessoa.porcentBranco;
    cadastros[linhas-1].densidade = novaPessoa.densidade;

    linhas++;
    cout << endl << "Cadastro realizado!" << endl;

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
        cin >> continua;
        if (continua == "sim"){
            continuar = true;
        } else {
            continuar = false;
        }
}

//Busca os dados de uma pessoa pelo CPF
void buscarpessoa(pessoa nomeProcurado[], bool& continuar, int linhas){
	bool encontrar = false;
    int indice;
	string cpf;
	cout<< "Digite o cpf da pessoa, sem espaços e pontos:";
	cin>> cpf;

    cout << "Buscando CPF... " << endl;
    for(int i=0; i<linhas and !encontrar; i++){
        if(cpf == nomeProcurado[i].cpf){
            encontrar = true;
            indice = i;
        }
    }
    if (encontrar) {
		cout << "** PESSOA ENCONTRADA **" << endl;
        cout << "Nome: " << nomeProcurado[indice].nome << endl;
        cout << "CPF: " << nomeProcurado[indice].cpf << endl;
        cout << "Tipo Sanguineo: " << nomeProcurado[indice].tipoSanguineo << endl;
        cout << "Porcentagem Globulos Vermelhos: " << nomeProcurado[indice].porcentVermelho <<"%"<< endl;
        cout << "Porcentagem Globulos Brancos: " << nomeProcurado[indice].porcentBranco <<"%"<< endl;
        cout << "Densidade do Sangue: " << nomeProcurado[indice].densidade << endl;    
    } else {
        cout << endl << "Pessoa não encontrada" << endl;
    }

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
	cin >> continua;
	if (continua == "sim"){
		continuar = true;
	} else {
		continuar = false;
	}

}

//Altera os dados de alguma pessoa escolhida pelo usuário
void alterarpessoa(pessoa nomeParaTrocar[], bool& continuar){
	bool encontrar = false;
    int indice = 0;
	string cpf;
	cout<< "Digite o CPF do paciente a ser alterado: ";
	cin>> cpf;
    cout<<endl;

    for(int i=0; i<5 and !encontrar; i++){
        if(cpf == nomeParaTrocar[i].cpf){
            encontrar = true;
            indice = i;
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
	}cout<<endl;


    cout << "** ALTERAÇÃO DE HEMOGRAMA **" << endl;
    cout << "Nome: " << endl;
    cin.ignore();
    getline(cin, nomeParaTrocar[indice].nome);
    cout << "CPF: " << endl;
    getline(cin, nomeParaTrocar[indice].cpf);
    cout << "Tipo Sanguineo: " << endl;
    cin.ignore();
    getline(cin, nomeParaTrocar[indice].tipoSanguineo);
    cout << "Porcentagem de Globulos Vermelhos: " << endl;
    cin>> nomeParaTrocar[indice].porcentVermelho;
    cout << "Porcentagem de Globulos Brancos: " << endl;
    cin >> nomeParaTrocar[indice].porcentBranco;
    cout << "Densidade do sangue: " << endl;
    cin >> nomeParaTrocar[indice].densidade;

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
	cin >> continua;
	if (continua == "sim"){
		continuar = true;
	} else {
		continuar = false;
	}

}

//Exclui os dados de uma pessoa escolhida pelo usuário
void excluirpessoa(pessoa nomeProcurado[], bool& continuar, int linhas){

    bool encontrar = false;
    int indice;
	string cpf;
	cout<< "Digite o cpf da pessoa que você deseja excluir, sem espaços e pontos:";
	cin>> cpf;

    cout << "Apagando pessoa... " << endl;
    for(int i=0; i<linhas and !encontrar; i++){
        if(cpf == nomeProcurado[i].cpf){
            encontrar = true;
            indice = i;
        }
    }
    if (encontrar) {
		cout << "** PESSOA APAGADA **" << endl;
        nomeProcurado[indice].nome = " ";
        nomeProcurado[indice].cpf = " ";
        nomeProcurado[indice].tipoSanguineo = " ";
        nomeProcurado[indice].porcentVermelho = 0;
        nomeProcurado[indice].porcentBranco = 0;
        nomeProcurado[indice].densidade = 0;    
    } else {
        cout << endl << "Pessoa não encontrada" << endl;
    }

    string continua;
    cout << "deseja continuar?(responda com sim ou não)"<<endl;
	cin >> continua;
	if (continua == "sim"){
		continuar = true;
	} else {
		continuar = false;
	}
}


int main() {
    //Coloca acentos no terminal(Apenas em Windows)
    setlocale(LC_ALL, "pt_BR.UTF-8");

    pessoa cadastros [150];
    
    //As linhas 250-263 contam quantas linhas há no arquivo
    int linhas = 0;
    ifstream in("Teste.csv");
    string unused;
    while ( getline(in, unused) ){
        linhas++;
    }
    fstream arquivo("Teste.csv");

    
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }else {
        cadastro(arquivo, cadastros, linhas);
    }

    

    int opcao;
    bool continuar = true;
    while (continuar) { //A variavel continuar pode ser alterada em cada um dos subprogramas acessados pelo usuário, de forma que ele possa escolher se deseja continuar utilizando o programa
		for(int i=0; i <=1; i++){ //Esse "for" garante que as opções só serão repetidas uma vez
            cout << "** CADASTRO DE HEMOGRAMA **" << endl;
            cout << "1. Cadastrar nova pessoa" << endl;
            cout << "2. Buscar pessoa" << endl;
            cout << "3. Alterar dados de uma pessoa" << endl;
            cout << "4. Excluir uma pessoa" << endl;
            cout << "5. Mostrar todos os dados" << endl;
            cout << "6. Sair" << endl;
            cout << "Digite a opção desejada: ";
            cin >> opcao;

            switch(opcao) {
                case 1:
                    cadastrarNovaPessoa(continuar, linhas, cadastros);
                    break;
                case 2:
                    buscarpessoa(cadastros, continuar, linhas);
                    break;
                case 3:
                    alterarpessoa(cadastros, continuar);
                    break;
                case 4:
                    excluirpessoa(cadastros, continuar, linhas);
                    break;
                case 5:
                    mostrartodosdados(cadastros, continuar, linhas);
                    break;
                case 6:
                    cout << "Programa encerrado" << endl;
                    return 0;
                default:
                    cout << "Opção inválida" << endl;
                    break;
            }
            if (!continuar){
                    cout<<"Saindo do programa..."<<endl;
                    return 0;
                }
            cout << endl;
        }
    }
    

    arquivo.close();

    return 0;
}
