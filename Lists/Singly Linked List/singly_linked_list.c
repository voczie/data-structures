#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_list.h"


//////////////////////////////////////////////////////////////////


typedef struct tNode{
    int data;
    tNode * next;
} tNode;

typedef struct tSingly_List{
    tNode * head;
    int total_nodes;
} tSingly_List;


//////////////////////////////////////////////////////////////////


tNode * create_node(tNode * node, int data_value){
    node = (tNode *)malloc(sizeof(tNode));

    if(node == NULL){
        printf("couldn't allocate node :(\n");
        return NULL;
    }

    node->data = data_value;
    node->next = NULL;

    printf("memory allocated node, value = %d\n", node->data);

    return node;
}

tSingly_List * create_list(tSingly_List * list){
    list->head = NULL;
    list->total_nodes = 0;

    printf("list created!\n");

    return list;
}

int is_empty(tSingly_List * list){
    if(list->head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int get_list_size(tSingly_List * list){
    return list->total_nodes;
}

int get_value_at_position(tSingly_List * list, int index){
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

int modify_value_at_position(tSingly_List * list, int new_value, int index){
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

int insert_at_position(tSingly_List * list, int data_value, int index){
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
            new_node->next = node_get_position->next;
            node_get_position->next = new_node;
        }

        list->total_nodes++;

        return 1;
    }
}

int remove_at_position(tSingly_List * list, int index){
    int i = 1;
    tNode * control_node = list->head;
    tNode * remove_node;

    if(index == 0 || index > get_list_size(list)){
        printf("not a valid index\n");
        return 0;
    }

    if(index == 1){
        remove_node = control_node;
        list->head = remove_node->next;
    }

    else{
        for(i; i < index - 1; i++){ 
                if(control_node->next == NULL){
                    break;
                }
                control_node = control_node->next;
        }
        remove_node = control_node->next;
        control_node->next = remove_node->next;
    }

    free(remove_node);

    list->total_nodes--;

    return 1;
}
   
    

void print_list(tSingly_List * list){
    int i = 1;
    tNode * node_print = list->head;

    for(i; i <= get_list_size(list); i++){
        if(node_print->next == NULL){
            printf("index = %d, data = %d\n", i, node_print->data);
            break;
        }
        else{
            printf("index = %d, data = %d\n", i, node_print->data);
            node_print = node_print->next;
        }
        
    }
}

void free_list(tSingly_List * list){
    int i = 1, list_size = get_list_size(list);

    printf("starting to clean...\n");
    for(i; i <= list_size;){
        printf("actual size = %d, i = %d\n", list_size, i);

        remove_at_position(list, list_size);
        list_size--;
    }
    printf("list cleaned!\n");
}