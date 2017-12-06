#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void setTurn();
//function prototypes from other files are necessary!
int producer();
int consumer();

int main(){
    printf("\n*** Welcome to the program! ***\n\n");
    
    int test = 0;
    int* ptr = &test;
    setTurn(ptr);
    
    int pid = fork();
    if(pid == -1){
        printf("Error: could not execute fork\n");
        exit(1);
    }
    if(pid != 0){ //executed by the parent
        int check = producer();
    }
    if(pid == 0){ //executed by the child
        int check = consumer();
    }
    printf("\n");
    return 0;
}

void setTurn(int* b){
    if(*b==0){
        FILE* f = fopen("TURN.txt","w+"); //creates a new blank file, erasing the old one
        fprintf(f, "0");
        fclose(f);
        *b = 1;
    }else{
        printf("\t\tError: setTurn failed\n");
        exit(1);
    }
}