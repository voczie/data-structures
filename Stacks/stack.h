#ifndef STACK_H_
#define STACK_H_

typedef struct tNode tNode;
typedef struct tStack tStack;

tNode * create_node(tNode *, int);
tStack * create_stack(tStack *);
int is_empty(tStack *);
int get_stack_size(tStack *);
int push(tStack *, int);
int pop(tStack *);
void print_stack(tStack *);
void clean_stack(tStack *); //to do recursive function

#endif