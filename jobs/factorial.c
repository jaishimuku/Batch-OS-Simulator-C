//
// Created by Mukunda P Jaishi on 9/7/20.
//
#include <stdio.h>
#include <unistd.h>

int main(){
    int i;
    int n = 10;
    int factorial = 1;

    for(i = 1; i <= n; i++){
        factorial *= i;
        printf("%d ", factorial);
        fflush(stdout);
        sleep(1);
    }
    printf("\nFactorial of 10 is : %d\n", factorial);
    return 0;
}
