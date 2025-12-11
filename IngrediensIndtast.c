#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "IngrediensIndtast.h"

//En struct der gør at vi kan gemme ingredienser og pointe videre til den næste. (linked lists) 
//En struct er en datatype man selv kan definere


Node* IngrediensIndtast_mainFunction(char hint[])
{
    Node *head = NULL; //Declares a pointer head der peger på en node struct. NULL initilieres den til så den ikke peger et sted hen endnu.
    char ingrediens_input[50];

    //promt brugeren for ingredienser og gem dem i en liste.

    printf("Write the ingrediens you like for %s (Type'exit' when you are finiched).\n",hint);
    while(1)
    {
        get_ingredient(ingrediens_input);
        if(strcmp(ingrediens_input, "exit") == 0){
            if (head == NULL){
                printf("[ERROR] - No ingredients were typed.\n\n");
            } else{
            break;
            }
        } else{
        capitalize(ingrediens_input);
        head = tilfoj_ingrediens_til_liste(ingrediens_input, head);
    }
    }

    return head;
    //Frigørelse a hukommelse
    //free_list(head);

    //return 0;
}

//char *ingrediens_input gives som en pointer da man ikke kan passere en hel array ind så dergor giver vi adressen til starten af arrayen
Node* tilfoj_ingrediens_til_liste(char *ingrediens_input, Node *head){
    

    //allokerer plads i hukommelsen på størrelse med Node og sat lig pointer n
    Node *n = malloc(sizeof(Node)); 
    //Hvis systemet ikke kan allokere nok plads til noden vil den retunere Null og her vil vi så stoppe programmet.
    //strcmp sammenligner to strings og retunerer 0 hvis stringsne er ens
    if(n == NULL)
    {
        printf("ERROR: memmory could not be allocated.\n");
        return head;
    }

    strcpy(n->ingredient, ingrediens_input);
    //put noden i listen
    n->next = head; //n's næste felt er sat lig listen og indsættes derfor forrest i listen
    head = n; //listen bliver sat lig n som er adressen til noden og ingrediensen der er blevet givet af brugeren.
    return head;
}

void get_ingredient(char *ingrediens_input){

    //begrænser mængden af char's som kan blive sannet ind til at passe med størrelsen på vores array
    scanf("%49s", ingrediens_input);
}

void print_list(Node *head){
    printf("Ingrediens typed in:\n");
    //Looper igennem listen og printer ingredienserne
    while(head != NULL){
        printf("%s\n",head->ingredient);
        //sætter pointeren head til at pege på den næste i listen
        head = head->next;
    }
}

// Funktion der firgører den hukkomelse listen har brugt 
void free_list(Node *head){
    while(head != NULL){
        Node *tmp = head;
        head = head ->next;
        free(tmp);
    }
}

void capitalize(char *ingrediens_input){
    //Konverterer det første bukstav til stort
    ingrediens_input[0] = toupper(ingrediens_input[0]);
 
    int i = 1;
    while(ingrediens_input[i] != '\0'){
        //Tjekker om det resten af bukstaverne er med stort 
        if(isupper(ingrediens_input[i])){
            //Konverterer hvis bukstavet er stort
            ingrediens_input[i] = tolower(ingrediens_input[i]);
        }
        i++;
    }
}