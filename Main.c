#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void setTurn();
int producer();
int consumer();

int main(){
    printf("\nWelcome to the program!\n");
    setTurn();
    printf("after setTurn\n");
    int pid = fork();
    if(pid == -1){
        printf("Error: could not execute fork");
        exit(1);
    }
    if(pid == 0)
        producer();
    else
        printf("Running the consumer file\n");
        //consumer();
    
    return 0;
}

void setTurn(){
    FILE* f = fopen("TURN.txt","w"); //creates a new blank file, erasing the old one
    putc('0', f);
}