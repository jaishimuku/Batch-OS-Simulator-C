//
// Created by Mukunda P Jaishi on 9/7/20.
//

#include <stdio.h>
#include <unistd.h>

int main(){
    int i;
    int sum = 0;

    for(i = 1; i < 11; i++){
        sum += i;
        printf("%d  ", sum);
        fflush(stdout);
        sleep(1);
    }

    printf("\nSum from 1 to 10 is %d.\n", sum);
    return 0;
}

