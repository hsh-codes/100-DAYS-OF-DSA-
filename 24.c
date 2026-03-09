#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    
    struct Node* dummy = createNode(0);
    struct Node* tail = dummy;

    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            tail->next = createNode(l1->data);
            l1 = l1->next;
        } else {
            tail->next = createNode(l2->data);
            l2 = l2->next;
        }
        tail = tail->next;
    }

    while(l1 != NULL) {
        tail->next = createNode(l1->data);
        l1 = l1->next;
        tail = tail->next;
    }

    while(l2 != NULL) {
        tail->next = createNode(l2->data);
        l2 = l2->next;
        tail = tail->next;
    }

    return dummy->next;
}

void display(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    struct Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    struct Node* merged = mergeLists(l1, l2);

    printf("Merged Linked List:\n");
    display(merged);

    return 0;
}