#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* deleteKey(struct node* head, int key) {
    
    if (head == NULL)
        return head;

    // If key is at head
    if (head->data == key) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* temp = head;

    while (temp->next != NULL) {
        if (temp->next->data == key) {
            struct node* del = temp->next;
            temp->next = temp->next->next;
            free(del);
            break;
        }
        temp = temp->next;
    }

    return head;
}