//Menu based program on Queue using struct and array in it
//Creation, Enqueue, Dequeue, Display, Count, Peek Front and Rear
//Coder : Pahntom-fs


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//circular queue using linked list and array
typedef struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
} queue;

//create queue
queue *createQueue(int size)
{
    queue *q = (queue *)malloc(sizeof(queue));

    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(q->size * sizeof(int));
    return q;
}

int isEmpty (queue *q)
{
  if (q->front == -1 && q->rear == -1)
    return 1;
  else
    return 0;
}

int isFull (queue *q)
{
  if ((q->rear + 1) % q->size == q->front)
    return 1;
  else
    return 0;
}

void enqueue (queue *q, int data)
{
  if (isFull(q))
    printf("Queue is full");

  else
  {
    if (isEmpty(q))
    {
      q->front = q->rear = 0;
      q->arr[q->rear] = data;
    }
    else
    {
      q->rear = (q->rear + 1) % q->size;
      q->arr[q->rear] = data;
    }
  }
}

void dequeue (queue *q)
{
  if (isEmpty(q))
    printf("Queue is empty");

  else
  {
    if (q->front == q->rear)
      q->front = q->rear = -1;
    else
      q->front = (q->front + 1) % q->size;
  }
}

void display (queue *q)
{
  if (isEmpty(q))
    printf("Queue is empty");

  else
  {
    int i = q->front;
    while (i != q->rear)
    {
      printf("%d\t", q->arr[i]);
      i = (i + 1) % q->size;
    }
    printf("%d ", q->arr[i]);
  }
}

//count the number of elements in the queue
int count (queue *q)
{
  if (isEmpty(q))
    return 0;

  else
  {
    int i = q->front;
    int count = 0;
    while (i != q->rear)
    {
      count++;
      i = (i + 1) % q->size;
    }
    count++;
    return count;
  }
}

//front element of the queue
int front (queue *q)
{
  if (isEmpty(q))
    return -1;

  else
    return q->arr[q->front];
}

//rear element of the queue
int rear (queue *q)
{
  if (isEmpty(q))
    return -1;

  else
    return q->arr[q->rear];
}

int main ()
{
  int choice, data;

  queue *q = createQueue(10);

  while (1)
  {
    printf("\n1. Enqueue");
    printf("\n2. Dequeue");
    printf("\n3. Display");
    printf("\n4. Count");
    printf("\n5. Front");
    printf("\n6. Rear");
    printf("\n7. Exit");

    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);

    printf("\n");

    switch (choice)
    {
      case 1:
        printf("\nEnter the data : ");
        scanf("%d", &data);
        enqueue(q, data);
        break;

      case 2:
        dequeue(q);
        printf("\nDequeued");
        break;

      case 3:
        display(q);
        break;

      case 4:
        printf("\nNumber of elements in the queue : %d", count(q));
        break;

      case 5:
        printf("\nFront element of the queue : %d", front(q));
        break;

      case 6:
        printf("\nRear element of the queue : %d", rear(q));
        break;

      case 7:
        exit(0);

      default:
        printf("\nInvalid choice");
    }

    printf("\n");
    sleep(2);
  }
}
