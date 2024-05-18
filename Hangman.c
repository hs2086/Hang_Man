#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

void DRAW(s32 num);

s32 main(void){
    s32 mistakes = 6, nonmistakes = 0, count = 0, i, flag;
    char word[10], ch;
    system("cls");
    printf("\n\n\t\t\t\tHANGMAN\n");
    printf("Rule: \nYou Have A Maximum Of Mistakes Is 6\nAll Alphabet Is Lower Case\n");
    printf("\n\nPlease Enter Your Word(5 - 10)ALPHABET: ");
    scanf("%s", word);
    system("cls");


    char *ptr = word;
    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }


    s32 *arr = (s32 *)calloc(count, sizeof(s32));
    printf("\n\n\t\t\t\tHANGMAN\n\n");
    printf("\t\t\t\t");


    for (i = 0; i < count; i++)
    {
        printf("_ ");
    }


    printf("\n\n");
    s32 num = 6 - mistakes;
    while (mistakes)
    {
        flag = 1; 
        printf("\t\tEnter The Alphabet In Lower Case: ");
        scanf(" %c", &ch);
        printf("\t\t\t\t");
        for (i = 0; i < count; i++)
        {
            if(ch == word[i])
            {
                printf("%c ", word[i]);
                flag = 0;
                arr[i] = 1;
                nonmistakes++;
            }else if(arr[i] == 1){
                printf("%c ", word[i]);
            }else{
                printf("_ ");
            }
        }
        if(flag == 1)
            mistakes--;
        num = 6 - mistakes;
        DRAW(num);
        if (nonmistakes == count)
        {
            break;
        }
        printf("\n\n\t\tYou Have %d Mistakes And You Remaining %d Lives", num, mistakes);
        printf("\n\n");
    }
    if(mistakes){
        system("cls");
        printf("\n\n\t\t\t\tHANGMAN\n\n");
        printf("\t\t\t\t( )\n\t\t\t\t\\|/\n\t\t\t\t/ \\");
        printf("\n\n\t\t\t\tYOU ARE WIN\n\n\n");
    }else{
        printf("\n\t\t\t\t\tGAME OVER\n\n\n");
    }
    return 0;
}

void DRAW(s32 num){
    u8 *draw[] = {"|   ( )", "|    |", "|   /|", "|   /|\\", "|   /", "|   / \\"};

    printf("\n\t\t\t ____\n");
    printf("\t\t\t|    |\n");
    s32 ff = 0;
    if (num >= 1)
    {
        printf("\t\t\t%s\n", draw[0]);
        ff = 1;
    }
    if (!ff)
    {
        printf("\t\t\t|\n");
    }
    ff = 0;
    if (num == 2)
    {
        printf("\t\t\t%s\n", draw[1]);
        ff = 1;
    }
    if (num == 3)
    {
        printf("\t\t\t%s\n", draw[2]);
        ff = 1;
    }
    if (num >= 4)
    {
        printf("\t\t\t%s\n", draw[3]);
        ff = 1;
    }
    if (!ff)
    {
        printf("\t\t\t|\n");
    }
    ff = 0;
    if (num == 5)
    {
        printf("\t\t\t%s\n", draw[4]);
        ff = 1;
    }
    if (num == 6)
    {
        printf("\t\t\t%s\n", draw[5]);
        ff = 1;
    }
    if (!ff)
    {
        printf("\t\t\t|\n");
    }
    ff = 0;
    printf("\t\t\t|\n");
    printf("\t\t----------------------------\n\n\n");
}
