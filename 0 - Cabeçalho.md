# Como escrever um arquivo de cabeçalho em C!
## O que são, de fato, arquivos de cabeçalho?
Eles são um tipo de arquivo no qual é possível declarar as funções que você usará no arquivo/função main. Arquivos de cabeçalho normalmente são usados para definir **tipos de dados**, **protótipos de funções** e **comandos para o pré-processador**.

## Passo-a-Passo
### Crie nomedoarquivo.h (Arquivo de Cabeçalho)
Dentro desse arquivo de cabeça, que precisa ter a extensão de arquivo **.h**, você irá apenas declarar suas funções. O propósito dos arquivos de cabeçalho é facilitar o uso dessas definições de funções e modularizar um programa extenso em C.

Você irá incluir **"#ifndef/define FILENAME_H_"** e **"#endif"** no seu código. Eles são chamados de **"#include guards"**. Uma vez que o cabeçalho for incluído, será checado se um valor único (que seria o **"NOMEDOARQUIVO_H_"**) está **definido**. Se **não está definido**, o programa irá definir e continuar para o resto do código. Então quando o código é **incluído novamente**, o primeiro "#ifndef" irá **falhar** (porque o valor já está definido), resultando em um arquivo de cabeçalho vazio. **Isso irá prevenir declaração dupla de quaisquer identificadores, como tipos, enums e variáveis estáticas.**

```C
// nomedoarquivo.h

#ifndef NOMEDOARQUIVO_H_     //se não está definido,
#define NOMEDOARQUIVO_H_              //então define

void subtraia (int, int);
void divida (int, int);

#endif                      //fim da condição
```

Note que você não irá declarar o nome dos parâmetros (mas você pode, se você realmente quiser), apenas o tipo deles!
Com o código acima, você estará basicamente dizendo que você terá **duas funções**, uma chamada **subtraia** e outra chamada **divida**, ambas irão aceitar **dois parâmetros** de tipo **inteiro** e **retornam tipo vazio**.

### Crie nomedoarquivo.c (Arquivo Fonte)
Em nomedoarquivo.c, que é o arquivo fonte de nomedoarquivo.h, você irá incluir "nomedoarquivo.h" (aqui é onde "#include guards" são necessários) e escrever suas funções, como você faria normalmente em C.

```C
// nomedoarquivo.c

#include <stdio.h>
#include "nomedoarquivo.h"

void subtraia(int a, int b){
    printf("Valor da subtração = %d\n", a - b);    
}

void divida(int a, int b){
    printf("Valor da divisão = %d\n" a / b);
}
```

Note que no bloco de código acima, a inclusão do seu nomedoarquivo.h usa aspas (""), e o motivo disso é que elas darão instrução para o pré-processador pesquisar por ele no diretório atual e no diretório padrão (caso não encontre o arquivo de cabeçalho no diretório atual). Você pode usar chevrons (<>) se você salvar o nomedoarquivo.h no diretório padrão.

Seu arquivo de cabeçalho, se você estiver usando aspas, **PRECISA** estar no mesmo diretório do seu arquivo main e do seu arquivo fonte.

### Inclua no arquivo main
Para usar seu novo arquivo de cabeçalho, será necessário incluir "stdio.h" para poder chamar a função "printf()" que você utilizou no código acima (nomedoarquivo.c). Você terá de incluir, também, seu "nomedoarquivo.h"

```C
// main.c

#include <stdio.h>      //não há problema em reincluir stdio.h
#include "nomedoarquivo.h"

int main(){
    subtraia(3, 2);
    
    divida(6. 3);

    printf("eba!\n");

    return 0;
}
```

Saída:

```
Valor da subtração = 1
Valor da divisão = 2
eba!
```

# Referências
*    https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
*    https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*    https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c