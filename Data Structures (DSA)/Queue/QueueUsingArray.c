//Menu based program on Queue Using Array
//Creation, Enqueue, Dequeue, Display, Count, Peek Front and Rear
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Queue using array
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

//function to check if queue is full
int isFull ()
{
    if (front == 0 && rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

//function to check if queue is empty
int isEmpty ()
{
    if (front == -1)
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
        front = 0;
        rear = 0;
        queue[rear] = data;
        return;
    }

    //if queue is not empty
    rear++;
    queue[rear] = data;
}

//function to delete an element from queue
void dequeue ()
{
    int data;

    //if queue is empty
    if (isEmpty())
        printf("\nQueue is empty\n");

    //if queue has only one element
    if (front == rear)
    {
        data = queue[front];
        front = -1;
        rear = -1;
        
        printf("\n%d removed from queue\n", data);
    }

    //if queue has more than one element
    data = queue[front];
    front++;
    printf("\n%d removed from queue\n", data);
}

//function to display the queue
void displayQueue ()
{
    int i;

    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue is: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

//function to count the number of elements in queue
int count ()
{
    int i, count = 0;

    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return 0;
    }

    for (i = front; i <= rear; i++)
    {
        count++;
    }

    return count;
}

//function to display the front element of queue
void peek ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nFront element is: %d\n", queue[front]);
}

//function to display the rear element of queue
void rearElement ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nRear element is: %d\n", queue[rear]);
}

int main ()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display queue");
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
                displayQueue();
                break;

            case 4:
                printf("\nNumber of elements in queue: %d\n", count());
                break;

            case 5:
                peek();
                break;

            case 6:
                rearElement();
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
