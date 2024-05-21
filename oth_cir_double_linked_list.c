#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }
}

void sortList(Node **head)
{
    if (*head == NULL || (*head)->next == *head)
        return;

    Node *current = *head;
    do
    {
        Node *nextNode = current->next;
        while (nextNode != *head)
        {
            if (current->data > nextNode->data)
            {
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    } while (current->next != *head);
}

void displayList(Node *head)
{
    if (head == NULL)
    {
        printf("List kosong.\n");
        return;
    }
    Node *temp = head;
    do
    {
        printf("Alamat: %p, Data: %d\n", temp, temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    Node *head = NULL;
    int N, data;

    printf("Masukkan jumlah data: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &data);
        insertEnd(&head, data);
    }

    printf("List sebelum pengurutan:\n");
    displayList(head);

    sortList(&head);

    printf("List setelah pengurutan:\n");
    displayList(head);

    return 0;
}