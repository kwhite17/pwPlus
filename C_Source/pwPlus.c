#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum {FALSE=0, TRUE=1} bool;

char * pwHelper(char * pw){
	int newPW = 0;
	int i;
	for (i = 0; i<strlen(pw); i++){
		newPW += pow((double)-1,(double)i + 2) * pw[i] * pow((double)10,(double)strlen(pw)-i-1);
	}
	char * numstr = malloc(sizeof(char) * (intlen(newPW) + 1));
	sprintf(numstr,"%d",newPW);
	numstr[intlen(newPW)] = '\0';
	return numstr;
}

improvedPW(char * pw, int letConv, bool atEnd, bool reverse){
	int pwLen = strlen(pw);
	char * change = malloc(sizeof(char) * (letConv + 1));
	char * remain = malloc(sizeof(char) * (pwLen-letConv + 1));
	if (letConv == 0 || letConv >= strlen(pw)){
		char * finPW = pwHelper(pw);
		printf("The old password is %s, and the new password is %s\n",pw,finPW);
		free(finPW);
	}
	else{
		if (atEnd){
			split(pw,remain,0,pwLen-letConv);
			split(pw,change,pwLen-letConv,pwLen);
			char * numstr = pwHelper(change);
			char * finPW = malloc(sizeof(char) * (pwLen + strlen(numstr) + 1));
			if (!reverse){
				sprintf(finPW,"%s%s%c\n",remain,numstr,'\0');
			}
			else{
				sprintf(finPW,"%s%s%c\n",numstr,remain,'\0');
			}
			printf("The old password is %s, and the new password is %s\n",pw,finPW);
			free(numstr);
			free(finPW);
		}
		else{
			split(pw,remain,letConv,pwLen);
			split(pw,change,0,letConv);
			char * numstr = pwHelper(change);
			char * finPW = malloc(sizeof(char) * (pwLen + strlen(numstr) +1));
			if (!reverse){
				sprintf(finPW,"%s%s%c\n",numstr,remain,'\0');
			}
			else{
				sprintf(finPW,"%s%s%c\n",remain,numstr,'\0');
			}
			printf("The old password is %s, and the new password is %s\n",pw,finPW);
			free(numstr);
			free(finPW);
		}
	}
	free(change);
	free(remain);
}

split (char * src, char * dest, int start, int finish){
	int i;
	for (i = start; i < finish; i++){
		dest[i-start] = src[i];
	}
	dest[finish-start] = '\0';
}

int intlen(int i){
	if (i == 0){
		return 1;
	}
	return floor(log10(abs(i)))+1;
}

int main(int argc, char **argv){
	bool atEnd;
	bool reverse;
	int letConv;
	if (argc == 5){
		letConv = atoi(argv[2]);
		if ((strcmp(argv[3],"True") == 0)||(strcmp(argv[3],"TRUE") == 0)||(strcmp(argv[3],"true") == 0)){
			atEnd = TRUE;
		}
		else{
			atEnd = FALSE;
		}
	if (strcmp(argv[4],"True") == 0||strcmp(argv[4],"TRUE") == 0 || strcmp(argv[4],"true") == 0){
			reverse = TRUE;
		}
		else{
			reverse = FALSE;
		}
		improvedPW(argv[1],letConv,atEnd,reverse);
	}
	else{
		printf("You didn't enter enough arguments, but here are some examples for you.\n");
		improvedPW("boom",2,TRUE,TRUE);
		improvedPW("boom",2,TRUE,FALSE);
		improvedPW("boom",2,FALSE,TRUE);
		improvedPW("boom",2,FALSE,FALSE);
	}
	return 0;
}