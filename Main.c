#include <stdio.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"
#include "Recipes.h"
#include "printmealplanner.h"

void fill_schedule(int Arr[7]);

int main(){

    printf("\nVelcome to the meal plan program!\n");
    printf("___________________________________\n\n");
    listOptions();

    //Instantiate the index variable for the result
    int BreakfastResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    //Create a new ingredient list
    Node *IngredientsBreakfast = NULL;
    //Run the ingredient input function to fill out the list
    while(1){
        IngredientsBreakfast = IngrediensIndtast_mainFunction("breakfast");
        //Print the recipes based on the ingredients
        //Also get the user input and set breakfast result to that
        print_recipes(recipes_breakfast,10,IngredientsBreakfast,BreakfastResultArray);
        if (BreakfastResultArray[0] != -1){
            break;
        }
    }

    printf("\n");
    //Now repeat for lunch and dinner (This could be a for loop frankly)

    int LunchResult = 0;
    int LunchResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    Node *IngredientsLunch = NULL;
    while(1){
        IngredientsLunch = IngrediensIndtast_mainFunction("lunch");
        print_recipes(recipes_lunch,10,IngredientsLunch,LunchResultArray);
        if (LunchResultArray[0] != -1){
            break;
        }
    }

    printf("\n");

    int DinnerResult = 0;
    int DinnerResultArray[7] = {-1,-1,-1,-1,-1,-1,-1};
    Node *IngredientsDinner = NULL;
    while(1){    
        IngredientsDinner = IngrediensIndtast_mainFunction("dinner");
        print_recipes(recipes_dinner,10,IngredientsDinner,DinnerResultArray);
        if (DinnerResultArray[0] != -1){
            break;
        }
    }
    printf("\n");

    fill_schedule(BreakfastResultArray);
    fill_schedule(LunchResultArray);
    fill_schedule(DinnerResultArray);

    //Print the recipes
    printf("_____________\n\n");
    printf("Your mealplan\n");
    printf("_____________\n\n");
    for (int i = 0; i < 7; i++){
        printf("Dag: %d\n",i+1);
        printf("%s\n",recipes_breakfast[BreakfastResultArray[i]].name);
        printf("%s\n",recipes_lunch[LunchResultArray[i]].name);
        printf("%s\n",recipes_dinner[DinnerResultArray[i]].name);
        printf("______________________________\n\n");
    }

    print_mealplan(BreakfastResultArray, LunchResultArray, DinnerResultArray);

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