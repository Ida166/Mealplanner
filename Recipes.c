#include "Recipes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IngrediensIndtast.h"
#include "KostPreference.h"

Recipe recipes_breakfast[] = {
{"Pancakes", 30, 2, 300,
 {"flour: 200g", "eggs: 1", "milk: 100ml", "sugar"},
 "Mix dry ingredients, add wet ingredients, then cook on a hot pan.", 4, {VEGETARIAN}},
{"Omelette", 30, 1, 350,
 {"eggs: 2", "milk: 100ml", "salt", "pepper"},
 "Whisk ingredients together and cook on a pan until firm.", 4, {VEGETARIAN}},
{"Skyr", 5, 1, 350,
 {"Skyr: 200g", "Fruit", "Oats"},
 "Place skyr in a bowl and add fruit and oats.", 3, {VEGETARIAN}},
{"Oats", 3, 1, 400,
 {"Oats: 70g", "Cinnamon", "Apple", "Milk: 200ml"},
 "Add oats and milk to a bowl, mix, and top with apple and cinnamon.", 4, {VEGETARIAN,VEGAN}},
{"Toast", 5, 1, 400,
 {"Toast", "Cheese", "Ham"},
 "Assemble the toast and grill if desired.", 3, {}},
{"Yoghurt", 5, 1, 400,
 {"Yoghurt: 200g", "Fruit", "Oats"},
 "Add yoghurt to a bowl and top with fruit and oats.", 3, {VEGETARIAN}},
{"Scrambled Eggs", 10, 1, 250,
 {"Eggs: 2", "Butter: 10g", "Salt", "Pepper"},
 "Whisk eggs, melt butter in pan, and cook while stirring gently.", 4, {VEGETARIAN}},
{"Banana Smoothie", 5, 1, 280,
 {"Banana: 1", "Milk: 200ml", "Oats: 30g"},
 "Blend banana, milk, and oats until smooth.", 3, {VEGETARIAN}},
{"Avocado Toast", 7, 1, 320,
 {"Toast", "Avocado: 1", "Salt", "Lemon juice"},
 "Mash avocado, spread on toast, and season with salt and lemon.", 4, {VEGETARIAN,VEGAN}},
{"Fruit Bowl", 5, 1, 220,
 {"Apple", "Banana", "Grapes", "Strawberries"},
 "Chop fruit and mix in a bowl.", 4, {VEGETARIAN,VEGAN}}
};
int breakfastcount = 10;

Recipe recipes_lunch[] = {
{"Chicken Stir Fry", 20, 1, 450,
    {"Chicken breast: 150g", "Mixed veggies: 200g", "Soy sauce: 1 tbsp", "Rice: 100g"},
    "Cook the chicken, add vegetables, pour soy sauce and serve with rice.",
    4, {}
},
{"Tuna Pasta", 15, 1, 500,
    {"Pasta: 100g", "Canned tuna: 1 can", "Corn: 50g", "Cream cheese: 1 tbsp"},
    "Boil pasta, mix with tuna, corn, and cream cheese.",
    4, {}
},
{"Veggie Wrap", 10, 1, 350,
    {"Tortilla", "Lettuce", "Tomato", "Chicken: 100g"},
    "Fill tortilla with vegetables and cooked chicken, then roll tightly.",
    4, {VEGETARIAN,VEGAN}
},
{"Chili Beans", 15, 1, 400,
    {"Kidney beans: 1 can", "Tomato sauce: 200ml", "Onion", "Spices"},
    "Heat onion, add beans and tomato sauce, season and simmer.",
    4, {}
},
{"Salmon Bowl", 20, 1, 500,
    {"Salmon: 150g", "Rice: 100g", "Spinach: 50g", "Lemon"},
    "Bake salmon, cook rice, add spinach and lemon juice on top.",
    4, {}
},
{"Chicken Caesar Salad", 12, 1, 350,
    {"Chicken: 120g", "Lettuce", "Croutons", "Caesar dressing: 1 tbsp"},
    "Cook chicken, add lettuce, croutons and dressing, then toss.",
    4, {}
},
{"Easy Veggie Pasta", 15, 1, 420,
    {"Pasta: 100g", "Zucchini", "Tomatoes", "Olive oil: 1 tbsp"},
    "Boil pasta, sauté veggies, mix together with olive oil.",
    4, {VEGETARIAN,VEGAN}
},
{"Egg Fried Rice", 10, 1, 450,
    {"Rice: 150g", "Eggs: 2", "Peas: 50g", "Soy sauce: 1 tbsp"},
    "Scramble eggs, add rice and peas, stir soy sauce through.",
    4, {}
},
{"Chicken Pita", 8, 1, 380,
    {"Pita bread", "Chicken: 100g", "Lettuce", "Yoghurt dressing"},
    "Fill pita with chicken, lettuce, and a spoon of yoghurt dressing.",
    4, {}
},
{"Tomato Soup & Toast", 12, 1, 300,
    {"Tomato soup: 1 can", "Toast", "Cheese"},
    "Heat soup, toast bread with cheese, serve together.",
    3, {VEGETARIAN}
},    
};
int lunchcount = 10;

Recipe recipes_dinner[] = {
{"One-Pot Chicken Pasta", 20, 1, 480,
    {"Pasta: 100g", "Chicken: 120g", "Cherry tomatoes: 100g", "Spinach: 50g", "Cream cheese: 1 tbsp"},
    "Cook chicken, add pasta, tomatoes and water. Simmer until pasta is done, stir in cream cheese and spinach.",
    4, {}
},
{"Bean & Veggie Burrito", 12, 1, 420,
    {"Tortilla", "Black beans: 1 can", "Corn: 50g", "Rice: 80g", "Salsa"},
    "Heat beans with corn, add cooked rice, wrap in tortilla with salsa.",
    4,{VEGETARIAN,VEGAN}
},
{"Quick Chicken Curry", 18, 1, 450,
    {"Chicken: 150g", "Curry paste: 1 tbsp", "Coconut milk: 150ml", "Frozen veggies: 150g"},
    "Cook chicken, add curry paste, pour coconut milk, add veggies and simmer.",
    4,{}
},
{"Omelette Bowl", 10, 1, 350,
    {"Eggs: 3", "Spinach: 50g", "Tomatoes", "Cheese: 20g"},
    "Whisk eggs, cook with spinach and tomatoes, add cheese before folding.",
    3,{VEGETARIAN}
},
{"Fast Salmon Pasta", 15, 1, 500,
    {"Pasta: 100g", "Smoked salmon: 80g", "Cream cheese: 1 tbsp", "Lemon", "Peas: 50g"},
    "Boil pasta, mix with peas, cream cheese and salmon. Add lemon.",
    4,{}
},
{"Turkey Chili", 20, 1, 470,
    {"Ground turkey: 150g", "Kidney beans: 1 can", "Tomato sauce: 200ml", "Chili spices"},
    "Cook turkey, add beans, tomato sauce and spices, simmer.",
    4,{}
},
{"Veggie Stir Fry Noodles", 12, 1, 420,
    {"Noodles: 100g", "Frozen stir-fry veggies: 200g", "Soy sauce: 1 tbsp", "Egg: 1"},
    "Cook noodles, fry veggies, add egg, mix everything with soy sauce.",
    4,{VEGETARIAN}
},
{"Baked Potato Bowl", 15, 1, 390,
    {"Potato: 1 large", "Cottage cheese: 100g", "Corn: 50g", "Spring onion"},
    "Microwave potato, top with cottage cheese, corn and chopped spring onion.",
    3,{VEGETARIAN}
},
{"Tuna Rice Bowl", 10, 1, 430,
    {"Rice: 150g", "Canned tuna: 1 can", "Soy sauce: 1 tsp", "Cucumber", "Mayo: 1 tsp"},
    "Mix rice with tuna, soy sauce, mayo and diced cucumber.",
    4,{}
},
{"Vegetarian Lentil Stew", 18, 1, 400,
    {"Red lentils: 100g", "Carrots", "Onion", "Vegetable broth: 300ml"},
    "Cook onion and carrot, add lentils and broth, simmer until thick.",
    4,{VEGETARIAN,VEGAN}
}
};
int dinnercount = 10;

//function to print [] recepies

void print_recipes(Recipe arr[],int size,Node *IngredienList, int result[7]){

    //Start new line
    printf("\n");
    int index = 0;
    Node* IngredienListStartPoint = IngredienList;

    int results[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    for(int i = 0; i < size; i++){
        Recipe current = arr[i]; //variable of type Recipe named current storing the current breakfast recipe

        int shouldAddToList = 0;

        //Check Diet Preference
        if (userDietCount > 0){

            int match = 0;

            for(int d = 0; d < userDietCount; d++){
                int pref = userDietChoices[d];

                if (hasPreference(current, pref)){
                    match = 1;
                    break;
                }
            }
            if (!match) {
                shouldAddToList = -1;
            }
        }

        //Check each ingredient
        if (shouldAddToList >= 0){
                IngredienList = IngredienListStartPoint;
                while(IngredienList != NULL){
                    //If recipes has ingredient then add it to the list
                    if (hasIngredient(current,IngredienList->ingredient)){
                        shouldAddToList = 1;
                        break;
                    }
                    //Go to the next ingredient if the check failed
                    IngredienList = IngredienList->next;
                }
            }

        //Print the recipe if the ingredients matched
        if (shouldAddToList > 0){
            printf("%d\n",i);
            results[index] = i;
            index++;
        }
    }

    if (results[0] == -1){
        printf("Ingen retter kunne genereres... Vil du generere nogle tilfaeldige retter? Y/N\n");
        
        while(1){
            char answear;
            scanf(" %c",&answear);
            if (answear == 'Y'){

                int maxSuggestions = 0;

                //Get max avilable options
                for(int i = 0; i < size; i++){
                    for (int j=0;j < userDietCount;j++)
                        if (hasPreference(arr[i], userDietChoices[j])){
                            maxSuggestions++;
                            break;
                    }
                    if (maxSuggestions >= 7){
                        break;
                    }
                }

                //If not, then default it to 7
                if (maxSuggestions == 0){
                    maxSuggestions = 7;
                }

                for (int i = 0; i < maxSuggestions;i++){

                    int preferenceValid = 0;
                    int ranIndex;
                    while (!preferenceValid){
                        ranIndex = rand()%size;
                        if (userDietCount > 0){

                            for(int j = 0; j < userDietCount; j++){
                                if (hasPreference(arr[ranIndex], userDietChoices[j])){
                                    if (!arrayHasValue(ranIndex,results,10))
                                    {
                                        preferenceValid = 1;
                                        break;
                                    }
                                }
                            }

                        } else {
                            if (!arrayHasValue(ranIndex,results,10)){
                               preferenceValid = 1;
                            }
                        }

                    }
                    results[i] = ranIndex;
                }
                break;
            }
            if (answear == 'N'){
                return;
            }
            else{
                printf("Invalid");
            }
        }
    }

    int recipesIndex = 0;
    for (int i = 0;i<10;i++){
        if (results[i] != -1){
            Recipe current = arr[results[i]];
            printf("[%d]... Recipe: %s\n",recipesIndex, current.name);
            printf("       Time: %d\n", current.time);
            printf("       Portions: %d\n", current.portion);
            printf("       Calories: %d\n", current.calories);
            printf("       Ingredients:\n");
            for(int j = 0; j < current.ingredient_count; j++){
                printf("       - %s\n", current.ingredient[j]);
            }
            printf("       Procedure: %s\n", current.procedure);
            printf("\n");
            recipesIndex++;
        }
    }

    printf("\nVaelg retter...(Indtast 'exit' for at afslutte)\n");
    int option;
    int arrayIndex = 0;
    
    char *p, s[100];
    //Få fat på brugerens input via fgets
    while(fgets(s,sizeof(s),stdin) && arrayIndex < 7){

        //Check om brugerens er "done"
        char inputText[100];
        strcpy(inputText,s);

        inputText[strlen(inputText)-1] = '\0';

        char compareText[] = "exit";
        int compResult = strcmp(inputText,compareText);

        if (compResult == 0){
            break;
        }


        //Inputtet var ikke "done", så converter s til et int
        option = strtol(s, &p, 10);


        //TODO: Uddyb hvad der sker i den første del a checket
        if (p == s || *p != '\n'){
            printf("Ikke et valid input\n");
        } else {
            result[arrayIndex] = results[option];
            arrayIndex++;
        }
    }





}

int hasPreference(Recipe targetRecipe, int pref){

    //Udregner størrelsen af dietPreference arrayet
    int arrSize = sizeof(targetRecipe.dietPreference)/sizeof(targetRecipe.dietPreference[0]);
    for (int i = 0; i < arrSize;i++){
        if (targetRecipe.dietPreference[i] == pref){
            return 1;
        }
    }

    return 0;
}

int hasIngredient(Recipe targetRecipe,char target[]){

    int i = 0;

    //Check through every ingredient
    while (i < targetRecipe.ingredient_count){

        //Get the string up until ':' and compare that to the search result

        char searchString[Max_Ingredient_name];

        int index = 0;
        //Check how many characters are in the original ingredient string
        int charsToCopy = sizeof(targetRecipe.ingredient[i])/sizeof(targetRecipe.ingredient[i][0]);
        //Iterate through the string until it either finds '\0' or ':'
        while (targetRecipe.ingredient[i][index] != '\0'){
            if (targetRecipe.ingredient[i][index] == ':'){
                charsToCopy = index;
                break;
            }
            index++;
        }

        //Copy the ingredient string onto searchString but only up to ':' if there was any

        strncpy(searchString,targetRecipe.ingredient[i],charsToCopy);
        searchString[charsToCopy] = '\0';
        capitalize(searchString);

        //Now compare that string with the original one
        if (strcmp(target,searchString) == 0){
            return 1;
        }
        i++;
    }

    return 0;
}

int arrayHasValue(int value,int arr[],int size){
    int i;
    for(i = 0; i < size; i++){
        if(arr[i] == value){
            return 1;
        }
    }
    return 0;
}