#include <iostream>
#include <locale>
#include <list>
#include <string>
using namespace std;

struct Itens
{
	string nome, dono, magia;
	int id, raridade;
};

list <Itens> itens;

void InserirItem()
{
	string nome, dono, magia;
	int id, raridade;
	
	cout << "Nome do Item: "; getline(cin >> ws, nome);
	cout << "Nome do Dono: "; getline(cin >> ws, dono);
	cout << "Propriedade magica: "; getline(cin >> ws, magia);
	cout << "Numero de Identidade: "; cin >> id;
	cout << "Raridade do Item: "; cin >> raridade;
	itens.push_back({nome, dono, magia, id, raridade});
	cout << endl;
	
	list<Itens>::iterator it;
	
	for(it = itens.begin(); it != itens.end(); it++)
	{
		cout << it->nome << endl;
		cout << it->dono << endl;
		cout << it->magia << endl;
		cout << it->id << endl;
		cout << it->raridade << endl;
	}
}
void Cadastro()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void Buscar()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void Verificar()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void ListarNome()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void ListarRaridade()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void ContarItens()
{
	cout << "Funcionalidade em contruçao" << endl;
}
void RemoverItens()
{
	cout << "Funcionalidade em contruçao" << endl;
}



int main()
{
	int x;
	setlocale(LC_ALL, "");
	
	while(true)
	{
		cout << endl;
		cout << "[1] - inserir item" << endl;
		cout << "[2] - cadastrar similaridades entre itens" << endl;
		cout << "[3] - buscar itens similares" << endl;
		cout << "[4] - verificar a existencia de um item" << endl;
		cout << "[5] - listar itens (por ordem alfabetica de nome)" << endl;
		cout << "[6] - listar itens (por ordem decrescente de raridade)" << endl;
		cout << "[7] - contar itens com a mesma propriedade magica" << endl;
		cout << "[8] - remover itens menos raros" << endl;
		cout << "[0] - sair" << endl;
		cout << endl;
		cout << "Insira opção desejada: ";
		cin >> x; cout << endl;
		
		switch(x)
		{
			case 1:
				InserirItem();
				break;
			case 2:
				Cadastro();
				break;
			case 3:
				Buscar();
				break;
			case 4:
				Verificar();
				break;
			case 5:
				ListarNome();
				break;
			case 6:
				ListarRaridade();
				break;
			case 7:
				ContarItens();
				break;
			case 8:
				RemoverItens();
				break;
			case 0:
				return 0;
			default:
				cout << "opção invalida" << endl;;
		}
	}
	
	return 0;
}
