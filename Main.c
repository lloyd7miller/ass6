#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void setTurn();
int producer();
int consumer();

int main(){
    printf("\nWelcome to the program!\n");
    
    int test = 0;
    int* ptr = &test;
    setTurn(ptr);
    printf("after setTurn\n");
    
    int pid = fork();
    if(pid == -1){
        printf("Error: could not execute fork");
        exit(1);
    }
    if(pid == 0){
        printf("Running the producer file\n");
        producer();
    }
    else{
        printf("Running the consumer file\n");
        consumer();
    }
    
    return 0;
}

void setTurn(int* b){
    if(*b==0){
        FILE* f = fopen("TURN.txt","w+"); //creates a new blank file, erasing the old one
        printf("\tsetTurn() ran once\n");
        fprintf(f, "0");
        fclose(f);
        *b = 1;
    }else{
        printf("\t\tnahh son\n");
    }
}