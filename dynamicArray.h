#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void **memory;
    int size;
    int item_size;
}List;

void Push(List *list, void* value){
    list->memory[list->size] = value;
    list->size++;
    if(list->size % 4 == 0 && list->size != 1)
    {
       void** newMemory = realloc(list->memory, (list->size + 4) * list->item_size);
       if(newMemory != NULL)
       {
            list->memory = newMemory;
       }
    }
}

List* Create(int item_size)
{
    List *my_struct;
    my_struct = malloc(sizeof(List));
    my_struct->memory = malloc(4 * item_size);
    my_struct->size = 0;
    my_struct->item_size = item_size;
    return my_struct;
}

void Release(List *list, int pos){
    int i = 0;
    for(i=pos; i<list->size-1; i++)
    {
        list->memory[i] = list->memory[i + 1];
    }
    list->size--;
    if(list->size <= 0){
        free(list);
    }else{
        if(list->size % 4 == 0)
        {
            void** newMemory = realloc(list->memory, list->size *     list->item_size);
            if(newMemory != NULL)
            {
                list->memory = newMemory;
            }
        }
    }
}
