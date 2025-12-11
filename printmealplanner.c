#include <stdio.h>
#include "Recipes.h" 


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
    fprintf(f, "Day;Breakfast;Lunch;Dinner\n");

    // Dage i ugen
    const char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", 
                           "Friday", "Saturday", "Sunday"};

    //Fyld csv filen med opskrifterne
    for (int i = 0; i < 7; i++) {
        Recipe breakfast = recipes_breakfast[breakfastResultArray[i]];
        Recipe lunch = recipes_lunch[lunchResultArray[i]];
        Recipe dinner = recipes_dinner[dinnerResultArray[i]];
        
         // Day column
        fprintf(f, "%s;", days[i]);

        // Breakfast column
        fprintf(f, "\"%s, Time: %d, Portions: %d, Calories: %d, ", breakfast.name, breakfast.time, breakfast.portion, breakfast.calories);
        fprintf(f, "Ingredients: ");
        for(int j = 0; j < breakfast.ingredient_count; j++) {
            fprintf(f, "%s, ", breakfast.ingredient[j]);
        }
        fprintf(f, "Procedure: %s\"", breakfast.procedure);
        
            
        // Add semicolon before moving to lunch
        fprintf(f, ";");    

        // Lunch column
        fprintf(f, "\"%s, Time: %d, Portions: %d, Calories: %d, ", lunch.name, lunch.time, lunch.portion, lunch.calories);
        fprintf(f, "Ingredients: ");
        for (int j = 0; j < lunch.ingredient_count; j++) {
            fprintf(f, "%s, ", lunch.ingredient[j]);
        }
        fprintf(f, "Procedure: %s\"", lunch.procedure);

        // Add semicolon before moving to dinner
        fprintf(f, ";"); 

        // Dinner column
        fprintf(f, "\"%s, Time: %d, Portions: %d, Calories: %d, ", dinner.name, dinner.time, dinner.portion, dinner.calories);
        fprintf(f, "Ingredients: ");
        for (int j = 0; j < dinner.ingredient_count; j++) {
            fprintf(f, "%s, ", dinner.ingredient[j]);
        }
        fprintf(f, "Procedure: %s\"\n", dinner.procedure);  // newline at end of row
    }
    
    fclose(f);
    return 0;
}

