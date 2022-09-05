#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.c"

int main(){
    tSingly_List singly_list;
    tSingly_List * p_singly_list = &singly_list;

    p_singly_list = create_list(p_singly_list);

    if(is_empty(p_singly_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty\n");
    }

    printf("total of nodes = %d\n", get_list_size(p_singly_list));

    insert_at_position(p_singly_list, 10, 1);
    print_list(p_singly_list);
    insert_at_position(p_singly_list, 23, 2);
    insert_at_position(p_singly_list, 324, 3);

    print_list(p_singly_list);

    insert_at_position(p_singly_list, 593, 4);

    print_list(p_singly_list);

    insert_at_position(p_singly_list, 6967, get_list_size(p_singly_list));

    print_list(p_singly_list);

    remove_at_position(p_singly_list, 2);

    print_list(p_singly_list);

    modify_value_at_position(p_singly_list, 777, get_list_size(p_singly_list));

    print_list(p_singly_list);

    free_list(p_singly_list);

    print_list(p_singly_list);

    if(is_empty(p_singly_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty\n");
    }

    return 0;
}