#include <stdio.h>


int options[2] = {1,0};

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

	printf("Vaelg kost praeference. Tast -1 naar du er faerdig\n");

vaelg_mulighed:
	printf("\n");
	for (int i = 0; i < 2;i++){
		printf("[%d]... %s...%s\n",i,optionNames[i],getToggleString(options[i]));
	}

	int optionSelect;
	scanf("%d",&optionSelect);

	if (optionSelect >= 0 && optionSelect < 2){

		//printf("%s",options[optionSelect]);

		if (options[optionSelect] == 0){
			options[optionSelect] = 1;
		} else {
			options[optionSelect] = 0;
		}
	}

	if (optionSelect!=-1){
		goto vaelg_mulighed;
	}

}