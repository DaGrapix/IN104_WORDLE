#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Wordle_solver.h"

int main(){
    char list_word[6]="ALLER";
    char word[6]="ALLER";
    char arrangement[6]="OOOOO";
    bool OK = is_similar(word,arrangement,list_word,5);
    printf("%d\n", OK);
}
