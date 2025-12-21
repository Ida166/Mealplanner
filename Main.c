#include <stdio.h>
#include <stdlib.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"
#include "printmealplanner.h"

//Fill schedule for any -1 indices
void fill_schedule(int Arr[7]);
//Handle meal input and selection
void handle_meal(const char *mealName, Recipe recipes[], int resultArray[7]);

int main(){

    printf("\nVelcome to the meal plan program!\n");
    printf("___________________________________\n\n");
    listOptions();

    //Define all available meals
    typedef struct {
        const char *name;
        Recipe *recipes;
    } MealType;

    MealType allMeals[] = {
        {"Breakfast", recipes_breakfast},
        {"Lunch",     recipes_lunch},
        {"Dinner",    recipes_dinner}
    };
    int totalMeals = sizeof(allMeals) / sizeof(MealType);

    //Dynamic arrays for user selections
    int *mealResults[totalMeals];
    for (int i = 0; i < totalMeals; i++) mealResults[i] = NULL;

    //Ask which meals the user wants
    for (int i = 0; i < totalMeals; i++) {
        int want = 0;
        printf("\n");
        printf("_________________________________________________\n\n");
        printf("Do you want to generate a mealplan for %s?\n", allMeals[i].name);
        printf("_________________________________________________\n\n");
        printf("Type 1 for yes or 0 for no: ");
        scanf("%d", &want);

        if (want) {
            mealResults[i] = malloc(7 * sizeof(int));
            for (int j = 0; j < 7; j++) mealResults[i][j] = -1;

            handle_meal(allMeals[i].name, allMeals[i].recipes, mealResults[i]);
            fill_schedule(mealResults[i]);
        }
    }

    // Prepare array of selected meals for printing
    Meal *mealsToPrint = malloc(totalMeals * sizeof(Meal));
    int selectedCount = 0;
    for (int i = 0; i < totalMeals; i++) {
        if (mealResults[i] != NULL) {
            mealsToPrint[selectedCount].name = allMeals[i].name;
            mealsToPrint[selectedCount].recipes = allMeals[i].recipes;
            mealsToPrint[selectedCount].resultArray = mealResults[i];
            selectedCount++;
        }
    }
    //Print the recipes
    printf("\n\n");
    printf("_____________\n\n");
    printf("Your mealplan\n");
    printf("_____________\n\n");
    const char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (int i = 0; i < 7; i++){
        printf("Dag: %d\n",i+1);
        for (int m = 0; m < selectedCount; m++) {
            printf("%s: %s\n", mealsToPrint[m].name,
                   mealsToPrint[m].recipes[mealsToPrint[m].resultArray[i]].name);
        }
        printf("______________________________\n\n");
    }

    // Print mealplan to CSV
    print_mealplan(mealsToPrint, selectedCount);

    // Free memory
    for (int i = 0; i < totalMeals; i++){
        free(mealResults[i]);
    }
    free(mealsToPrint);

    return 0;
}

void fill_schedule(int Arr[7]){
    int i = 0;
    int arrIndex = 0;
    while(i < 7){
        if (Arr[i] == -1){
            Arr[i] = Arr[arrIndex];
            arrIndex++;
        }
        i++;
    }
}

void handle_meal(const char *mealName, Recipe recipes[], int resultArray[7]) {
    Node *ingredients = NULL;

    while (1) {
        ingredients = IngrediensIndtast_mainFunction(mealName);
        print_recipes(recipes, 10, ingredients, resultArray);

        if (resultArray[0] != -1)
            break;

        free_list(ingredients);
        ingredients = NULL;
    }

    free_list(ingredients);
}