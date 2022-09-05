#include <stdlib.h>
#include <stdio.h>
#include "doubly_linked.list.h"

//////////////////////////////////////////////////////////////////


typedef struct tNode{
    tNode * previous;
    int data;
    tNode * next;
} tNode;

typedef struct tDoubly_List{
    tNode * head;
    int total_nodes;
} tDoubly_List;


//////////////////////////////////////////////////////////////////


tNode * create_node(tNode * node, int data_value){
    node = (tNode *)malloc(sizeof(tNode));

    if(node == NULL){
        printf("couldn't allocate node :(\n");
        return NULL;
    }

    node->data = data_value;
    node->next = NULL;
    node->previous = NULL;

    pritnf("memory allocated node, value = %d\n", node->data);

    return node;
}

tDoubly_List * create_list(tDoubly_List * list){
    list->head = NULL;
    list->total_nodes = 0;

    printf("list created!\n");

    return list;
}

int is_empty(tDoubly_List * list){
    if(list->head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int get_list_size(tDoubly_List * list){
    return list->total_nodes;
}

int get_value_at_position(tDoubly_List * list, int index){
    int i = 1;
    tNode * node_get_position = list->head;

    if(index == 1){
        return node_get_position->data;
    }
    else{
        for(i; i < index - 1; i++){
            node_get_position = node_get_position->next;
        }
    }
    return node_get_position->data;
}

int modify_value_at_position(tDoubly_List * list, int new_value, int index){
    int old_value; 
    int i = 1;
    tNode * node_get_position = list->head;

    for(i; i < index; i++){ 
        if(node_get_position->next == NULL){
            break;
        }
        node_get_position = node_get_position->next;
    }

    old_value = node_get_position->data;
    node_get_position->data = new_value;

    if(node_get_position->data == old_value){
        return 0;
    }
    else{
        return 1;  
    } 
}

int insert_at_position(tDoubly_List * list, int data_value, int index){
    tNode * new_node;
    tNode * node_get_position = list->head;
    int i = 1;

    new_node = create_node(new_node, data_value);

    if(new_node == NULL){
        printf("couldn't allocate node and insert it :(\n");
        return 0;
    }

    else{
        if(index == 0 || index > get_list_size(list) + 1){
            printf("not a valid index\n");
            return 0;
        }

        if(index == 1){
            list->head = new_node;
        }

        else{
            for(i; i < index; i++){
                if(node_get_position->next == NULL){
                    break;
                }
                node_get_position = node_get_position->next;
            }
            printf("\ni = %d, node data = %d\n\n", i, node_get_position->data);
            new_node->previous = node_get_position;
            new_node->next = node_get_position->next;
            node_get_position->next = new_node;
        }

        list->total_nodes++;

        return 1;
    }
}

