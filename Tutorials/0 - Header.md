# How to write a **header** files in C!
## What is, in fact, a header file?
They are a type of file in which is possible to declare the functions that you'll be using in the main file/function. Header files usually are used for define **data types**, **function prototypes** and **preprocessor commands**.

## Step-by-Step
### Create filename.h (Header File)
Inside this header file, that need to have **.h** file extension, you'll only declare your functions. The purpose of header files is to facilitate the use of those functions definitions and modularize a large C program.

You'll include **"#ifndef/define FILENAME_H_"** and **"#endif"** into the code. They are called **"#include guards"**. Once the header is included, it checks if a unique value (that would be **"FILENAME_H_"**) is **defined**. If it's **not defined**, it defines it and continues to the rest of the code. So, when the code is **included again**, the first "#ifndef" will **fail** (because the value is already defined), resulting in a blank file. **That will prevent double declaration of any identifiers such as types, enums and static variables.**

```C
// filename.h

#ifndef FILENAME_H_     //if not defined,
#define FILENAME_H_         //then define

void subtract (int, int);
void divide (int, int);

#endif                 //end if statement
```

Note that you'll not declare parameters names (but you can, if you really want to), only their types!
With the code above, you're basically saying that you'll have **two functions**, one named **subtract** and other named **divide**, both will accept **two parameters** with **interger** type and **return void type**.

### Create filename.c (Source File)
In filename.c, that is your source file for filename.h, you'll include "filename.h" (here is where "#include guards" are necessary) and write your functions, like you would do in normally in C.
```C
// filename.c

#include <stdio.h>
#include "filename.h"

void subtract(int a, int b){
    printf("Subtracted value = %d\n", a - b);    
}

void divide(int a, int b){
    printf("Divided value = %d\n" a / b);
}
```
Note that in the code block above, the include of your filename.h uses quotes (""), and that's because that'll instruct the preprocessor to search for it in the actual folder and in the standard folder (if it doesn't find the header file in the actual folder). You can use angular brackets (<>) if you save the filename.h in the standard folder.

Your header file, if you're using quotes, **NEEDS** to be in the same folder of your main file and your source file.

### Include it in main file
To use your new header file, it'll be necessary to include "stdio.h" in order to use the function "printf()" that you called in the code above (filename.c). You'll have to include, also, your "filename.h". 

```C
// main.c

#include <stdio.h>      //there's no problem in re-including stdio.h
#include "filename.h"

int main(){
    subtract(3, 2);
    
    divide(6. 3);

    printf("yea!\n");

    return 0;
}
```

Output:

```
Subtracted value = 1
Divided value = 2
yea!
```

# References
*    https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
*    https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*    https://stackoverflow.com/questions/7109964/creating-your-own-header-file-in-c