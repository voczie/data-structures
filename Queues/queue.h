#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct tNode tNode;
typedef struct tQueue tQueue;

tNode * create_node(tNode *, int);
tQueue * create_queue(tQueue *);
int is_empty(tQueue *);
int get_queue_size(tQueue *);
int enqueue(tQueue *, int);
int dequeue(tQueue *);
void print_queue(tQueue *);
void clean_queue(tQueue *);

#endif