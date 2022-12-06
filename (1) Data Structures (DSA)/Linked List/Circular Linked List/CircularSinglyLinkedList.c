//Menu based program on Cicular Singly Linked List
//Creation, Insertion, Deletion, Display, Search, Reverse, Count
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//circular linked list
typedef struct list
{
    int data;
    struct list *next;
} list;

//creating a list pointer head, which will point to list we will create (currently empty)
list *head = NULL;

//to create a circular linked list
list* createNode (int data)
{
    list *newNode = (list*)malloc(sizeof(list));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

list* insertNode (int data)
{
    list *newNode = createNode(data);

    //if list is empty
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return head;
    }

    list *temp = head;

    //traversing to the last node (list is not empty)
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

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
        head->next = head;
        return head;
    }

    //if position is 1
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    list *temp = head;
    int i = 1;

    //traversing to the position
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

//deletion from circular linked list
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
    if (temp->data == data && temp->next == head)
    {
        head = NULL;
        free(temp);
        return head;
    }

    //if first element is to be deleted
    if (temp->data == data)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;

        //free the current head
        free(head);

        head = temp->next;
        return head;
    }

    //if element to be deleted is in between
    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    //if last element is to be deleted
    if (temp->next == head)
    {
        prev->next = head;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

//to delete node at a particular position
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
    if (position == 1 && temp->next == head)
    {
        head = NULL;
        free(temp);
        return head;
    }

    //if first element is to be deleted
    if (position == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;

        //free the current head
        free(head);

        head = temp->next;
        return head;
    }

    int i = 1;

    //traversing to the position
    while (i < position)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    //if last element is to be deleted
    if (temp->next == head)
    {
        prev->next = head;
        free(temp);
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

//displaying the circular linked list
void displayList ()
{
    list *temp = head;

    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    printf("\nList is: ");
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\n");
}

//count the number of nodes in circular linked list
int countNodes ()
{
    list *temp = head;
    int count = 0;

    if (temp == NULL)
    {
        return 0;
    }

    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    count++;

    return count;
}

//searching an element in circular linked list
int searchNode (int data)
{
    list *temp = head;
    int position = 1;

    if (temp == NULL)
    {
        return -1;
    }

    while (temp->next != head)
    {
        if (temp->data == data)
        {
            return position;
        }
        temp = temp->next;
        position++;
    }

    if (temp->data == data)
    {
        return position;
    }

    return -1;
}

//to reverse a circular linked list
list* reverseList ()
{
    list *prev = NULL;
    list *current = head;
    list *next = NULL;

    if (current == NULL)
    {
        return NULL;
    }

    while (current->next != head)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    current->next = prev;
    head = current;

    return head;
}

int main ()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Insert node at the end of the list");
        printf("\n2. Insert node at a particular position");
        printf("\n3. Delete node from the list");
        printf("\n4. Delete node from a particular position");
        printf("\n5. Display the list");
        printf("\n6. Count the number of nodes in the list");
        printf("\n7. Search an element in the list");
        printf("\n8. Reverse the list");
        printf("\n9. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                head = insertNode(data);
                break;

            case 2:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                printf("\nEnter the position: ");
                scanf("%d", &position);
                head = insertAt(data, position);
                break;

            case 3:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                head = deleteNode(data);
                break;

            case 4:
                printf("\nEnter the position: ");
                scanf("%d", &position);
                head = deleteAt(position);
                break;

            case 5:
                displayList();
                break;

            case 6:
                printf("\nNumber of nodes in the list: %d", countNodes());
                break;

            case 7:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                position = searchNode(data);
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
