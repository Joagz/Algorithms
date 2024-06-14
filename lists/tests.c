#include "list.h"
#include <stdio.h>

int main() {
        
    list l = create_list();
    
    int a = 3;
    int b = 2;

    add(a, &l);
    add(b, &l);

    for(int i = 0; i < l.len; i++){
        printf("0x%X ", l.elements[i]);
    }

    delete_index(0, &l);
    
    printf("\nDeleted element at index ZERO\n");
    printf("Element at ZERO now => 0x%X\n", l.elements[0]);
}

