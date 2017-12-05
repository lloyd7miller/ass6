#include <stdlib.h>
#include <stdio.h>

int producer(){
    FILE* turn = fopen("TURN.txt","rt");
    //need to keep track of how far we got into the file...
    //--> nvm, we just shove the char into the DATA.txt file
    char c = fgetc(turn);
    while(c != '0'){
        continue;
    }
    
}