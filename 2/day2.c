#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct format {
	int min;
	int max;
	char signChar;
	char* pass;
}; typedef struct format format;

//Will take a char array and create a struct
format create_struct(char* line) {
	format retval;

	retval.min = atoi(strtok(line, "-"));
	retval.max = atoi(strtok(NULL, " "));
	retval.signChar = *strtok(NULL, ":");
	retval.pass = strtok(NULL, "\n\r\v\f");

	return retval;
}

int sled(format f) {
	int charCounter = 0;
	size_t len = strlen(f.pass);
	//Check if each character matches the sign char
	for(int i = 0; i < len;i++) {
		if((char)f.pass[i] == f.signChar) {
			charCounter++;
		}
	}

	//Check If character count is valid
	if(charCounter < f.min || charCounter > f.max) {
		return 0;
	}
	return 1;
}

int toboggan(format f) {
	if (f.pass[f.min] == f.signChar ^ f.pass[f.max] == f.signChar) {
		return 1;
	}
	return 0;
}

int main (void) {

	FILE* fp = fopen("input", "r");
	//The buffer array in which we will write each line
	char buffer[30];
	format f;
	int character; //fgetc return unsigned char cast to an int
	int i,n,k = 0;
	int sledc = 0;
	int tobogganc = 0;
	while((character = fgetc(fp)) != EOF) {
		//Check if we reached linebreak (end of line)
		if(character == '\n') {
			buffer[i++] = '\n'; //strtok will read until ’\n'
			format f = create_struct(buffer);

			n = sled(f);
			sledc += n;
			
			k = toboggan(f);
			tobogganc += k;
			//Empty the buffer
			memset(buffer, 0, 30);
			i = 0;
		}
		else {
			//Fill our buffer with single chars read from input file
			buffer[i++] = (char)character;
		}

	}
	fclose(fp);
	printf("valid sled password: %d\n", sledc);
	printf("valid toboggan password: %d\n", tobogganc);

}

