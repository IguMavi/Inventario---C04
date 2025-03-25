#include <iostream>
#include <locale>
#include <string>
#include <list>
using namespace std;

struct Itens
{
	string nome, dono, magia;
	int id, raridade;
};

struct Similaridade
{
	int	origem, destino, peso;	
};

list <Similaridade> similarens[999999];
list<Similaridade>::iterator ti;
list<Itens>::iterator it;
list <Itens> itens;
string N[99999];

void InserirItem()
{
	string nome, dono, magia;
	int id, raridade, i = 0;
	
	cout << "Nome do Item: "; getline(cin >> ws, nome);
	cout << "Nome do Dono: "; getline(cin >> ws, dono);
	cout << "Propriedade magica: "; getline(cin >> ws, magia);
	cout << "Numero de Identidade: "; cin >> id;
	cout << "Raridade do Item (0-100): "; cin >> raridade;
	itens.push_back({nome, dono, magia, id, raridade});
	cout << endl;
	N[i] = nome;
	i++;
}

void Cadastro()
{
	int i = 1, item1, item2, peso, arestas = 0;
	cout << "Itens no inventario" << endl;
	
	for(it = itens.begin(); it != itens.end(); it++)
	{
		cout << "(" << i << ") ";
		cout << it->nome << endl;
		i++;
	}
	cout << endl; cout << "Selecione dois itens: ";
	cin >> item1 >> item2;
	item1--; item2--;
	cout << "Escreva similiaridade entre os itens (0-100): ";
	cin >> peso; arestas++;
	
	similarens[item1].push_back({item1,item2,peso});
	similarens[item2].push_back({item2,item1,peso});
	
	
	cout << endl << "Tabela de Similaridades: " << endl;
	for(i=0; i < arestas; i++)
	{
		for(ti = similarens[i].begin(); ti != similarens[i].end(); ti++)
		{
			cout << ti ->origem + 1 << " similar com " << ti -> destino + 1 << ": ";
			cout << ti -> peso << "%" << endl;
		}
	}
}

void Buscar()
{
	string nome, doninho;
	int similaridade;
	
	cout << "Escolha um dono: ";
	getline(cin >> ws, doninho);
	cout << "Digite o nome do item: ";
	getline(cin >> ws, nome);
	cout << "Digite a similaridade: ";
	cin >> similaridade;
	
	ti = similarens.begin();
	for(it = itens.begin(); it != itens.end(); it++)
	{
		if(it->dono!=doninho)
		{
			if(ti->origem == it && similaridade <= ti->peso)
			{
				if(N[it] == nome)
				{
					cout << it -> nome << endl;
				}
			}
		}
		ti++;
	}
	
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
