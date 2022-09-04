# Structs
## What is a Struct?
Structures are a **compound data type** that we use for **grouping** other data types (simple and compound) under a **common and unique data type**. All the data that composes a structure needs to be stored within named **variables**. We call it **"Struct"** in C language.

## How to use it
### Creating a struct
It's pretty easy to think of any situation that it's needed to group data into some object. For example, if you need to register a costumer that sign up in your store's website.

```C
// costumer.c

#include <stdio.h>
#include <string.h>

struct costumer{        // "struct" is the keyword, "costumer" is the structure tag
    char first_name[30];
    char last_name[30];
    char credit_card_number[17];    // those are the members/fields
    int security_number;            // of the structure
    int age;
    float checkout_price;
};
```

### Using a struct
When we use the structure we made, it's necessary to create a variable of the **"costumer"** type, and then we can use it as a group and other variables could be **referred** to by using **dot notation**.

```C
// costumer.c

struct costumer jojo;    // defining a variable "jojo" of data type "costumer"

strcpy(jojo.first_name, "Joseph");
strcpy(jojo.last_name, "Joestar");
jojo.age = 40;
jojo.checkout_price = 230.5;

printf("%s %s, %d years old, has a chekout of $%.2f\n", jojo.first_name, jojo.last_name, jojo.age, jojo.checkout_price);
```

### Another way to declare a Struct
We can declare a Struct and separately assign a variable of their type. But it's also possible to declare a variable at the moment we create a structure.

```C
// costumer.c

struct costumer{        
    char first_name[30];
    char last_name[30];
    char credit_card_number[17];
    int security_number;
    int age;
    float checkout_price;
} jojo;
```
Warning: In C++, the struct keyword is optional before in declaration of a variable. In C, it is mandatory.

### Initializing Structs
We can't initialize a struct when declaring it. It's **only possible** to do it with a **declared struct variable** inside a **function** through **curly braces ({})**. 
We can use the order of the struct members declarations to initialize them or use designated declaration.

#### Initializing through order of declaration
```C
// money.c

struct money{
    float dollar, euro, real;
    int yen;
};

int main(){
    struct money wallet = {21.4, 21.5, 110.67, 3000};
    return 0;
}
```

#### Initializing through designed declaration
```C
// money.c

struct money{
    float dollar, euro, real;
    int yen;
};

int main(){
    struct money wallet = {.euro = 21.5, .real = 110.67, .yen = 3000, .dollar = 21.4};
    struct money purse = {.yen = 10000, .real = 368.89};

    return 0;
}
```
### Self-Referential Structs
A structure that self referentiates themselfs is a definition which includes at least one variable that is a **pointer** to the **struct** of its **own type**.

```C
// node.c

struct Node{
    int data;
    struct Node *next;  // refers to itself
};
```

### Structure Pointer
It's possible to use pointers to struct data types. If it happens, to access the struct members we use the **arrow operator (->)**.

```C
// money.c

#include <stdio.h>

struct money{
    float dollar, euro, real;
    int yen;
};

int main(){
    struct money wallet = {.euro = 21.5, .real = 110.67, .yen = 3000, .dollar = 21.4};
    struct money *purse = &wallet;  // purse is a pointer to wallet, and both are money type

    printf("Euro = %.2f, Dollar = %.2f", purse->euro, purse->dollar);
    return 0;
}
```
Through **"purse"**, it's possible to have access to **"wallet"** members.

### Using typedef
Type Definition (typedef) is a command that allows the definition of a new type. With that, it's possible to create a type from a struct.

```C
// hair.c

typedef struct{
    char color[15];
    char type[3];
    int length_cm;
} hair;

int main(){
    hair jojo = {.color = "brown", .type = "1B", .length_cm = 25};   // with that, there's no 
                                                                    //need to use "struct" before "hair"
    return 0;
}
```

### Limitations of Structs in C
*   We cannot use operators like +,- etc. on Structure variables;
*   C Structures do not permit data hiding. Structure members can be accessed by any function, anywhere in the scope of the Structure;
*   C structures do not permit functions inside Structure;
*   C Structures cannot have static members inside their body;
*   C Programming language do not support access modifiers. So they cannot be used in C Structures;
*   Structures in C cannot have constructor inside Structures.

## References
*   https://www.thedshandbook.com
*   https://www.geeksforgeeks.org/structures-c/
*   https://www.ime.usp.br/~pf/algoritmos/aulas/footnotes/typedef.html