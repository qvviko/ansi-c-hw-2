//
// Created by puzankova 30.05.18
//

#include "stack.h"

struct Node {
    double value;
    struct Node *next;
    struct Node *prev;

};

struct Node *stack = NULL; // it is your stack to work with it

int size();

int push(double value) {
    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the stack
    //  2 - other

    // the stack size is 50 elements

    //We need to check if the size of the stack is already 50
    if (stack == NULL) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = NULL;
        stack = new_node;
        return 0;
    } else if (size() != 50) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = NULL;

        struct Node *old = stack;

        stack = new_node;
        stack->next = old;
        old->prev = new_node;
        return 0;
    } else {
        return 1;
    }
    return 2;
}

double pop() {
    // returns top value and delete it from stack
    // if stack is empty returns -infinity and print error message to the screen
    /* YOUR CODE */
    if (stack == NULL) {
        printf("StackUnderflow: STACK IS EMPTY\n");
        return -INFINITY;
    } else {
        double value_to_return = stack->value;
        struct Node *old_node = stack;

        stack = stack->next;
        if (stack != NULL) {
            stack->prev = NULL;
        }

        free(old_node);
        return value_to_return;
    }

}

double pick() {
    // just returns the top value
    // if stack is empty returns -infinity and print error message to the screen
    /* YOUR CODE */
    if (stack == NULL) {
        printf("StackUnderflow: STACK IS EMPTY\n");
        return -INFINITY;
    } else {
        return stack->value;
    }
}

int size() {
    if (&stack == NULL) {
        return 0;
    } else {
        struct Node *current = stack;
        int i = 1;
        while (current->next != NULL) {
            ++i;
            current = current->next;
        }
        return i;
    }
}