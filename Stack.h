#pragma once

struct Stack
    {
    int* data;
    size_t size;
    size_t capacity;
    };

typedef struct Stack Stack;

int StackPop(Stack *pStk);
void StackPush(Stack *pStk, int elem);
void StackDestructor(Stack *pStk);
void StackConstructor(Stack *pStk, int initcapacity);
