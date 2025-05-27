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
		inserNome(curr->left,nome);
	}
	else
	{
		inserNome(curr->right,nome);
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
		insertRaridade(curr->left,raro);
	}
	else
	{
		insertRaridade(curr->right,raro);
	}
}
 
void InserirItem()
{
	string nome, dono, magia;
	int id, raridade;
	cout << " -> Nome do Item: "; getline(cin >> ws, nome);
	inserNome(root,nome);
	cout << " -> Nome do Dono: "; getline(cin >> ws, dono);
	cout << " -> Propriedade magica: "; getline(cin >> ws, magia);
	cout << " -> Numero de Identidade: "; cin >> id;
	cout << " -> Raridade do Item (0-100): "; cin >> raridade;
	insertRaridade(raiz,raridade);
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
		return search(curr->left,nome);
	}
	else if(nome > curr->nome)
	{
		return search(curr->right,nome);
	}
}
 
void Verificar()
{
	string item;
	cout << " -> Item que deseja procurar: ";
	getline(cin >> ws, item);
	ArvoreNome * result = search(root, item); // coloca p/ apontar o no do elemento
	cout << endl;
	if(result == NULL)
	{
		cout << "Item '" << item << "' nao encontrado no inventario." << endl;
	} else {
		cout << "Item '" << item << "' encontrado no inventario." << endl;
	}
}
 
 void emOrdem(ArvoreNome * curr)
 {
 	if(curr != NULL){
	 	emOrdem(curr -> left);
	 	cout << curr->nome << endl;
	 	emOrdem(curr -> right);
	 }
 }
 
void ListarNome()
{
	emOrdem(root);
}
 
 void emOrdemR(ArvoreRaridade * curr)
 {
 	if(curr != NULL){
	 	emOrdemR(curr -> right);
	 	cout << curr->raro << endl;
	 	emOrdemR(curr -> left);
	 }
 }
 
void ListarRaridade()
{
	emOrdemR(raiz);
}
 
void ContarItens()
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

 
ArvoreRaridade * repoint_less(ArvoreRaridade * & curr)
{
  if(curr->left == NULL)
  {
    ArvoreRaridade * aux = curr;
    curr = curr->right;
    return aux;
  } else {
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
    return remove(curr->left,info);
  }
  else if(info > curr->raro)
  {
    return remove(curr->right,info);
  }
}

 // void removerMenores(ArvoreRaridade * &curr, int info)
 // {
 // 	if(curr != NULL){
	//  	removerMenores(curr -> left, info);
	//  	if(curr->raro < info){
	// 		 remove(curr, info);
	// 	 }
	//  	removerMenores(curr -> right, info);
	//  }
 // }
 	 
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
	int num;
	cout << "Digite um valor: ";
	cin >> num;
	removerMenores(raiz, num);
	cout << "A lista resultante é: " << endl;
	emOrdemR(raiz);
	cout << "A lista resultante nome é: " << endl;
	emOrdem(root);
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
