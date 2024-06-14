#include "list.h"
#include <stdlib.h>

#define LIST_DEFAULT_SIZE 2

list create_list()
{
    list l;
    
    l.len = 0;
    l.size = LIST_DEFAULT_SIZE;
    l.elements = (int*) malloc(l.size * sizeof(int));
    
    return l;
}

void checkSizeAndUpdate(list *l) 
{
    if(l->len == l->size){
        l->elements = reallocarray(l, l->size + l->size/2, sizeof(int*));
    }
}

// Adds an element and checks for list size, if not enough, update the size
size_t add(int el, list *l) 
{
    checkSizeAndUpdate(l);
    l->elements[l->len] = el;
    l->len = l->len + 1;
    return l->len - 1;
}

// Deletes an element at INDEX and returns the length of the list
size_t delete_index(unsigned int index, list *l) 
{
    if(l->len <= index) return -1;

    for(int i = index; i < l->len-1; i++)
    {
        l->elements[index] = l->elements[index+1];
    }
    l->elements[l->len] = 0x00;
    l->len = l->len-1;
    return l->len;
}

// Get an element at INDEX
int *get(unsigned int index, list *l)
{
    if(l->len <= index) return NULL;
    return &l->elements[index];
}

