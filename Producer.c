#include <stdlib.h>
#include <stdio.h> 

int producer(){
    printf("\tI am the producer file\n");
    
    //check if it's your turn
    int t = checkTurn();

    //******** need to fix the loop so it keeps going till the eof


    int pos = 0;
    FILE *dataFile = fopen("mydata.txt", "rt");

    while(t == 0){
        //grab a char from mydata.txt
        fseek(dataFile, pos, SEEK_SET);
        char k = getc(dataFile);

        //take that char and put it the DATA.txt exchanger file
        FILE* exData = fopen("DATA.txt","w");
        putc(k, exData);
        fclose(exData);

        //increment the position that we are at in the file
        pos++;

        //make it ahmed's turn
        FILE* turn = fopen("TURN.txt", "w");
        putc("1", turn);
        fclose(turn);
    }
    fclose(dataFile);
    return 0;
}

int checkTurn(){
    FILE *turn = fopen("TURN.txt", "r");
    char c = fgetc(turn);
    fclose(turn);
    if(c == '0'){
        return 0;
    }
    if(c == '1'){
        return 1;
    }else{
        printf("Error: Can't figure out who's turn it is");
    }
}