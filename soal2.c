#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definisi Node.
typedef struct Node 
{
    int nilai;
    struct Node *next;
} Node;
    
void clearTerminal()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk membuat node baru
Node* createNode(int nilai) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memory gagal\n");
        exit(1);
    }
    newNode->nilai = nilai;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan node di akhir linked list
void appendNode(Node** head, int nilai) 
{
    Node* newNode = createNode(nilai);
    if (*head == NULL) 
        *head = newNode;
    else 
    {
        Node* current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

Node* partition(Node* head, int x) 
{
    Node* leftPart = NULL;
    Node* leftTail = NULL;
    Node* rightPart = NULL;
    Node* rightTail = NULL;

    while (head != NULL)
    {
        if (head->nilai < x)
        {
            if (leftPart == NULL)
                leftPart = leftTail = head;
            
            else
            {
                leftTail->next = head;
                leftTail = leftTail->next;
            }
        }
        
        else
        {
            if (rightPart == NULL)
                rightPart = rightTail = head;

            else
            {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
        }
        head = head->next;
    }

    if (rightPart != NULL)
        rightTail->next = NULL;
    
    if (leftPart != NULL)
        leftTail->next = rightPart;
    else return rightPart;

    return leftPart;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) 
{
    Node* current = head;
    printf("[");
    while (current != NULL) 
    {
        printf("%d", current->nilai);
        if (current->next)
            printf(", ");
        current = current->next;
    }
    printf("]\n");
}

// Fungsi untuk membebaskan memori linked list
void freeList(Node* head) 
{
    Node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    clearTerminal();
    Node* list = NULL;
    appendNode(&list, 4);
    appendNode(&list, 2);
    appendNode(&list, 8);
    appendNode(&list, 1);
    appendNode(&list, 5);

    Node* result = partition(list, 3);

    printList(result);

    return 0;
}