#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


//////////////////////////////////////////////////////////////////


typedef struct tNode{
    int data;
    tNode * beneath;
} tNode;

typedef struct tStack{
    tNode * top;
    int total_nodes;
} tStack;


//////////////////////////////////////////////////////////////////


tNode * create_node(tNode * node, int data_value){
    node = (tNode *)malloc(sizeof(tNode));

    if(node == NULL){
        printf("couldn't allocate node :(\n");
        return NULL;
    }

    node->data = data_value;
    node->beneath = NULL;

    printf("memory allocated node, value = %d\n", node->data);

    return node;
}

tStack * create_stack(tStack * stack){
    stack->top = NULL;
    stack->total_nodes = 0;

    printf("stack created!\n");

    return stack;
}

int is_empty(tStack * stack){
    if(stack->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int get_stack_size(tStack * stack){
    return stack->total_nodes;
}

int push(tStack * stack, int data_value){
    tNode * new_node;

    new_node = create_node(new_node, data_value);

    if(new_node == NULL){
        printf("couldn't allocate node and push it :(\n");
        return 0;
    }

    else{
        new_node->beneath = stack->top;
        stack->top = new_node;

        printf("\nstack size = %d, node data = %d\n\n", get_stack_size(stack), stack->top->data);
        
        stack->total_nodes++;

        return 1;
    }
}

int pop(tStack * stack){
    tNode * popped_node = stack->top;
    int popped_value = popped_node->data;

    stack->top = popped_node->beneath;

    free(popped_node);

    stack->total_nodes--;

    return popped_value;
}

void print_stack(tStack * stack){
    int i = 1;
    tNode * node_print = stack->top;

    for(i; i <= get_stack_size(stack); i++){
        if(node_print->beneath == NULL){
            printf("index = %d, data = %d\n", i, node_print->data);
            break;
        }
        else{
            printf("index = %d, data = %d\n", i, node_print->data);
            node_print = node_print->beneath;
        }
    }

    printf("\n");
}

void clean_stack(tStack * stack){
    int popped, i = 1, stack_size = get_stack_size(stack);

    printf("starting to clean...\n");
    for(i; i <= stack_size; i++){
        printf("actual size = %d, i = %d\n", stack_size, i);
        stack_size = get_stack_size(stack);
        
        popped = pop(stack);
        printf("actual size = %d, i = %d, popped value = %d\n", stack_size, i, popped);
    }
    
    printf("stack cleaned!\n");
    stack->top = NULL;
}