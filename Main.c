#include <stdlib.h>
#include <stdio.h>

int main(){
    int pid = fork();
    if(pid != 0)
        producer();
    if(pid == 0)
        consumer();
    return 0;
}