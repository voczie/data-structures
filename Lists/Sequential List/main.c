#include <stdlib.h>
#include <stdio.h>
#include "sequential_list.c"

int main(){
    tSequential_List seq_list;
    tSequential_List * p_seq_list = &seq_list;

    p_seq_list = create_list(p_seq_list);

    if(is_empty(p_seq_list)){
        printf("the list is empty!\n");
    }
    else{
        printf("the list is not empty!\n");
    }

    printf("total elements %d\n", get_list_size(p_seq_list));

    insert_at_position(p_seq_list, 10, 0);

    print_list(p_seq_list);

    insert_at_position(p_seq_list, 23, 1);
    insert_at_position(p_seq_list, 324, 2);

    print_list(p_seq_list);

    insert_at_position(p_seq_list, 593, 3);

    print_list(p_seq_list);

    insert_at_position(p_seq_list, 6967, get_list_size(p_seq_list) - 1);

    print_list(p_seq_list);

    insert_at_position(p_seq_list, 666, 2);

    print_list(p_seq_list);

    remove_at_position(p_seq_list, 2);

    print_list(p_seq_list);

    modify_value_at_position(p_seq_list, 999, get_list_size(p_seq_list) - 1);

    print_list(p_seq_list);


    return 0;
}
