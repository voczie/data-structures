#include <stdlib.h>
#include <stdio.h>
#include "stack.c"

int main(){
    tStack stack;
    tStack * p_stack = &stack;
    int interger, i;

    p_stack = create_stack(p_stack);

    if(is_empty(p_stack)){
        printf("the stack is empty!\n");
    }
    else{
        printf("the stack is not empty\n");
    }

    printf("total of nodes = %d\n", get_stack_size(p_stack));

    push(p_stack, 10);

    print_stack(p_stack);

    push(p_stack, 23);
    push(p_stack, 324);

    print_stack(p_stack);

    push(p_stack, 593);

    print_stack(p_stack);

    for(i = 1; i <= 2; i++){
        interger = pop(p_stack);
        printf("popped int = %d\n", interger);
    }
    
    print_stack(p_stack);

    clean_stack(p_stack);

    if(is_empty(p_stack)){
        printf("the stack is empty!\n");
    }
    else{
        printf("the stack is not empty\n");
    }

    return 0;
}