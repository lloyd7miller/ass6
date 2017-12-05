#include <stdlib.h>
#include <stdio.h>

int producer(){
    printf("\tI am the producer file\n");
    
    FILE* turn = fopen("TURN.txt","r");
    //need to keep track of how far we got into the file...
    //--> nvm, we just shove the char into the DATA.txt file
    char c = fgetc(turn);
    int pos = 0;
    FILE *dataFile = fopen("mydata.txt", "rt");

    while(c == '0'){
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