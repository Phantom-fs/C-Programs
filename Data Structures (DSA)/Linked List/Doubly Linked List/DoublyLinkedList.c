//Menu based program on Doubly Linked List
//Creation, Insertion, Deletion, Display, Search, Reverse, Count
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Node structure
typedef struct list
{
    int data;
    struct list *next;
    struct list *prev;
} list;

//creating a list pointer head, which will point to list we will create (currently empty)
list* head = NULL;

//function to create a node
list* createNode (int data)
{
    list *newNode = (list*)malloc(sizeof(list));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

list* insertNode (int data)
{
    list *newNode = createNode(data);

    //if list is empty
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    list *temp = head;

    //traversing to the last node (list is not empty)
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

//to insert node at a particular position
list* insertAt (int data, int position)
{
    list *newNode = createNode(data);

    //if list is empty
    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    //if list is not empty
    list *temp = head;

    //traversing to the position
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next->prev = newNode;

    return head;
}

//deletion from doubly linked list
list* deleteNode (int data)
{
    list *temp = head;
    list *prev = NULL;

    //if list is empty
    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }

    //if only one element in list
    if (temp->data == data)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    //if more than one element in list
    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    //if element is not found
    if (temp == NULL)
    {
        printf("\nElement not found\n");
        return head;
    }

    //if last element
    if (temp->next == NULL)
    {
        prev->next = NULL;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);

    return head;
}

//to delete a node at a particular position
list* deleteAt (int position)
{
    list *temp = head;
    list *prev = NULL;

    //if list is empty
    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }

    //if only one element in list
    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return head;
    }

    //if more than one element in list
    for (int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    //if element is not found
    if (temp == NULL)
    {
        printf("\nElement not found\n");
        return head;
    }

    //if last element
    if (temp->next == NULL)
    {
        prev->next = NULL;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);

    return head;
}

void printList ()
{
    list *temp = head;

    printf("\nList is: ");

    //if list is empty
    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    //traversing to the last node (list is not empty)
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

//count the number of nodes in the list
int countNodes ()
{
    list *temp = head;
    int count = 0;

    //if list is empty
    if (temp == NULL)
    {
        return 0;
    }

    //traversing to the last node (list is not empty)
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

//to search for an element in the list
int search (int data)
{
    list *temp = head;
    int count = 0;

    //if list is empty
    if (temp == NULL)
    {
        return -1;
    }

    //traversing to the last node (list is not empty)
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return count;
        }
        count++;
        temp = temp->next;
    }

    return -1;
}

//to reverse the list
list* reverseList ()
{
    list *temp = head;
    list *prev = NULL;
    list *next = NULL;

    //if list is empty
    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return NULL;
    }

    //if only one element in list
    if (temp->next == NULL)
    {
        return head;
    }

    //if more than one element in list
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }

    head = prev;

    return head;
}

int main ()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Insert node at the end of the list");
        printf("\n2. Insert node at a particular position");
        printf("\n3. Delete node");
        printf("\n4. Delete node at a particular position");
        printf("\n5. Print list");
        printf("\n6. Count the number of nodes in the list");
        printf("\n7. Search for an element in the list");
        printf("\n8. Reverse the list");
        printf("\n9. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                head = insertNode(data);
                break;

            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                printf("\nEnter position: ");
                scanf("%d", &position);
                head = insertAt(data, position);
                break;

            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                head = deleteNode(data);
                break;

            case 4:
                printf("\nEnter position: ");
                scanf("%d", &position);
                head = deleteAt(position);
                break;

            case 5:
                printList();
                break;

            case 6:
                printf("\nNumber of nodes in the list is: %d\n", countNodes());
                break;

            case 7:
                printf("\nEnter data: ");
                scanf("%d", &data);
                position = search(data);
                if (position == -1)
                {
                    printf("\nElement not found\n");
                }
                else
                {
                    printf("\nElement found at position %d\n", position);
                }
                break;

            case 8:
                head = reverseList();
                printf("\nList reversed\n");
                break;

            case 9:
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }

        printf("\n");
        sleep(2);
    }

    return 0;
}
