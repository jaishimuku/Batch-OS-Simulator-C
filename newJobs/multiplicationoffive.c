//
// Created by Mukunda P Jaishi on 9/7/20.
//
#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    int n = 5;
    for (i = 1; i <= 10; ++i) {
        fflush(stdout);
        sleep(1);
        printf("%d * %d = %d \n", n, i, n * i);
    }
    return 0;
}
