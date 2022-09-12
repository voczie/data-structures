#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.c"

int main(){
    tCircular_List circular_list;
    tCircular_List * p_circular_list = &circular_list;

    p_circular_list = create_list(p_circular_list);

    if(is_empty(p_circular_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty\n");
    }

    printf("total of nodes = %d\n", get_list_size(p_circular_list));

    insert_at_position(p_circular_list, 10, 1);
    print_list(p_circular_list);
    insert_at_position(p_circular_list, 23, 2);
    insert_at_position(p_circular_list, 324, 3);

    print_list(p_circular_list);

    insert_at_position(p_circular_list, 593, 4);

    print_list(p_circular_list);

    insert_at_position(p_circular_list, 6967, get_list_size(p_circular_list));

    print_list(p_circular_list);

    remove_at_position(p_circular_list, 2);

    print_list(p_circular_list);

    modify_value_at_position(p_circular_list, 777, get_list_size(p_circular_list));

    print_list(p_circular_list);

    free_list(p_circular_list);

    print_list(p_circular_list);

    if(is_empty(p_circular_list)){
        printf("the list is empty!\n");
    }
    else{
        print_list(p_circular_list);
        printf("the list is not empty\n");
    }

    return 0;
}