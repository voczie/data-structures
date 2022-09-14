#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


//////////////////////////////////////////////////////////////////


typedef struct tNode{
    int data;
    tNode * previous;
} tNode;

typedef struct tQueue{
    tNode * head;
    tNode * tail;
    int total_nodes;
} tQueue;


//////////////////////////////////////////////////////////////////


tNode * create_node(tNode * node, int data_value){
    node = (tNode *)malloc(sizeof(tNode));

    if(node == NULL){
        printf("couldn't allocate node :(\n");
        return NULL;
    }

    node->data = data_value;
    node->previous = NULL;

    printf("memory allocated node, value = %d\n", node->data);

    return node;
}

tQueue * create_queue(tQueue * queue){
    queue->head = NULL;
    queue->tail = NULL;
    queue->total_nodes = 0;

    printf("queue created!\n");

    return queue;
}

int is_empty(tQueue * queue){
    if((queue->head == NULL) && (queue->tail == NULL)){
        return 1;
    }
    else{
        return 0;
    }
}

int get_queue_size(tQueue * queue){
    return queue->total_nodes;
}

int enqueue(tQueue * queue, int data_value){
    tNode * new_node;

    new_node = create_node(new_node, data_value);

    if(new_node == NULL){
        printf("couldn't allocate node and enqueue it :(\n");
        return 0;
    }
    else{
        if(queue->total_nodes == 0){
            queue->head = new_node;
            queue->tail = new_node;
        }
        else{
            queue->tail->previous = new_node;
            queue->tail = new_node;
            
        }
        
        queue->total_nodes++;

        return 1;
    }
}

int dequeue(tQueue * queue){
    tNode * dequeued_node = queue->head;
    int dequeued_value = dequeued_node->data;

    queue->head = dequeued_node->previous;

    free(dequeued_node);

    queue->total_nodes--;

    return dequeued_value;
}

void print_queue(tQueue * queue){
    int i = 1;
    tNode * node_print = queue->head;

    for(i; i <= get_queue_size(queue); i++){
        if(node_print->previous == NULL){
            printf("index = %d, data = %d\n", i, node_print->data);
            break;
        }
        else{
            printf("index = %d, data = %d\n", i, node_print->data);
            node_print = node_print->previous;
        }
    }

    printf("\n");
}

void clean_queue(tQueue * queue){
    int dequeued, i = 1, queue_size = get_queue_size(queue);

    printf("starting to clean...\n");
    for(i; i <= queue_size; i++){
        printf("actual size = %d, i = %d\n", queue_size, i);
        queue_size = get_queue_size(queue);

        dequeued = dequeue(queue);
        printf("actual size = %d, i = %d, dequeued value = %d\n", queue_size, i, dequeued);
    }

    printf("queue cleaned!\n");
    queue->head = NULL;
    queue->tail = NULL;
}