# Estruturas — Structs
## O que é uma Struct?
Estruturas são um **tipo de dado composto** que usamos para **agrupar** outros tipos de dados (simples e compostos) sob um **tipo único de dado** que terão em comum. Todos os dados que compõem uma estrutura precisam ser armazenados em **variáveis** nomeadas. Chamamos isso de **"Struct"** em linguagem C.

## Como usá-las
### Criando uma struct
É bem fácil conseguir pensar em uma situação na qual será necessário agrupar dados em um objeto. Por exemplo, se você precisar registrar um cliente que se cadastrou no site da sua loja.

```C
// cliente.c

#include <stdio.h>
#include <string.h>

struct cliente{        // "struct" é uma palavra-chave, "cliente" é a etiqueta/tag da estrutura
    char nome[30];
    char sobrenome[30];
    char numero_cartao_de_credito[17];    // esses são os membros/campos
    int cvc;                              // da estrutura
    int idade;
    float valor_compra;
};
```

### Usando a struct
Quando usamos a estrutura que fizemos, é necessário criar uma variável do tipo **"cliente"**, e aí poderemos usá-la como grupo e suas variáveis podem ser **referenciadas** a partir do uso do **ponto final (.)**.

```C
// cliente.c

struct cliente jojo;    // declarando uma variável "jojo" do tipo de dado "cliente"

strcpy(jojo.nome, "Joseph");
strcpy(jojo.sobrenome, "Joestar");
jojo.idade = 40;
jojo.valor_compra = 230.5;

printf("%s %s, %d anos, tem uma compra de $%.2f\n", jojo.nome, jojo.sobrenome, jojo.idade, jojo.valor_compra);
```

### Outra forma de declarar uma Struct
Podemos definir uma Struct e separadamente declarar uma variável de seu tipo. Mas também é possível declarar a variável no momento em que criamos a estrutura.

```C
// cliente.c

struct cliente{        
    char nome[30];
    char sobrenome[30];
    char numero_cartao_de_credito[17];
    int cvc;
    int idade;
    float valor_compra;
} jojo;     // variável do tipo cliente
```
Aviso: Em C++, a palavra-chave struct é opcional antes da declaração de uma variável. Em C, é obrigatório.

### Inicializando Structs
Não podemos inicializar uma struct ao definí-la. **Apenas é possível** fazê-lo com uma **variável** do tipo **struct** **declarada** dentro de uma **função** a partir do uso de **chaves ({})**.
Podemos usar a **ordem de declaração dos membros** da struct para inicializá-las ou usar **declaração designada**.

#### Inicializando a partir da ordem de declaração
```C
// dinheiro.c

struct dinheiro{
    float dolar, euro, real;
    int iene;
};

int main(){
    struct dinheiro carteira = {21.4, 21.5, 110.67, 3000};
    return 0;
}
```

#### Inicializando a partir de declaração designada
```C
// dinheiro.c

struct dinheiro{
    float dolar, euro, real;
    int iene;
};

int main(){
    struct dinheiro carteira = {.euro = 21.5, .real = 110.67, .iene = 3000, .dolar = 21.4};
    struct dinheiro bolsa = {.iene = 10000, .real = 368.89};

    return 0;
}
```
### Structs Auto-Referentes
Uma estrutura que se auto referencia é a definição que inclui ao menos uma variável que é um **ponteiro** para a **struct** de seu **próprio tipo**.

```C
// no.c

struct No{
    int dado;
    struct No *prox;  // refere-se a si mesma
};
```

### Ponteiro de Estrutura
É possível usar ponteiros para tipos de dados struct. Se isso acontece, para acessar membros da struct nós usamos o **operador de seta (->)**.

```C
// dinheiro.c

#include <stdio.h>

struct dinheiro{
    float dolar, euro, real;
    int iene;
};

int main(){
    struct dinheiro carteira = {.euro = 21.5, .real = 110.67, .iene = 3000, .dolar = 21.4};
    struct dinheiro *bolsa = &carteira;  // bolsa é um ponteiro para carteira, e ambos são do tipo dinheiro

    printf("Euro = %.2f, Dolar = %.2f", bolsa->euro, bolsa->dolar);
    return 0;
}
```
Através de **"bolsa"**, é possível acessar membros de **"carteira"**.

### Usando typedef
Definição de Tipo (typedef) é um comando que permite a definição de um novo tipo de dado. Isso possibilita a criação de um tipo através de uma struct.

```C
// cabelo.c

typedef struct{
    char cor[15];
    char tipo[3];
    int tamanho_cm;
} cabelo;

int main(){
    cabelo jojo = {.cor = "marrom", .tipo = "1B", .tamanho_cm = 25};    // com isso, não há necessidade 
                                                                        // de usar "struct" antes de "cabelo"
    return 0;
}
```

### Limitações de Structs em C
*   Não podemos usar operadores como +, -, etc. em variáveis de estrutura;
*   Estruturas em C não permitem a ocultação de dados. Membros da estrutura podem ser acessados por qualquer função, em qualquer lugar no seu escopo;
*   Estruturas em C não permitem funções dentro delas;
*   Estruturas em C não podem ter métodos construtores dentro delas;
*   Estruturas em C não podem ter membros estáticos em sua formação;
*   A linguagem de programação C não tem suporte a modificadores de acesso. Então não é possível usá-los em estruturas de C.

## Referências
*   https://www.thedshandbook.com
*   https://www.geeksforgeeks.org/structures-c/
*   https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/typedef.html