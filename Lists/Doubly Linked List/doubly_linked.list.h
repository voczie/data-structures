#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

typedef struct tNode tNode;
typedef struct tDoubly_List tDoubly_List;

tNode * create_node(tNode *, int);
tDoubly_List * create_list(tDoubly_List *);
int is_empty(tDoubly_List *);
int get_list_size(tDoubly_List *);
int get_value_at_position(tDoubly_List *, int);
int modify_value_at_position(tDoubly_List *, int, int);
int insert_at_position(tDoubly_List *, int, int);
int remove_at_position(tDoubly_List *, int);
void print_list(tDoubly_List *);
void free_list(tDoubly_List *);

#endif