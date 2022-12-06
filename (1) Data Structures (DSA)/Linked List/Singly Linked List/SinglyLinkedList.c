//Menu based program on Singly Linked List
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
} list;

//creating a list pointer head, which will point to list we will create (currently empty)
list *head = NULL;

//function to create a node
list* createNode (int data)
{
    list *newNode = (list*)malloc(sizeof(list));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to insert an element in list
list* insert (int data)
{
    //if list is empty
    if (head == NULL)
    {
        head = (list *)malloc(sizeof(list));
        head->data = data;
        head->next = NULL;
        return head;
    }

    //if list is not empty
    list *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = createNode(data);
    return temp->next;
}

//to insert node at a particular position
list* insertAt (int data, int position)
{
    //if list is empty
    if (head == NULL)
    {
        head = (list *)malloc(sizeof(list));
        head->data = data;
        head->next = NULL;
        return head;
    }

    //if list is not empty
    list *temp = head;
    list *newNode = createNode(data);

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return temp->next;
}

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

    //traversing to the node to be deleted
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    //if element not found
    if (temp == NULL)
    {
        printf("\nElement not found\n");
        return NULL;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

//to delete node at a particular position
list* deleteNodeAt (int position)
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

    //traversing to the node to be deleted
    for (int i = 0; i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    //if element not found
    if (temp == NULL)
    {
        printf("\nElement not found\n");
        return NULL;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void printList (list *head)
{
    list *temp = head;

    printf("\nList is: ");

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

//count numbers of elements in the list
int count (list *head)
{
    list *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

//to search an element in the list
int search (int data)
{
    list *temp = head;
    int position = 0;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return position;
        }

        position++;
        temp = temp->next;
    }

    return -1;
}

//to reverse the list
list* reverse (list *head)
{
    list *prev = NULL;
    list *current = head;
    list *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Insert an element in list");
        printf("\n2. Insert an element at a particular position");
        printf("\n3. Delete an element from list");
        printf("\n4. Delete an element from a particular position");
        printf("\n5. Print list");
        printf("\n6. Count number of elements in list");
        printf("\n7. Search for an element in list");
        printf("\n8. Reverse the list");
        printf("\n9. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &data);
                printf("\nEnter position: ");
                scanf("%d", &position);
                insertAt(data, position);
                break;

            case 3:
                printf("\nEnter element to be deleted: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 4:
                printf("\nEnter position: ");
                scanf("%d", &position);
                deleteNodeAt(position);
                break;

            case 5:
                printList(head);
                break;

            case 6:
                printf("\nNumber of elements in list: %d", count(head));
                break;

            case 7:
                printf("\nEnter element to be searched: ");
                scanf("%d", &data);
                search(data);
                break;

            case 8:
                head = reverse(head);
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
}
