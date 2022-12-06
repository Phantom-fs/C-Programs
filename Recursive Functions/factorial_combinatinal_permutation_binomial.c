//Resursion based program on Factorial, Combinational, Permutation and Binomial of two numbers
//Phantom-fs


#include <stdio.h>
#include <unistd.h>

long long int factorial (int n) 
{
  if (n <= 1) 
  {
    return 1;
  }

  return n * factorial(n - 1);
}

long double combination (int n, int k) 
{
  return factorial(n) / (factorial(k) * factorial(n - k));
}

long double permutation (int n, int k) 
{
  return factorial(n) / factorial(n - k);
}

long double binomial (int n, int k) 
{
  return combination(n + k - 1, k);
}
    
int main()
{
  int fac, com1, com2, per1, per2, bin1, bin2;

  printf("\n\nNOTE : This program is for positive integers only and limited size of integers, don't enter long sized integers!");

  //factorial
  printf("\n\n*******************************************************************\n\n"); 

  printf("Enter the number whose factorial is to be found : ");
  scanf("%d", &fac);

  printf("\nFactorial of %d is %lld", fac, factorial(fac));

  sleep(2);

  //combination
  printf("\n\n*******************************************************************\n\n");

  printf("Enter the two numbers whose combination is to be found : ");
  scanf("%d %d", &com1, &com2);

  printf("\nCombination of %d and %d is %.2Lf", com1, com2, combination(com1, com2));

  sleep(2);

  //permutation
  printf("\n\n*******************************************************************\n\n");

  printf("Enter the two numbers whose permutation is to be found : ");
  scanf("%d %d", &per1, &per2);

  printf("\nPermutation of %d and %d is %.2Lf", per1, per2, permutation(per1, per2));

  sleep(2);

  //binomial
  printf("\n\n*******************************************************************\n\n");

  printf("Enter the two numbers whose binomial is to be found : ");
  scanf("%d %d", &bin1, &bin2);

  printf("\nBinomial of %d and %d is %.2Lf", bin1, bin2, binomial(bin1, bin2));

  sleep(2);

  printf("\n\n*******************************************************************\n\n");

  return 0;
}
