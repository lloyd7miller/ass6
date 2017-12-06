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
    //printf("--> after setTurn\n");
    
    int pid = fork();
    if(pid == -1){
        printf("Error: could not execute fork\n");
        exit(1);
    }
    if(pid != 0){ //executed by the parent
        //printf("Running the producer file\n");
        int check = producer();
        //(check == 0) ? printf("\tsuccess for producer\n"): printf("failure for producer\n");
    }
    if(pid == 0){ //executed by the child
        //printf("Running the consumer file\n");
        int check = consumer();
        //(check == 0) ? printf("\tsuccess for consumer\n") : printf("failure for consumer\n");
    }
    //printf("End of the main method\n");
    printf("\n");
    return 0;
}

void setTurn(int* b){
    if(*b==0){
        FILE* f = fopen("TURN.txt","w+"); //creates a new blank file, erasing the old one
        //printf("\tsetTurn() ran once\n");
        fprintf(f, "0");
        fclose(f);
        *b = 1;
    }else{
        printf("\t\tnahh son\n");
    }
}