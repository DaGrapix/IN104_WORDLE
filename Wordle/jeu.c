#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "word_compare.h"
#include "load_dic.h"
#include "random_word.h"


int main(){
    printf("                                       ##############################\n");
    printf("                                       #####       WORDLE       #####\n");
    printf("                                       ##############################\n\n");

    printf("#############################################  REGLES DU JEU  #############################################\n");
    printf("___________________________________________________________________________________________________________\n");
    printf("Un mot a ete choisi au hasard. Ton role est de retrouver ce mot en un certain nombre de tours.\n");
    printf("Tu devras donner un mot a chaque tour.\nPour chacune des lettres de ce mot,\n"
            "si cette lettre est presente dans le mot choisi et est a la bonne place, un O s'affichera à cette place;\n"
            "Si c'est une lettre qui est dans le mot mais à la mauvaise place, un Z s'affichera;\n"
            "si la lettre n'est pas dans le mot, un X s'affichera.\n");
    printf("___________________________________________________________________________________________________________\n\n\n");

    int nb_tour;
    int word_length;
    char language[16];
    char dico_name[16];

    printf("Veux-tu jouer en FRANCAIS ou en ANGLAIS?\n");
    scanf("%s", language);
    while((strcmp(language, "FRANCAIS")!=0) && (strcmp(language, "ANGLAIS")!=0)){
        printf("Tu dois répondre FRANCAIS ou ANGLAIS! Réeessaie!\n");
        scanf("%s", language);
    }

    if (strcmp(language, "FRANCAIS")==0){
        strcpy(dico_name,"french.txt");
    }
    else{
        strcpy(dico_name,"english.txt");
    }

    printf("\n\n");

    printf("En combien de tours veux tu jouer?\n");
    scanf("%d", &nb_tour);
    while((nb_tour>50) || (nb_tour<=0)){
        printf("Il faut un nombre entre 1 et 50! Réeessaie!\n");
        scanf("%d", &nb_tour);
    }

    printf("\n\n");

    printf("Avec combien de lettres veux tu jouer?\n");
    scanf("%d", &word_length);
    while((word_length>10) || (word_length<=2)){
        printf("Il faut un nombre entre 3 et 10! Réeessaie!\n");
        scanf("%d", &word_length);
    }

    printf("\n\n");

    printf("Jeu en %d tours, pour des mots de %d lettres en %s\n\n", nb_tour, word_length, language);


    srand(time(NULL));


    int size;
    char** list = read_dico(dico_name, &size, word_length);

    char* game_word = random_word(list, size);

    int tour_counter = 1;
    bool gagne = false;
    char user_word[2*size+1];

    while ((tour_counter<=nb_tour) && !gagne){
        printf("#####  TOUR %d  #####\n", tour_counter);
        scanf("%s", user_word);
        if (strcmp(user_word, game_word)==0){
            printf("C'est gagné!\n");
            printf("\\(ᵔᵕᵔ)/\n\n");
            return(0);
        }
        else if (strlen(user_word)!=word_length){
            printf("Pas le bon nombre de lettres, Reessaie!\n\n");
        }
        else if (find_word_dicho(list, user_word, 0, size-1)==false){
            printf("Ce n'est pas un mot du dico, Reessaie!\n\n");
        }
        else{
            letter_check(game_word, user_word);
            tour_counter++;
            printf("\n\n");
        }
    }

    printf("C'est perdu!, le mot etait\n%s\n", game_word);
    printf("¯\\_(⊙︿⊙)_/¯\n\n");
    return(0);
}