#include <stdlib.h>
#include <stdio.h>

int consumer(){
	//printf("\tI am the consumer file\n");

	char turn, current;
	FILE *t;

	while(1){
		while((t = fopen("TURN.txt" , "r+")) == NULL);
		turn = fgetc(t);
		fclose(t);
		if(turn == '1'){
			FILE *f = fopen("DATA.txt", "r");
			current = fgetc(f);
			if(current == EOF)
				return 0;
			printf("%c", current);
			fclose(f);

			// if (current == EOF){
			// 	//printf("END CONSUMER\n");
			// 	return 0;
			// }

			t = fopen("TURN.txt", "w");
			turn = '0';
			fputc(turn, t);

			fclose(t);
		}
	}
	return 0 ;
}
