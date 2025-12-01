#include <stdio.h>

int print_mealplan(int breakfastResultArray[7], int lunchResultArray[7], int dinnerResultArray[7]){
    //åbner filen
    FILE *f = fopen("printmealplanner.csv", "w");
    if (!f){
        printf("Could not open file for writing.\n");
        return 1;
    }

    // Generer en overskrift
    fprintf(f, "Meal Plan Template\n");

    // Generer Kolonneoverskrifter
    fprintf(f, "Day,Breakfast,Lunch,Dinner\n");

    // Dage i ugen
    const char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                           "Friday", "Saturday", "Sunday"};

    //Fyld csv filen med opskrifterne
    for (int i = 0; i < 7; i++) {
        
        fprintf(f, "%s,"%s","%s","%s"\n",
        days[i],
        recipes_breakfast[breakfastResultArray[i]].name,
        recipes_lunch[lunchResultArray[i]].name,
        recipes_dinner[dinnerResultArray[i]].name);
    }

    fclose(f);
    return 0;
}
