#include <stdlib.h>
#include <stdio.h>
#include "sequential_list.h"
#define MAX_VALUE 100


//////////////////////////////////////////////////////////////////


typedef struct tSequential_List{
    int data[MAX_VALUE];
    int total_elements;
} tSequential_List;


//////////////////////////////////////////////////////////////////


tSequential_List * create_list(tSequential_List * list){
    list->total_elements = 0;

    printf("list created!\n");

    return list;
}

int is_empty(tSequential_List * list){
    if((list == NULL) || (list->total_elements == 0)){
        return 1;
    }
    else{
        return 0;
    }
}

int get_list_size(tSequential_List * list){
    return list->total_elements;
}

int get_value_at_position(tSequential_List * list, int index){
    return list->data[index];
}

int modify_value_at_position(tSequential_List * list, int new_value, int index){
    int old_value = list->data[index];

    list->data[index] = new_value;

    if(list->data[index] == new_value){
        printf("Old value at index %d is %d\n", index, old_value);
        printf("New value at index %d is %d\n", index, new_value);
        return 1;
    }
    else{
        printf("error at modifying value :(\n");
        return 0;
    }
}

int insert_at_position(tSequential_List * list, int data_value, int index){
    int list_size = get_list_size(list);

    if(index > list_size){
        printf("can't insert at index %d cause index %d is empty!\n", index, index-1);
        return 0;
    }
    else{
        for(list_size; list_size > index; list_size--){
            list->data[list_size] = list->data[list_size - 1];
        }

        list->data[index] = data_value;
        list->total_elements++;

        return 1;
    }
}

int remove_at_position(tSequential_List * list, int index){
    int removed_value, list_size = get_list_size(list) - 1;

    if(index <= list_size){
        printf("there's nothing at index %d to be removed!\n", index);
        return -1;
    }
    else{
        removed_value = list->data[index];

        for(index; index <= list_size; index++){
            list->data[list_size - 1] = list->data[list_size];
        }

        list->total_elements--;

        return removed_value;
    }
}

void print_list(tSequential_List * list){
    int i = 0, list_size = get_list_size(list);
    
    for(i; i < list_size; i++){
        printf("index = %d, data = %d\n", i, list->data[i]);
    }
}

void free_list(tSequential_List * list){
    free(list);
    printf("list cleaned!\n");
}