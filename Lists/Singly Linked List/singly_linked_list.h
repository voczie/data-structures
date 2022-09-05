#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

typedef struct tNode tNode;
typedef struct tSingly_List tSingly_List;

tNode * create_node(tNode *, int);
tSingly_List * create_list(tSingly_List *);
int is_empty(tSingly_List *);
int get_list_size(tSingly_List *);
int get_value_at_position(tSingly_List *, int);
int modify_value_at_position(tSingly_List *, int, int);
int insert_at_position(tSingly_List *, int, int);
int remove_at_position(tSingly_List *, int);
void print_list(tSingly_List *);
void free_list(tSingly_List *);

#endif