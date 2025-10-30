# 🧭 Inventário Infinito

Um projeto desenvolvido em **C++** com foco em estruturas de dados e manipulação dinâmica de informações.  
O programa simula um **inventário mágico**, permitindo cadastrar, buscar, listar, remover e comparar itens — tudo organizado com o uso de **árvores binárias**, **listas ligadas** e **estruturas geométricas**.

---

## 👥 Equipe
- **Igor Mendes Mavigno** - 663  
- **João Amback Kovacsik Selim** - 631  
- **Lara Moreira Siécola** - 611  
- **Laura Fernanda de Castro Ferreira** - 2285  
- **Pedro Henrique Santos de Oliveira** - 2170  

---

## ⚙️ Tecnologias utilizadas
- Linguagem: **C++**
- Bibliotecas padrão: `<iostream>`, `<list>`, `<string>`, `<cstdlib>`, `<locale>`
- Compilador recomendado: `g++` ou qualquer IDE compatível com C++

---

## 🧩 Estruturas e conceitos aplicados

| Conceito | Descrição |
|-----------|------------|
| **Structs** | Representação de entidades como `Itens`, `Similaridade`, `ArvoreNome`, `ArvoreRaridade` e `ponto`. |
| **Listas Ligadas (`std::list`)** | Armazenam dinamicamente os itens e as similaridades entre eles. |
| **Árvores Binárias** | Utilizadas para organizar e pesquisar itens por **nome** e por **raridade**. |
| **Recursão** | Empregada nas funções de inserção, busca, listagem e remoção em árvores. |
| **Ponteiros** | Controlam a alocação dinâmica de nós nas árvores e listas. |
| **Geometria Computacional** | Função `dentro_do_poligono()` verifica se um item está dentro de uma área definida pelo usuário. |
| **Busca e Ordenação** | Ordenação em ordem alfabética (em-ordem na árvore de nomes) e por raridade (árvore de inteiros). |
| **Manipulação de Estruturas Dinâmicas** | Inserção e remoção de elementos de forma eficiente sem uso de vetores fixos. |

---

## 🧠 Funcionalidades principais

- 🔹 **Inserir item:** adiciona novos objetos ao inventário (verificando se estão dentro da área válida).
- 🔹 **Cadastrar similaridade:** relaciona itens com um peso percentual de similaridade.
- 🔹 **Buscar itens similares:** lista itens compatíveis com base na similaridade e no dono.
- 🔹 **Verificar item:** busca um item pelo nome usando árvore binária.
- 🔹 **Listar itens:** exibe em ordem alfabética (por nome) ou decrescente (por raridade).
- 🔹 **Contar itens mágicos:** filtra itens com a mesma propriedade mágica.
- 🔹 **Remover itens raros:** elimina todos os itens com raridade abaixo de um valor informado.

---

## 🧭 Como executar

```bash
# Compile o programa
g++ inventario_infinito.cpp -o inventario

# Execute o executável
./inventario
