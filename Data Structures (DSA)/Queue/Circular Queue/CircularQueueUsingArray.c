//Menu based program on Cicular Queue Using Array
//Creation, Enqueue, Dequeue, Display, Count, Peek Front and Rear
//coder: Phantom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//circular queue using array
#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

//function to check if queue is full
int isFull ()
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
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
        printf("\n\nQueue is full\n");
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
    rear = (rear + 1) % MAX;
    queue[rear] = data;

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

    //if queue has only one element
    if (front == rear)
    {
        data = queue[front];
        front = -1;
        rear = -1;
        printf("\nDeleted element is %d\n", data);
        return;
    }

    //if queue has more than one element
    data = queue[front];
    front = (front + 1) % MAX;
    printf("\nDeleted element is %d\n", data);
}

//function to display queue
void display ()
{
    int i;

    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
        return;
    }

    //if queue is not empty
    printf("\nQueue is: ");
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
    }

    printf("%d  ", queue[i]);
}

//number of elements in queue
int count ()
{
    int i, count = 0;

    //if queue is empty
    if (isEmpty())
    {
        return 0;
    }

    //if queue is not empty
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        count++;
    }

    count++;

    return count;
}

//function to get front element of queue
int frontElement ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }

    return queue[front];
}

//function to get rear element of queue
int rearElement ()
{
    //if queue is empty
    if (isEmpty())
    {
        printf("\nQueue is empty");
        return -1;
    }

    return queue[rear];
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Count");
        printf("\n5. Front element");
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
                printf("\nFront element is %d", frontElement());
                break;

            case 6:
                printf("\nRear element is %d", rearElement());
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
