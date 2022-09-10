#include <stdlib.h>
#include <stdio.h>
#include "circular_linked_list.h"

//////////////////////////////////////////////////////////////////


typedef struct tNode{
    tNode * previous;
    int data;
    tNode * next;
} tNode;

typedef struct tCircular_List{
    tNode * head;
    int total_nodes;
} tCircular_List;


//////////////////////////////////////////////////////////////////