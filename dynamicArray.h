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

void Push(int value, Array *arr){
    int lastElementPos = arr->size - 1;
    arr->size++;
    if(arr->size > 4){
        arr->arr = (int*)realloc(arr->arr, arr->size * sizeof(int));
    }
    arr->arr[lastElementPos + 1] = value;
}

void Release(Array *arr, int pos){
    int i = 0;
    for(i=pos-1; i<arr->size-1; i++)
    {
        arr->arr[i] = arr->arr[i + 1];
    }
    arr->size--;
    if(arr->size <= 0){
        free(arr);
    }else{
        arr->arr = realloc(arr->arr, arr->size * sizeof(int));
    }
}