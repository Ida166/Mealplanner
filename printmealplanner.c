#include <stdio.h>
#include "printmealplanner.h"  //Defines Meal struct
#include "Recipes.h"

int print_mealplan(Meal meals[], int mealCount){
    //åbner filen
    FILE *f = fopen("printmealplanner.csv", "w");
    if (!f){
        printf("Could not open file for writing.\n");
        return 1;
    }

    //Generate a headline
    fprintf(f, "Meal Plan Template\n");

    //Generate columns headlines
    fprintf(f, "Day;");
    //Dynamic headers only prints columns for selected meals
    for (int m = 0; m < mealCount; m++) {
        if (meals[m].resultArray) {
            fprintf(f, "%s;", meals[m].name);
        }
    }
    fprintf(f, "\n");

    //Days
    const char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                           "Friday", "Saturday", "Sunday"};
    
    //Fill the csv file with the recipes 
    for (int i = 0; i < 7; i++) {
        
         //Day column
        fprintf(f, "%s;", days[i]);

        for (int m = 0; m < mealCount; m++) {
            if (!meals[m].resultArray) continue;  //Skip unselected meals

            Recipe r = meals[m].recipes[meals[m].resultArray[i]];

            fprintf(f, "\"%s, Time: %d, Portions: %d, Calories: %d, Ingredients: ",
                    r.name, r.time, r.portion, r.calories);

            for (int j = 0; j < r.ingredient_count; j++)
                fprintf(f, "%s, ", r.ingredient[j]);

            fprintf(f, "Procedure: %s\"", r.procedure);

            fprintf(f, ";");  //column separator
        }
    fprintf(f, "\n"); //end of row
    }
    fclose(f);
    return 0;
}
