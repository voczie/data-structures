#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.c"

int main(){
    tDoubly_List doubly_list;
    tDoubly_List * p_doubly_list = &doubly_list;

    p_doubly_list = create_list(p_doubly_list);

    if(is_empty(p_doubly_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty\n");
    }

    printf("total of nodes = %d\n", get_list_size(p_doubly_list));

    insert_at_position(p_doubly_list, 10, 1);
    print_list(p_doubly_list);
    insert_at_position(p_doubly_list, 23, 2);
    insert_at_position(p_doubly_list, 324, 3);

    print_list(p_doubly_list);

    insert_at_position(p_doubly_list, 593, 4);

    print_list(p_doubly_list);

    insert_at_position(p_doubly_list, 6967, get_list_size(p_doubly_list));

    print_list(p_doubly_list);

    remove_at_position(p_doubly_list, 2);

    print_list(p_doubly_list);

    modify_value_at_position(p_doubly_list, 777, get_list_size(p_doubly_list));

    print_list(p_doubly_list);

    free_list(p_doubly_list);

    print_list(p_doubly_list);

    if(is_empty(p_doubly_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty\n");
    }

    return 0;
}