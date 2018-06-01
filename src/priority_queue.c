//
// Created by puzankova 30.05.18
//

#include "priority_queue.h"

struct Node {
    double value;
    int key;
    struct Node *next;
    struct Node *prev;

};

struct Node *queue = NULL; // it is your queue to work with it
static int size_of_the_queue = 0;

int insert(double value, int key) {
    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the queue
    //  2 - other

    // the queue size is 100 elements

    /* YOUR CODE */
    if (size_of_the_queue >= MAX_QUEUE_SIZE) {
        return 1;
    } else {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->key = key;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (queue == NULL) {
            queue = new_node;
        } else {
            struct Node *current = queue;
            while (current->next != NULL || key > (current->key)) {
                current = current->next;
            }

            if (current->next == NULL && key > current->key) {
                current->next = new_node;
                new_node->prev = current;
            } else {
                current->prev->next = new_node;
                new_node->prev = current->prev;
                new_node->next = current;
                current->prev = new_node;
            }
        }
        ++size_of_the_queue;
        return 0;
    }
    return 2;
}

double extract_min() {
    // returns the min value and delete it from queue
    // if queue is empty returns -infinity and print error message to the screen
    /* YOUR CODE */

    if (queue == NULL) {
        printf("StackUnderflow: STACK IS EMPTY\n");
        return -INFINITY;
    } else {
        double value_to_return = queue->value;
        struct Node *old_node = queue;
        queue = old_node->next;

        if (queue != NULL) {
            queue->prev = NULL;
        }

        free(old_node);
        --size_of_the_queue;
        return value_to_return;
    }
}
