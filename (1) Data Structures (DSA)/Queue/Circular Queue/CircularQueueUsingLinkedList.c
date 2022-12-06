//Menu based program on Cicular Queue Using Linked List
//Creation, Enqueue, Dequeue, Display, Count, Peek Front and Rear
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Circular Queue using linked list
typedef struct list
{
    int data;
    struct list *next;
} list;

//creating a list pointer head, which will point to list we will create (currently empty)
list *head = NULL;

list *front = NULL;
list *rear = NULL;

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
    rear->next = (list *)malloc(sizeof(list));
    rear = rear->next;
    rear->data = data;
    rear->next = NULL;
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
    printf("\n%d is deleted from queue ", data);
}

//function to display queue
void display ()
{
    list *temp = head;
    printf("\n\nQueue is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

//count number of elements in queue
int count ()
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

//function to get first element from queue
int peek ()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }

    return front->data;
}

//function to get rear element from the queue
int rearElement ()
{
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }

    return rear->data;
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Count");
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
                printf("\nNumber of elements in queue is %d", count());
                break;

            case 5:
                printf("\nFirst element in queue is %d", peek());
                break;

            case 6:
                printf("\nRear element in queue is %d", rearElement());
                break;

            case 7:
                exit(0);

            default:
                printf("\nInvalid choice");
        }

        printf("\n");
        sleep(2);
    }

    return 0;
}
