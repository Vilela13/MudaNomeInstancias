#include <sstream>

#include <iostream>     // Biblioteca padrão de c++
#include <istream>      // Biblioteca padrão de c++
#include <list>         // Biblioteca que contem a estrutura listas
#include <string>       // Biblioteca que contem a estrutura string ( vetor de caracteres)
#include <fstream>      // Biblioteca que contem a estrutura para acessar arquivos txt
#include <vector>       // Biblioteca que contem a estrutura Vector

#include <stdio.h>      // Biblioteca padão de C, principalmente a operações de entrada e saída
#include <stdlib.h>     // Biblioteca padão de C, possui funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <string.h>
#include <cstring>


using namespace std;

void EscreveNomeArquivos(){
    ofstream AqruivoSaida1;
    ofstream AqruivoSaida2;
    AqruivoSaida1.open("NomeInstancias.txt");
    AqruivoSaida2.open("NomeMudadoInstancias.txt");

// C101
    for(int i = 101; i < 110; i++){
        AqruivoSaida1 << "C" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-C" << i << ".txt"<< endl;
    }

// C201
    for(int i = 201; i < 209; i++){
        AqruivoSaida1 << "C" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-C" << i << ".txt"<< endl;
    }

// R101
    for(int i = 101; i < 113; i++){
        AqruivoSaida1 << "R" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-R" << i << ".txt"<< endl;
    }

// R201
    for(int i = 201; i < 212; i++){
        AqruivoSaida1 << "R" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-R" << i << ".txt"<< endl;
    }

// RC101
    for(int i = 101; i < 109; i++){
        AqruivoSaida1 << "RC" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-RC" << i << ".txt"<< endl;
    }

// RC201
    for(int i = 201; i < 209; i++){
        AqruivoSaida1 << "RC" << i << ".txt"<< endl;
        AqruivoSaida2 << "p-RC" << i << ".txt"<< endl;
    }

    AqruivoSaida1 << "EOF";
    AqruivoSaida2 << "EOF";

    AqruivoSaida1.close();
    AqruivoSaida2.close();



}

int main(){

	ifstream ArquivoNomeInstancias;
	ifstream ArquivoEntrada;
	ofstream AqruivoSaida;

	char *a;
	char *b;
	char *c;
	list<char*> ListaInstancias;
	string Nome1;
	string Nome2;

	string Linha;

	list<char*>::iterator it;

	EscreveNomeArquivos();

	ArquivoNomeInstancias.open("NomeInstancias.txt");
	ArquivoNomeInstancias >> Nome1;
	while( Nome1 != "EOF"){
		a = new char[Nome1.size()+1];
		a[Nome1.size()]=0;
		memcpy(a,Nome1.c_str(),Nome1.size());
		//cout << a  << endl ;
		ListaInstancias.push_back(a);
		ArquivoNomeInstancias >> Nome1;
	}

	FILE *fp1;

	while( ListaInstancias.size() > 0){
		it = ListaInstancias.begin();
		a = *it;
		ListaInstancias.pop_front();

        Nome1 = "./ArqMudNome/p-";               // Aqui se coloca onde se quer colocar os arquivos, tomar cuidado com caminhos muito longos
        b = new char[Nome1.size()+1];
        b[Nome1.size()]=0;
        memcpy(b,Nome1.c_str(),Nome1.size());
        strcat(b,a);

        Nome2 = "./InstPeq/";
        c = new char[Nome2.size()+1];
        c[Nome2.size()]=0;
        memcpy(c,Nome2.c_str(),Nome2.size());
        strcat(c,a);

        cout << endl << c << endl << b << endl << ListaInstancias.size() << endl ;



        //fp1 = fopen (b, "w");

        //cout << "final";

        ArquivoEntrada.open(c);
        AqruivoSaida.open(b);



        //cout << endl << a << endl << endl;

        getline(ArquivoEntrada,Linha);
        //cout << Linha;


        while( ArquivoEntrada.good() ){
            //cout << Linha << endl;
            AqruivoSaida << Linha;
            getline(ArquivoEntrada,Linha);
        }


        ArquivoEntrada.close();
        AqruivoSaida.close();



    }




    //fclose(fp1);






}
