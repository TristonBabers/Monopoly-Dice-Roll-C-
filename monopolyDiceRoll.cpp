/**
    File Name: monopolyDiceRoll.cpp

    Author: Triston Babers
    Email: triston.babers.official@gmail.com
*/

// Imports:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>


// Constants:
#define NUM_DICE 2
#define DIE_SIDES 6
#define DOUBLE_LIMIT 2

// Functions:
void displayJail();
void displayDice(short D1, short D2);
short rollDice(void);

/*o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o[Main]0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o*/
int main()
{
    // Variables:
    short dice1;
    short dice2;
    short total = 0;
    short doubleCounter = 0;
    char rollAgain;

    // Initialize Random Seed:
    srand(time(0));

    // Game Start:
    printf(" Welcome to Monopoly Dice Roll! \n\n");
    printf(" Press ANY KEY To Roll %d Dice!\n", NUM_DICE);
    getch();
    fflush(stdin);

    // Dice Loop:
    do {
        // Roll Dice:
        dice1 = rollDice();
        dice2 = rollDice();

        // Display Dice:
        total += (dice1 + dice2);
        displayDice(dice1, dice2);
        printf("\n     [Total]: %d\n", total);

        // Doubles:
        if (dice1 == dice2) {
            if (doubleCounter < DOUBLE_LIMIT) {
                printf(" Doubles! Lucky!!! Press ANY KEY for your free roll!\n",
                   NUM_DICE);
                doubleCounter += 1;
                getch();
                fflush(stdin);
                rollAgain = 'Y';
            } else {
                printf(" Oh No! You rolled too many doubles! Go to Jail!\n\n");
                displayJail();
                doubleCounter = 0;
                total = 0;
                printf("\n Roll Again? (Y/N)\n");
                scanf("%c", &rollAgain);
                fflush(stdin);
            }
        } else {
            // Re-Prompt:
            doubleCounter = 0;
            total = 0;
            printf("\n Roll Again? (Y/N)\n");
            scanf("%c", &rollAgain);
            fflush(stdin);
        }
    } while(rollAgain == 'Y' || rollAgain == 'y');
    return 0;
}

/*o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o[Functions]o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o0o*/

void displayJail() {
    printf("        +=============+ \n");
    printf("        | | | | | | | | \n");
    printf("        |=|=|=|=|=|=|=| \n");
    printf("        | | | | | | | | \n");
    printf("        |=|=|=|=|=|=|=| \n");
    printf("        | | | | | | | | \n");
    printf("        +=============+ \n");
}

void displayDice(short D1, short D2) {
    // Variables:
    char diePointer[6][3][14] = {{
        "|           |",
        "|     *     |",
        "|           |",
    },
    {
        "|  *        |",
        "|           |",
        "|        *  |",
    },
    {
        "|  *        |",
        "|     *     |",
        "|        *  |",
    },
    {
        "|  *     *  |",
        "|           |",
        "|  *     *  |",
    },
    {
        "|  *     *  |",
        "|     *     |",
        "|  *     *  |",
    },
    {
        "|  *  *  *  |",
        "|           |",
        "|  *  *  *  |",
    }};

    // Start:
    printf("            +-----------+        +-----------+\n");

    // Print Die Faces:
    /* One is subtracted from both D1 and D2 so they fit within the array
     * bounds of 0-5 */
    for (int i = 0; i < 3; ++i) {
        printf("            ");
        printf("%s", diePointer[(int)D1-1][i]);
        printf("        ");
        printf("%s\n", diePointer[(int)D2-1][i]);
    }

    // End:
    printf("            +-----------+        +-----------+\n");
}

short rollDice(void) {
    // Variables:
    short randomNum;

    // Return Random Number Between 1-6:
    randomNum = (rand() % DIE_SIDES) + 1;
    return (short)randomNum;
}
