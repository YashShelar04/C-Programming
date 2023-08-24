#include <stdio.h>

int prime_numbers(int num){
    if(num <= 1){
     return 1;
    }
    for(int i = 2; i <= num / 2; i++){
        if (num % i == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Prime numbers between 50 and 100 are:\n ");

    for (int i = 50; i <= 100; i++) {
        if (prime_numbers(i)==0) {
            printf("%d ", i);
        }
    }

    return 0;
}
