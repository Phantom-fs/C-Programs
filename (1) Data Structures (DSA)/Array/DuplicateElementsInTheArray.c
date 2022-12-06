//Find the numbers of duplicate elements in a Array of size 10 based on user input
//Coder : Phantom-fs


#include <stdio.h>
#include <unistd.h>

int main()
{
    int arr [10];
    int i, j;
    int temp = 0, count = 0;

    printf("\n************************************************************\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    //can also take complete array at once
    /*

    printf("\nEnter the elements of the array : ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    */

    for (i = 0; i < 10; i++)
    {
       temp = arr[i];

       for (j = i + 1; j < 10; j++)
       {
            if (temp == arr[j])
            {
                count++;
            }

            else 
                continue;
       }
    }

    printf("\nNumber of duplicate elements in Array : %d\n", count);

    sleep(2);

    printf("\n************************************************************\n");

    return 0;    
}
