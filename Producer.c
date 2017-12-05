#include <stdlib.h>
#include <stdio.h>

int producer(){
    FILE* turn = fopen("TURN.txt","r");
    //need to keep track of how far we got into the file...
    //--> nvm, we just shove the char into the DATA.txt file
    char c = fgetc(turn);
    int i = 0;
    while(c == '0'){
        FILE* dataFile = fopen("mydata.txt","rt");
        if(i == 5){
            printf("Ran %d times\n", i);
            return 0;
        }
        i++;
    }
    return 0;
}