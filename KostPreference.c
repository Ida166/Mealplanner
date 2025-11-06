#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Laver en liste af muligheder

int options[2] = {1,0};

//Laver et seperat array til at give indexene navne. Vi kan muligvis lave options om til et struct

char optionNames[2][7] = {
	"Koed",
	"Vegetar"
};

char *getToggleString(int value) {
	if (value == 0){
		return "Fra";
	}
	return "Til";
}

void listOptions() {

	//Print intro text
	printf("Vaelg kost praeference. Tast 'done' naar du er faerdig\n");

	//Hop her til når brugeren har indstillet deres kostpræference
vaelg_mulighed:
	printf("\n");

	//Print mulighederne
	for (int i = 0; i < 2;i++){
		printf("[%d]... %s...%s\n",i,optionNames[i],getToggleString(options[i]));
	}

	int optionSelect;
	
	char *p, s[100];
	//Få fat på brugerens input via fgets
	while(fgets(s,sizeof(s),stdin)){

		//Check om brugerens er "done"
		char inputText[100];
		strcpy(inputText,s);
		inputText[strlen(inputText)-1] = '\0';

		char compareText[] = "done";
		int result = strcmp(inputText,compareText);

		//Hvis det er så hop til slutningenen af functionen
		if (result == 0){
			goto end;
		}

		//Inputtet var ikke "done", så converter s til et int
		optionSelect = strtol(s, &p, 10);

		if (p == s || *p != '\n' || !(optionSelect >= 0 && optionSelect < 2)){
			printf("Ikke et valid input\n");
		} else break;
	}

	//Sæt indstillings værdi
	if (options[optionSelect] == 0){
		options[optionSelect] = 1;
	} else {
		options[optionSelect] = 0;
	}

	goto vaelg_mulighed;

end:
	printf("\n");
}