#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

struct Node* rotateRight(struct Node* head, int k)
{
    if(head == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    while(temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    k = k % length;

    int steps = length - k;

    struct Node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct Node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

void display(struct Node* head)
{
    struct Node* temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter value of k (rotation): ");
    scanf("%d", &k);

    printf("\nOriginal Linked List:\n");
    display(head);

    head = rotateRight(head, k);

    printf("\nRotated Linked List:\n");
    display(head);

    return 0;
}