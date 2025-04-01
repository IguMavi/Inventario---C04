#include <iostream>
#include <locale>
#include <string>
#include <list>
#include <cstdlib>

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

list <Itens> itens;
list<Itens>::iterator it;

list <Similaridade> similarens[9999];
list<Similaridade>::iterator ti;

void InserirItem()
{
	string nome, dono, magia;
	int id, raridade;
	
	cout << " -> Nome do Item: "; getline(cin >> ws, nome);
	cout << " -> Nome do Dono: "; getline(cin >> ws, dono);
	cout << " -> Propriedade magica: "; getline(cin >> ws, magia);
	cout << " -> Numero de Identidade: "; cin >> id;
	cout << " -> Raridade do Item (0-100): "; cin >> raridade;
	itens.push_back({nome, dono, magia, id, raridade});
	cout << endl;
}

void Cadastro()
{
	int i = 1, item1, item2, peso, arestas = 0;
	
	cout << " ---------------- ITENS NO INVENTARIO ---------------- " << endl;
	for(it = itens.begin(); it != itens.end(); it++)
	{
		cout << "(" << i << ") ";
		cout << it->nome << endl;
		i++;
	}
	cout << " ----------------------------------------------------- " << endl;
	
	//OBS QND NAO TIVER ITENS NO INVENTARIO SAIR DA FUNCAO
	
	cout << endl; cout << " -> Selecione dois itens: ";
	cin >> item1 >> item2;
	item1--; item2--;
	cout << " -> Escreva similiaridade entre os itens (0-100): ";
	cin >> peso; arestas++;
	
	similarens[item1].push_back({item1,item2,peso});
	similarens[item2].push_back({item2,item1,peso});
	
	
	cout << endl << " -------------- TABELA DE SIMILARIDADES -------------- " << endl;
	for(i=0; i < arestas; i++)
	{
		for(ti = similarens[i].begin(); ti != similarens[i].end(); ti++)
		{
			cout << "- " << ti ->origem + 1 << " similar com " << ti -> destino + 1 << ": " << ti -> peso << "%" << endl;
		}
	}
	cout << " ----------------------------------------------------- " << endl;
}

void Buscar()
{
	string nome, doninho;
	int similaridade;
	
	// OBS SE NAO TIVER NENHUM ITEM SAIR DA FUNCAO 
	// OBS QUANDO NAO ACHAR UM ITEM NAO PODE DAR ERRO, TEM Q SAIR
	
	cout << " -> Escolha um dono, para nao pertencer: ";
	getline(cin >> ws, doninho);
	cout << " -> Digite o nome do item, que queira ter similaridade: ";
	getline(cin >> ws, nome);
	cout << " -> Digite a similaridade: ";
	cin >> similaridade;
	
    int posicao = -1; // posicao do intem
    int indice = 0; // contador
    for (it = itens.begin(); it != itens.end(); it++)
    {
        if (it->nome == nome)
        {
            posicao = indice;
            break;
        }
		indice++;
    }
    
    cout << endl;

    for (ti = similarens[posicao].begin(); ti != similarens[posicao].end(); ti++)
    {
        indice = 0;
        for (it = itens.begin(); it != itens.end(); it++)
        {
            if (it->dono != doninho && indice == ti->destino) 
            {
		        if (ti->peso >= similaridade)
		        {
		        	cout << "- " << it->nome << " tem similaridade de " << ti->peso << "% com o item " << nome << endl;
                }
			}
			indice++;
        }
	}
	
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
		// system("cls"); // Limpa o terminal
		cout << " ------------------------ MENU ------------------------ " << endl;
		cout << "[1] - Inserir item" << endl;
		cout << "[2] - Cadastrar similaridades entre itens" << endl;
		cout << "[3] - Buscar itens similares" << endl;
		cout << "[4] - Verificar a existencia de um item" << endl;
		cout << "[5] - Listar itens (por ordem alfabetica de nome)" << endl;
		cout << "[6] - Listar itens (por ordem decrescente de raridade)" << endl;
		cout << "[7] - Contar itens com a mesma propriedade magica" << endl;
		cout << "[8] - Remover itens menos raros" << endl;
		cout << "[0] - Sair" << endl;
		cout << " ------------------------------------------------------ " << endl;
		cout << endl;
		cout << " -> Insira opção desejada: ";
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
				cout << " ! OPCAO INVALIDA ! " << endl;;
		}
	}
	
	return 0;
}
