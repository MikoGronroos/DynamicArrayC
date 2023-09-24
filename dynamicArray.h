#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* arr;
    int size;
}Array;

void InitArray(Array *arr){
    arr->arr = (int*)malloc(4 * sizeof(int));
    arr->size = 0;
}

void Push(int value, Array *array){
    int lastElementPos = array->size - 1;
    array->size++;
    if(array->size > 4){
        array->arr = (int*)realloc(array->arr, array->size * sizeof(int));
    }
    array->arr[lastElementPos + 1] = value;
}

void Release(Array *array, int pos){
    int i = 0;
    for(i=pos-1; i<array->size-1; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->size--;
    if(array->size <= 0){
        free(array);
    }else{
        array->arr = realloc(array->arr, array->size * sizeof(int));
    }
}