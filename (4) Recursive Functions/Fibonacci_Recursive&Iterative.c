/*
FIBONACCI SERIES (both using recursion and iteration)
*/
//iterative Fibonacci Program is provided in comments after the program
//Coder: Phantom-fs

#include <stdio.h>
#include <unistd.h>

//fibonacci series using recursion
long long int fibonacci (int n) 
{
  if (n <= 1) 
  {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main ()
{
  int n, i = 0;

  printf("\n\nNOTE: The number of terms should be greater than 1 and don't provide with very large numbers of terms");

  printf("\n\n******************************************************************");

  printf("\n\nEnter the number of terms: ");
  scanf("%d", &n);

  printf("\n");

  printf("\nFibonacci Series: \n\n");

  //printing the first term
  printf("0\n");

  for (i = 1; i < n; i++)
  {
    printf("%lld\t", fibonacci(i));

    //printing new line after every 8 terms
    if(i % 6 == 0)
      printf("\n");
  }

  sleep(3);
  printf("\n\n");

  return 0;
}

/*
 * METHOD 2 : using iterative method

 * CODE :

* -------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int main ()
{
  int i;
  double z;        //can also use long double as huge numbers to be printed
  double x = 1;    //first term is 1 in our loop sequence
  double y = 0;
  int longetivity;

  printf("\n\n******************************************************************");

  printf("\nHow many Fibonacci Numbers you want to print : ");
  scanf(" %d", &longetivity);

  printf("\nFIBONACCI SERIES:\n");

  printf("0");   //printing the part that was excluded, if we start from 0, then loop of 0 + 0 + .... will be printed

  for(i = 1; i < longetivity; i++)   //starting from 1 as 0 is not included in sequence, and is already printed
  {
    z = x + y;  //the term to print z is sum of two previous terms i.e. x (first term) + y (second term)

    printf("   +   %0.0lf", z);  //print the term z, 0.0%lf for not printing decimal points

    x = y;  //assigning the first term (x) with the value of y, so that when loop repeats we have the first term is previous term

    y = z;  //assigning the second term (y) with the value of z(the term printed), will be the previous value in next term printing
  }

  printf("\n\n******************************************************************\n");

  return 0;

}

* -------------------------------------------------------------------------------------------------------------------------------------

 * EXPLANATION :

 * The way used in this program is of reassigning, we know a number in Fibonacci sequence is sum of previous two numbers,
 * now x is the first number and y's the second term after printing the current term (z), 
 * we reassign x and y, to the new terms i.e. now x is y and y is z,
 * as each number is sum of previous two numbers, this way, we move ahead in the sequence

  x = 1
  y = 1

  z = 2 (new term print)

 * reassign

  x (first term) = 1 (value of y as x = y)
  y (second term) = 2 (value of z as y = z)

 * this way we have the terms needed for printing the next term, loop repeats

  z(new term) = x (1) + y (2)
  z = 3 (new term print)

 * this way the whole series can be printed
*/
