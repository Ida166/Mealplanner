#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "KostPreference.h"

Diet_Preference User_Diet_Preference = ALL;

//Laver et seperat array til at give indexene navne. Vi kan muligvis lave options om til et struct

int dietPreferenceAmount = 3;

char optionNames[3][10] = {
	"Alle",
	"Vegetar",
	"Vegan"
};


void listOptions() {

	//Print intro text
	printf("Vaelg kost praeference.\n");

	printf("\n");

	//Print mulighederne
	for (int i = 0; i < dietPreferenceAmount;i++){
		printf("[%d]... %s\n",i,optionNames[i]);
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

		//Inputtet var ikke "done", så converter s til et int
		optionSelect = strtol(s, &p, 10);


		//TODO: Uddyb hvad der sker i den første del a checket
		if (p == s || *p != '\n' || !(optionSelect >= 0 && optionSelect < dietPreferenceAmount)){
			printf("Ikke et valid input\n");
		} else break;
	}

	//Sæt indstillings værdi
	User_Diet_Preference = optionSelect;

	printf("\n");
}