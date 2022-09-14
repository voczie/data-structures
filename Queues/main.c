#include <stdlib.h>
#include <stdio.h>
#include "queue.c"

int main(){
    tQueue queue;
    tQueue * p_queue = &queue;
    int interger, i;

    p_queue = create_queue(p_queue);

    if(is_empty(p_queue)){
        printf("the queue is empty!\n");
    }
    else{
        printf("the queue is not empty\n");
    }

    printf("total of nodes = %d\n", get_queue_size(p_queue));

    enqueue(p_queue, 10);

    print_queue(p_queue);

    enqueue(p_queue, 23);
    enqueue(p_queue, 324);

    print_queue(p_queue);

    enqueue(p_queue, 593);

    print_queue(p_queue);

    for(i = 1; i <= 2; i++){
        interger = dequeue(p_queue);
        printf("dequeued int = %d\n", interger);
    }

    print_queue(p_queue);

    clean_queue(p_queue);

    if(is_empty(p_queue)){
        printf("the queue is empty!\n");
    }
    else{
        printf("the queue is not empty\n");
    }

    return 0;
}