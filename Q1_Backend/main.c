#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL
} TypeTag;

typedef struct Node
{
    TypeTag type;
    int value;
} Node;

int fibonacci(int n) {
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;

    int fib[n + 1];
    fib[1] = 0;
    fib[2] = 1;

    for (int i = 3; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    return fib[n];
}

void calc(Node *node) {
    switch (node->type) {
        case ADD:
            printf("ADD: %d\n", node->value);
            break;
        case SUB:
            printf("SUB: %d\n", node->value);
            break;
        case MUL:
            printf("MUL: %d\n", node->value);
            break;
        default:
            printf("Unknown\n");
            break;
    }
}

Node* add(int a, int b) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = ADD;
    node->value = a + b;
    return node;
}

Node* multiply(int a, int b) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = MUL;
    node->value = a * b;
    return node;
}

Node* subtract(Node* a, Node* b) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = SUB;
    if (b == NULL) {
        node->value = fibonacci(a->value);
    } else {
        node->value = a->value - b->value;
    }
    return node;
}

Node* (*makeFunc(TypeTag type))() {
    switch (type) {
        case ADD:
            return add;
        case SUB:
            return (Node* (*)(int))subtract;
        case MUL:
            return multiply;
        default:
            return NULL;
    }
}

void main() {
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);
}