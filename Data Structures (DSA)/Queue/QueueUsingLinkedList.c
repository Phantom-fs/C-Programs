//Menu based program on Queue Using Linked List
//Creation, Enqueue, Dequeue, Display, Count, Peek Front and Rear
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Queue using using linked list
typedef struct list
{
    int data;
    struct list *next;
} list;

//creating a list pointer head, which will point to list we will create (currently empty)
list *head = NULL;
list *rear = NULL;
list *front = NULL;

//function to check if queue is empty
int isEmpty ()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

//function to check if queue is full
int isFull ()
{
    list *temp = (list *)malloc(sizeof(list));
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}

//function to insert an element in queue
void enqueue (int data)
{
    //if queue is full
    if (isFull())
    {
        printf("\nQueue is full\n");
        return;
    }

    //if queue is empty
    if (isEmpty())
    {
        head = (list *)malloc(sizeof(list));
        head->data = data;
        head->next = NULL;
        rear = head;
        front = head;
        return;
    }

    //if queue is not empty
    list *temp = (list *)malloc(sizeof(list));
    temp->data = data;
    temp->next = NULL;
    rear->next = temp;
    rear = temp;
}

//function to delete an element from queue
void dequeue ()
{
    int data;

    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    //if queue is not empty
    list *temp = head;
    data = temp->data;
    head = head->next;
    free(temp);
    printf("\n%d deleted from queue\n", data);
}

//function to display queue
void display ()
{
    list *temp = head;

    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    //if queue is not empty
    printf("\nQueue is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//number of elements in queue
int size ()
{
    int count = 0;
    list *temp = head;

    //if queue is empty
    if (isEmpty())
    {
        return count;
    }

    //if queue is not empty
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

//function to get front element of queue
int peek ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    //if queue is not empty
    return front->data;
}

//function to display rear element of queue
int rearElement ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return -1;
    }

    //if queue is not empty
    return rear->data;
}

int main()
{
    int choice, data, position;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Size");
        printf("\n5. Peek");
        printf("\n6. Rear element");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nSize of queue is: %d", size());
                break;

            case 5:
                printf("\nFront element of queue is: %d", peek());
                break;

            case 6:
                printf("\nRear element of queue is: %d", rearElement());
                break;

            case 7:
                exit(0);
                
            default:
                printf("\nInvalid choice\n");
        }

        printf("\n");
        sleep(2);

    }
}
