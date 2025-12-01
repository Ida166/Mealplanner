#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"

void fill_schedule(int Arr[7]);

int main(){

    printf("\nVelkommen til meal plan programmet!\n\n");
    listOptions();

    //Instantiate the index variable for the result
    int BreakfastResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    //Create a new ingredient list
    Node *IngredientsBreakfast = NULL;
    //Run the ingredient input function to fill out the list
    IngredientsBreakfast = IngrediensIndtast_mainFunction("Morgenmad");
    //Print the recipes based on the ingredients
    //Also get the user input and set breakfast result to that
    print_recipes(recipes_breakfast,10,IngredientsBreakfast,BreakfastResultArray);

    printf("\n");
    //Now repeat for lunch and dinner (This could be a for loop frankly)

    int LunchResult = 0;
    int LunchResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    Node *IngredientsLunch = NULL;
    IngredientsLunch = IngrediensIndtast_mainFunction("Frokost");
    print_recipes(recipes_lunch,10,IngredientsLunch,LunchResultArray);

    printf("\n");

    int DinnerResult = 0;
    int DinnerResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    Node *IngredientsDinner = NULL;
    IngredientsDinner = IngrediensIndtast_mainFunction("Aftensmad");
    print_recipes(recipes_dinner,10,IngredientsDinner,DinnerResultArray);

    printf("\n");

    fill_schedule(BreakfastResultArray);
    fill_schedule(LunchResultArray);
    fill_schedule(DinnerResultArray);

    //Print the recipes

    for (int i = 0; i < 7; i++){
        printf("Dag: %d\n",i+1);
        printf("%s\n",recipes_breakfast[BreakfastResultArray[i]].name);
        printf("%s\n",recipes_lunch[LunchResultArray[i]].name);
        printf("%s\n",recipes_dinner[DinnerResultArray[i]].name);
        printf("\n");
    }
    free_list(IngredientsBreakfast);
    free_list(IngredientsLunch);
    free_list(IngredientsDinner);

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