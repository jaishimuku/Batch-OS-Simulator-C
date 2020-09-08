//
// Created by Mukunda P Jaishi on 9/7/20.
//
#include <stdio.h>
#include <unistd.h>

int main(){
    int i;
    int n = 100;

    for(i = 0 ; i < n; i++){
        printf("# ");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
    return 0;
}
