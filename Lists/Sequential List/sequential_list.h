#ifndef SEQUENTIAL_LIST_H_
#define SEQUENTIAL_LIST_H_

typedef struct tSequential_List tSequential_List;

tSequential_List * create_list(tSequential_List *);
int is_empty(tSequential_List *);
int get_list_size(tSequential_List *);
int get_value_at_position(tSequential_List *, int);
int modify_value_at_position(tSequential_List *, int, int);
int insert_at_position(tSequential_List *, int, int);
int remove_at_position(tSequential_List *, int);
void print_list(tSequential_List *);
void free_list(tSequential_List *);

#endif