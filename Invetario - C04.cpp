#include <iostream>
#include <locale>
using namespace std;

void InserirItem()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void Cadastro()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void Buscar()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void Verificar()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void ListarNome()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void ListarRaridade()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void ContarItens()
{
	cout << "Funcionalidade em contru�ao" << endl;
}
void RemoverItens()
{
	cout << "Funcionalidade em contru�ao" << endl;
}



int main()
{
	int x;
	setlocale(LC_ALL, "");
	while(true)
	{
		cout << "[1] - inserir item" << endl;
		cout << "[2] - cadastrar similaridades entre itens" << endl;
		cout << "[3] - buscar itens similares" << endl;
		cout << "[4] - verificar a existencia de um item" << endl;
		cout << "[5] - listar itens (por ordem alfabetica de nome)" << endl;
		cout << "[6] - listar itens (por ordem decrescente de raridade)" << endl;
		cout << "[7] - contar itens com a mesma propriedade magica" << endl;
		cout << "[8] - remover itens menos raros" << endl;
		cout << "[0] - sair" << endl;
		
		cout << "Insira op�ao desejada: ";
		cin >> x;
		
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
		}
	}
	
	return 0;
}