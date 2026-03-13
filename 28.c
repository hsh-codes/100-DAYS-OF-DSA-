#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

struct Node *head = NULL;

// Function to create circular linked list
void create(int n)
{
    struct Node *temp, *newnode;
    int i, value;

    for(i = 1; i <= n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp->next = head; // Make it circular
}

// Traversal function
void traverse()
{
    struct Node *temp;

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = head;

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;

    } while(temp != head);

    printf("(Back to Head)\n");
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    create(n);

    printf("Circular Linked List:\n");
    traverse();

    return 0;
}