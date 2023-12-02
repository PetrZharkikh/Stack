#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Stack
    {
    int* data;
    size_t size;
    size_t capacity;
    };

int StackPop(Stack *pStk);
void StackPush(Stack *pStk, int elem);
void StackDestructor(Stack *pStk);
void StackConstructor(Stack *pStk, int initcapacity);

int main(void)
    {
    struct Stack stk = {0, 0, 0};
    StackConstructor(&stk, 5);
    StackPush(&stk, 10);
    StackPush(&stk, 9);
    int x = StackPop(&stk);
    int y = StackPop(&stk);
    printf("%d, %d", x, y);
    StackDestructor(&stk);
    return 0;
    }

void StackConstructor(Stack *pStk, int initcapacity)
    {
    pStk->data = (int*)calloc(initcapacity, sizeof(int));
    pStk->size = 0;
    pStk->capacity = initcapacity;
    }

void StackDestructor(Stack *pStk)
    {
    free(pStk->data);
    pStk->data = NULL;
    pStk->size = 0;
    pStk->capacity = 0;
    }

void StackPush(Stack *pStk, int elem)
    {
    if (pStk->size == pStk->capacity)
        {
        pStk->data = (int*)realloc(pStk->data, 2*pStk->size*sizeof(int));
        pStk->capacity *= 2;
        }
    *(pStk->data + pStk->size) = elem;
    ++pStk->size;
    }

int StackPop(Stack *pStk)
    {
    if (pStk->size == 0) return -1;
    --pStk->size;
    int elem = *(pStk->data + +pStk->size);
    return elem;
    }




