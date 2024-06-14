#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t len;
    size_t size;
    int *elements;
} list;

size_t add(int el, list *l);
size_t delete_index(unsigned int index, list *l);
list create_list();
int *get(unsigned int index, list *l);







