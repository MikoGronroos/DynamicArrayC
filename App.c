#include "DynamicMemory.h"
#include <stdio.h>

typedef struct{
    int size;
    int item_size;
}Testi;

int main(void)
{
    List *list = Create(sizeof(int*));
    void *ptr = malloc(list->item_size);
    *((int*)ptr) = 5;
    Push(list, ptr);
    Push(list, ptr);
    Push(list, ptr);
    Push(list, ptr);
    for (size_t i = 0; i < list->size; i++)
    {
        void* ptrs = list->memory[i];
        printf("%d\n", *((int*)ptrs));
    }
    printf("--------\n");
    List *lista = Create(sizeof(char**));
    void *stringPtr = malloc(lista->item_size);
    *((char**)stringPtr) = "Xdd";


    void *stringPtr1 = malloc(lista->item_size);
    *((char**)stringPtr1) = "Moi";


    Push(lista, stringPtr);
    Push(lista, stringPtr1);
    Push(lista, stringPtr);
    Push(lista, stringPtr1);
    Push(lista, stringPtr);
    Push(lista, stringPtr1);
    Push(lista, stringPtr);
    Push(lista, stringPtr1);
    for (size_t i = 0; i < lista->size; i++)
    {
        void* ptrs = lista->memory[i];
        printf("%s\n", *((char**)ptrs));
    }    
    printf("%d\n", lista->size);
    printf("--------\n");

    Release(lista, 1);
    Release(lista, 2);
    Release(lista, 0);

    for (size_t i = 0; i < lista->size; i++)
    {
        void* ptrs = lista->memory[i];
        printf("%s\n", *((char**)ptrs));
    }
    printf("%d\n", lista->size);

    printf("--------\n");

    for (size_t i = 0; i < 8; i++)
    {
        void* ptrs = lista->memory[i];
        printf("%p\n", ptrs);
    }

    printf("--------\n");

    Release(lista, 1);
    Release(lista, 2);
    Release(lista, 0);

    for (size_t i = 0; i < 8; i++)
    {
        void* ptrs = lista->memory[i];
        printf("%p\n", ptrs);
    }


    printf("--------\n");
    List *testiLista = Create(sizeof(Testi*));
    void *testiPtr = malloc(testiLista->item_size);
    Testi *my_struct;
    my_struct = malloc(sizeof(Testi));
    my_struct->item_size = 676;
    my_struct->size = 6969;
    *((Testi*)testiPtr) = *my_struct;

    Push(testiLista, testiPtr);

    for (size_t i = 0; i < 1; i++)
    {
        void* ptrs = testiLista->memory[i];
        Testi value1 = *((Testi*)ptrs);
        printf("%d,, %d\n", value1.item_size, value1.size);
    }

    return 0;
}
