#include <stdlib.h>
#include <stdio.h> 

int checkTurn();

int producer(){
    //printf("\tI am the producer file\n");

    //keep track of how far we have read in mydata.txt
    int pos = 0;

    //open up the file we will take chars from
    FILE *dataFile = fopen("mydata.txt", "rt");

    while(1){
        //check if it's your turn
        int t = checkTurn();

        if(t == 0){
            //grab a char from mydata.txt
            fseek(dataFile, pos, SEEK_SET);
            char k = getc(dataFile);    
            //printf("k = %c\n", k);

            //take that char and put it the DATA.txt exchanger file
            FILE* exData = fopen("DATA.txt","w");

            if(exData == NULL){
                printf("Error: could not open mydata.txt\n");
                exit(1);
            }

            fputc(k, exData);
            fclose(exData);

            //increment the position that we are at in the file
            pos++;

            //make it ahmed's turn
            FILE* turn = fopen("TURN.txt", "w");
            if (turn == NULL){
                printf("Error: could not open TURN.txt\n");
                exit(1);
            }
            putc('1', turn);
            fclose(turn);

            //once we have passed on the EOF to the consumer,
            //we can end the producer program
            if (k == EOF){
                //printf("END PRODUCER\n");
                fclose(dataFile);
                return 0;
            }
        }
    }
    return -1;
}

int checkTurn(){
    FILE *turn;
    
    //while I cannot open the file, the busy loop will keep looping
    while((turn = fopen("TURN.txt", "r")) == NULL);
    
    char c = fgetc(turn);
    fclose(turn);
    if(c == '0'){
        return 0;
    }
    if(c == '1'){
        return 1;
    }else{
        //printf("Error: Can't figure out who's turn it is");
        return -1;
    }
}