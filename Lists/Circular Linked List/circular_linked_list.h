#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

typedef struct tNode tNode;
typedef struct tCircular_List tCircular_List;

tNode * create_node(tNode *, int);
tCircular_List * create_list(tCircular_List *);
int is_empty(tCircular_List *);
int get_list_size(tCircular_List *);
int get_value_at_position(tCircular_List *, int);
int modify_value_at_position(tCircular_List *, int, int);
int insert_at_position(tCircular_List *, int, int);
int remove_at_position(tCircular_List *, int);
void print_list(tCircular_List *);
void free_list(tCircular_List *);

#endif