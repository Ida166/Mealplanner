#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();

    //Instantiate the index variable for the result
    int BreakfastResult = 0;
    int BreakfastResultarray[7];
    //Create a new ingredient list
    Node *IngredientsBreakfast = NULL;
    //Run the ingredient input function to fill out the list
    IngredientsBreakfast = IngrediensIndtast_mainFunction();
    //Print the recipes based on the ingredients
    //Also get the user input and set breakfast result to that
    print_recipes(recipes_breakfast,10,IngredientsBreakfast,&BreakfastResultarray);

    printf("\n");
    //Now repeat for lunch and dinner (This could be a for loop frankly)

    int LunchResult = 0;
    int Lunchresultarray[7];
    Node *IngredientsLunch = NULL;
    IngredientsLunch = IngrediensIndtast_mainFunction();
    print_recipes(recipes_lunch,10,IngredientsLunch,&Lunchresultarray);

    printf("\n");

    int DinnerResult = 0;
    int Dinnerresultarray[7];
    Node *IngredientsDinner = NULL;
    IngredientsDinner = IngrediensIndtast_mainFunction();
    print_recipes(recipes_dinner,10,IngredientsDinner,&Dinnerresultarray);

    printf("\n");


    //Skal laves om til et for loop så vi får alle 7 resultater ud
    //Print the selected recipes
    
    for (int i = 0; i < 7; i++){
    printf("Dag %d - Morgenmad:\n", i + 1);
    printf("%s\n",recipes_breakfast[BreakfastResultarray[i]].name);
    }
    for (int i = 0; i < 7; i++){
    printf("Dag %d - Frokost:\n", i + 1);
    printf("%s\n",recipes_lunch[Lunchresultarray[i]].name);
    printf("%s\n",recipes_dinner[Dinnerresultarray[i]].name);
    }
    return 0;
}