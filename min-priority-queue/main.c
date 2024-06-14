#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Declarations */

#define DEFAULT_LIST_SIZE 1

typedef struct {
    size_t len;
    uint8_t *items;
    size_t size;
} min_priority_queue;

void init(min_priority_queue * l);
void upgradeList(min_priority_queue * l, size_t len, size_t size);
void checkQueueSizeAndUpdate(min_priority_queue * l);
void printQueue(min_priority_queue*l);
void enqueue(uint8_t val, min_priority_queue *l);
uint8_t dequeue(min_priority_queue *l);
uint8_t front(min_priority_queue *l);

// UNIT TESTS
int main() {
    min_priority_queue l;
    init(&l);

    printf("starting values: ");
    for (int i = 8; i >= 0; i--) {
        printf("%d ", i);
    }
    printf("\n");

    enqueue(8, &l);
    enqueue(7, &l);
    enqueue(6, &l);
    enqueue(5, &l);
    enqueue(4, &l);
    enqueue(3, &l);
    enqueue(2, &l);
    enqueue(1, &l);
    enqueue(0, &l);
    
    printQueue(&l);
    size_t k = l.len;

    for(int i = 0; i < k; i++){
        uint8_t val = front(&l);
        printf("front: %d\n", val);

        val = dequeue(&l);
        printf("dequeued: %d\n", val);

    }

    printQueue(&l);

}

/* Implementations: */

void init(min_priority_queue * l) {
    l->size = DEFAULT_LIST_SIZE;
    l->items = (uint8_t*) malloc(l->size * sizeof(uint8_t));
    l->len = 0;
}

void upgradeQueue(min_priority_queue * l, size_t len, size_t size) {
    l->size = size; // default
    l->items = reallocarray(l->items, (size + size/2), sizeof(uint8_t));
    l->len = len;
}

void checkQueueSizeAndUpdate(min_priority_queue * l) {
    if(l->len == l->size)
    {
        upgradeQueue(l, l->len, l->size);    
        printf("Array reallocated and size upgraded!\n");
    } 
}

void printQueue(min_priority_queue*l) {
    printf("min_priority_queue: ");
    for (int i = 0; i<l->len; i++) {
        printf("%d ", l->items[i]); 
    }
    printf("\n");
}

// linear time if value is minimum of queue
void enqueue(uint8_t val, min_priority_queue *l) {
    if(l->len == 0) {
        l->items[l->len] = val;
    } else if(l->items[l->len-1] > val) {
        int i = 1;
        while(l->items[l->len-i] > val) {
            uint8_t temp = l->items[l->len-i];
            l->items[l->len-i] = val;
            l->items[l->len-i+1] = temp;
            i++;
        }
    } else    
        l->items[l->len] = val;
    l->len = l->len + 1;
}

// linear time to fix array
uint8_t dequeue(min_priority_queue *l) {
    
    uint8_t retNum = l->items[0];

    for(int i = 1; i < l->len; i++){
        l->items[i-1] = l->items[i];
    }

    l->len = l->len-1;
    l->items[l->len] = 0x00;

    return retNum;
}

uint8_t front(min_priority_queue *l) {
    return l->items[0];
}
