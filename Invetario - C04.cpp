// EQUIPE -----------------------------------------
NOMES : 
		IGOR MENDES MAVIGNO - 663
		JOAO AMBACK KOVACSIK SELIM - 631
		LARA MOREIRA SIÉCOLA - 611
		LAURA FERNANDA DE CASTRO FERREIRA - 2285
		PEDRO HENRIQUE SANTOS DE OLIVEIRA - 2170
// ------------------------------------------------
#include <iostream>
#include <locale>
#include <string>
#include <list>
#include <cstdlib>

using namespace std;

// INICIALIZANDO VARIAVIES ------------------------
struct ponto
{
	int x, y;
};

struct Itens
{
	string nome, dono, magia;
	int id, raridade;
};

struct Similaridade
{
	int	origem, destino, peso;
};

struct ArvoreNome
{
	string nome;
	ArvoreNome * left;
	ArvoreNome * right;
};

struct ArvoreRaridade
{
	int raro;
	ArvoreRaridade * left;
	ArvoreRaridade * right;
};

list <Itens> itens;
list<Itens>::iterator it;

list <Similaridade> similarens[9999];
list<Similaridade>::iterator ti;

ArvoreNome * root = NULL; // Para a arvore binaria
ArvoreRaridade* raiz = NULL;
// ------------------------------------------------

// INSERINDO ITENS --------------------------------

// Retorna true se o ponto p está dentro do polígono
bool dentro_do_poligono(ponto pol[], int n, ponto p)
{
	int cont = 0;
	for (int i = 0; i < n; i++)
	{
		ponto a = pol[i];
		ponto b = pol[(i + 1) % n]; // próximo vértice, com volta ao início

		// Checa se o ponto está entre os valores y dos dois vértices
		if ((a.y > p.y) != (b.y > p.y))
		{
			// Calcula a coordenada x onde a linha do ponto cruza a aresta
			double x_intersecao = (double)(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x;
			if (p.x < x_intersecao)
				cont++;
		}
	}
	return (cont % 2 == 1); // Se número de interseções for ímpar, está dentro
}

void inserNome(ArvoreNome * &curr, string nome)
{
	if(curr == NULL)
	{
		curr = new ArvoreNome;
		curr->nome = nome;
		curr->left = NULL;
		curr->right = NULL;
	}
	else if(nome < curr->nome)
	{
		inserNome(curr->left, nome);
	}
	else
	{
		inserNome(curr->right, nome);
	}
}

void insertRaridade(ArvoreRaridade * &curr, int raro)
{
	if(curr == NULL)
	{
		curr = new ArvoreRaridade;
		curr->raro = raro;
		curr->left = NULL;
		curr->right = NULL;
	}
	else if(raro < curr->raro)
	{
		insertRaridade(curr->left, raro);
	}
	else
	{
		insertRaridade(curr->right, raro);
	}
}

ponto p;
ponto pol[100];
int n;

void InserirItem()
{
	string nome, dono, magia;
	int id, raridade;

	cout << " -> Nome do Item: ";
	getline(cin >> ws, nome);
	cout << " -> Nome do Dono: ";
	getline(cin >> ws, dono);
	cout << " -> Propriedade magica: ";
	getline(cin >> ws, magia);
	cout << " -> Numero de Identidade: ";
	cin >> id;
	cout << " -> Raridade do Item (0-100): ";
	cin >> raridade;
	cout << " -> Coordenadas do Item: X = ";
	cin >> p.x;
	cout << "	                 Y = ";
	cin >> p.y;
	cout << endl;
	if (dentro_do_poligono(pol, n, p))
	{
		inserNome(root, nome);
		insertRaridade(raiz, raridade);
		itens.push_back( {nome, dono, magia, id, raridade});
		cout << "Item adicionado com sucesso!";
	}
	else
	{
		cout << "Impossivel adicionar o item com essas coordenas.";
	}
	cout << endl;
}
// ------------------------------------------------

// CADASTRANDO ITENS ------------------------------
void Cadastro()
{
	if(root != NULL)
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
		cout << endl;
		cout << " -> Selecione dois itens: ";
		cin >> item1 >> item2;
		item1--;
		item2--;
		cout << " -> Escreva similiaridade entre os itens (0-100): ";
		cin >> peso;
		arestas++;
		similarens[item1].push_back({item1, item2, peso});
		similarens[item2].push_back({item2, item1, peso});

		cout << endl << " -------------- TABELA DE SIMILARIDADES -------------- " << endl;
		i = 0;
		for(it = itens.begin(); it != itens.end(); ++it, ++i)
		{
			for(ti = similarens[i].begin(); ti != similarens[i].end(); ti++)
			{
				if (ti->origem < ti->destino) // mostra só uma vez
            	{
					cout << "- " << ti ->origem + 1 << " similar com " << ti -> destino + 1 << ": " << ti -> peso << "%" << endl;
				}
			}
		}
		cout << " ----------------------------------------------------- " << endl;
	}
	else
	{
		cout << "Nao sera possivel cadastrar similaridade entre itens, pois nao ha itens." << endl;
	}
}
// ------------------------------------------------

// BUSCANDO ITENS ---------------------------------
void Buscar()
{
	if(root != NULL)
	{
		string nome, doninho;
		int similaridade;
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
	else
	{
		cout << "Nao ha itens para serem buscados." << endl;
	}
}
// ------------------------------------------------

// VERIFICANDO ITEM -------------------------------
ArvoreNome * search(ArvoreNome * curr, string nome)
{
	if(curr == NULL)
	{
		return NULL;
	}
	else if(curr->nome == nome)
	{
		return curr;
	}
	else if(nome < curr->nome)
	{
		return search(curr->left, nome);
	}
	else if(nome > curr->nome)
	{
		return search(curr->right, nome);
	}
}

void Verificar()
{
	if(root != NULL)
	{
		string item;
		cout << " -> Item que deseja procurar: ";
		getline(cin >> ws, item);
		ArvoreNome * result = search(root, item); // coloca p/ apontar o no do elemento
		cout << endl;
		if(result == NULL)
		{
			cout << "Item '" << item << "' nao encontrado no inventario." << endl;
		}
		else
		{
			cout << "Item '" << item << "' encontrado no inventario." << endl;
		}
	}
	else
	{
		cout << "Inventario esta vazio, nao ha itens para verificar existencia." << endl;
	}
}
// ------------------------------------------------

// LISTANDO ITENS ---------------------------------
void emOrdem(ArvoreNome * curr)
{
	if(curr != NULL)
	{
		emOrdem(curr -> left);
		cout << curr->nome << endl;
		emOrdem(curr -> right);
	}
}

void ListarNome()
{
	if(root != NULL)
	{
		emOrdem(root);
	}
	else
	{
		cout << "Nao ha itens para serem listados." << endl;
	}
}

string buscanome(int info)
{

	int indice = 0;
	for (it = itens.begin(); it != itens.end(); ++it)
	{
		if (it->raridade == info)
		{
			return it->nome;
		}
		indice++;
	}

	return "";
}
void emOrdemR(ArvoreRaridade * curr)
{
	if(curr != NULL)
	{
		emOrdemR(curr -> right);
		//string n = 
		cout <<"       " << curr->raro << "                 |      " << buscanome(curr->raro) << endl;
		emOrdemR(curr -> left);
	}
}

void ListarRaridade()
{
	if(raiz != NULL)
	{
		cout << "       RARIDADE ITEM      |      NOME ITEM     " << endl;
		cout << " --------------------------------------------- " << endl;
		emOrdemR(raiz);
		cout << " --------------------------------------------- " << endl;
	}
	else
	{
		cout << "Nao ha itens para serem listados." << endl;
	}

}
// ------------------------------------------------

// CONTANDO ITENS ---------------------------------
void ContarItens()
{
	if(root != NULL)
	{
		string magia;
		cout << " -> Digite a propriedade mágica para contagem: ";
		getline(cin >> ws, magia);

		int cont = 0;
		for (it = itens.begin(); it != itens.end(); ++it)
		{
			if (it->magia == magia)
				cont++;
		}

		cout << endl;
		cout << "Foram encontrados " << cont << " item(ns) com a magia '" << magia << "'." << endl;
	}
	else
	{
		cout << "Inventario vazio, nao sera possivel procurar item." << endl;
	}
}
// ------------------------------------------------

// REMOVENDO ITENS --------------------------------
ArvoreRaridade * repoint_less(ArvoreRaridade * & curr)
{
	if(curr->left == NULL)
	{
		ArvoreRaridade * aux = curr;
		curr = curr->right;
		return aux;
	}
	else
	{
		return repoint_less(curr->left);
	}
}

string apagarList(string nome, list<Itens>::iterator it)
{
	string aux = nome;

	itens.erase(it);

	return aux;
}
string buscarNomeR(int info)
{

	int indice = 0;
	for (it = itens.begin(); it != itens.end(); ++it)
	{
		if (it->raridade == info)
		{
			return apagarList(it->nome, it);
		}
		indice++;
	}

	return "";
}

bool removeNome(ArvoreNome *&curr, const string& nome)
{
	if (curr == NULL) return false;

	if (nome < curr->nome)
		return removeNome(curr->left, nome);
	else if (nome > curr->nome)
		return removeNome(curr->right, nome);
	else
	{
		ArvoreNome *aux = curr;
		if (curr->left == NULL)
			curr = curr->right;
		else if (curr->right == NULL)
			curr = curr->left;
		else
		{
			ArvoreNome *sub = curr->right;
			while (sub->left != NULL)
				sub = sub->left;
			curr->nome = sub->nome;
			removeNome(curr->right, sub->nome);
			return true;
		}
		delete aux;
		return true;
	}
}

bool remove(ArvoreRaridade * &curr, int info)
{
	if(curr == NULL)
	{
		return false;
	}
	else if(curr->raro == info)
	{

		string nome = buscarNomeR(info);

		removeNome(root, nome);

		ArvoreRaridade * aux = curr;
		if(curr->left == NULL) // caso tenha so o filho da direita
		{
			curr = curr->right;
		}
		else if(curr->right == NULL) // caso tenha so o filho da esquerda
		{
			curr = curr->left;
		}
		else // caso tenha os dois filhos
		{
			aux = repoint_less(curr->right);
			curr->raro = aux->raro; // o meu menor do lado dos maiores será a raiz(root)
		}
		delete aux;
		aux = NULL;
		return true;
	}
	else if(info < curr->raro)
	{
		return remove(curr->left, info);
	}
	else if(info > curr->raro)
	{
		return remove(curr->right, info);
	}
}

void removerMenores(ArvoreRaridade* &curr, int info)
{
	if (curr == NULL)
	{
		return;
	}

	removerMenores(curr->left, info);
	removerMenores(curr->right, info);

	if (curr->raro < info)
	{
		remove(curr, curr->raro); // Isso já cuida de reorganizar o nó
		removerMenores(curr, info); // Verifica novamente o novo nó que ficou no lugar
	}
}

void RemoverItens()
{
	if(root != NULL)
	{
		int num;
		cout << "Digite um valor: ";
		cin >> num;
		removerMenores(raiz, num);
		cout << endl;
		cout << " ---------- INVENTARIO APOS REMOCAO ---------- " << endl;
		cout << "       RARIDADE ITEM      |      NOME ITEM     " << endl;
		cout << " --------------------------------------------- " << endl;
		emOrdemR(raiz);
		cout << " --------------------------------------------- " << endl;
		cout << endl;
	}
	else
	{
		cout << "Inventario nao tem itens para que se possa ser removido." << endl;
	}
}
// ------------------------------------------------

// MENU -------------------------------------------
int main()
{
	int x;
	setlocale(LC_ALL, "");
	int sair = NULL;
	int cont = 1;

	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Olá! Bem vindo ao seu Inventario Infinito!" << endl;
	cout << "Para comecar a sua aventura, vamos definir o tamanho da sua bolsa." << endl;
	cout << "Primeiro sera preciso colocar a quatidade de pontos para formar a bolsa," << endl;
	cout << "logo em seguida as coordenas do ponto." << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << " -> Quantidade de pontos: ";
	cin >> n;
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << "Ponto " << cont << ":" << endl;
		cout << " -> X = ";
		cin >> pol[i].x;
		cout << " -> Y = ";
		cin >> pol[i].y;
		cout << endl;
		cont++;
	}
	cout << "Bolsa criada com sucesso! Agora pode prosseguir com a insercao de itens." << endl;

	cout << "     _________" << endl;
	cout << "    /        /\\_" << endl;
	cout << "   /________/  /\\" << endl;
	cout << "   | ______ | /  \\" << endl;
	cout << "   ||      ||/    \\" << endl;
	cout << "   ||  ()  ||      |" << endl;
	cout << "   ||______||      |" << endl;
	cout << "   |________\\_____/" << endl;

	cout << endl;
	cout << " -> Insira [1] para continuar e [0] para sair: ";
	cin >> sair;
	if(sair == 1)
	{
		system("cls");
	}
	else
	{
		return 0;
	}


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
		cin >> x;
		cout << endl;
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
// ------------------------------------------------
