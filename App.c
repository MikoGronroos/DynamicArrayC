#include "dynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Array *array = malloc(sizeof(Array));
    InitArray(array);

    printf("Push\n");

    Push(9, array);
    Push(15, array);
    Push(18, array);
    int i = 0;
    for(i = 0; i < array->size; i++){
        printf("%d\n", array->arr[i]);
    }
    
    printf("\nRelease\n");

    Release(array, 3);
    Release(array, 2);

    int j = 0;
    for(j = 0; j < array->size; j++){
        printf("%d\n", array->arr[j]);
    }
    printf("Amount of items: %d", array->size);
}