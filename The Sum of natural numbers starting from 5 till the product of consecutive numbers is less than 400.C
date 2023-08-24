#include <stdio.h>

int Fibonacci_number(int num) {
   int prev = 0, curr = 1, next = 1;
   while (next < num) {
      prev = curr;
      curr = next;
      next = prev + curr;
   }
   return (next == num);
}

int main() {
   int num;
   printf("Enter a number to check if it is part of the Fibonacci series: ");
   scanf("%d", &num);
   if (Fibonacci_number(num)==1) {
      printf("%d is part of the Fibonacci series\n", num);
   } else {
      printf("%d is not part of the Fibonacci series\n", num);
   }
   return 0;
}
