#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void PrintResult(int, int, int, int);
void PrintCard(int, int);

int main()
{
    int card1, card2, suit1, suit2;
    srand(time(NULL));

    do
    {
        suit1 = rand() % 4;
        card1 = rand() % 13 + 2;
        suit2 = rand() % 4;
        card2 = rand() % 13 + 2;

    } while (card1 == card2 && suit1 == suit2);

    printf("Player 1: ");
    PrintCard(card1, suit1);
    printf("\nPlayer 2: ");
    PrintCard(card2, suit2);
    printf("\n");

    PrintResult(card1, suit1, card2, suit2);
    printf("\n");
}

void PrintResult(int card1, int suit1, int card2, int suit2)
{
    if (card1 > card2)
    {
        printf("Player 1 wins");
    }
    else if (card1 < card2)
    {
        printf("Player 2 wins");
    }
    else if (suit1 > suit2)
    {
        printf("Player 1 wins");
    }
    else if (suit1 < suit2)
    {
        printf("Player 2 wins");
    }
    else
    {
        printf("There is a tie");
    }
}

void PrintCard(int card, int suit)
{
    switch (card)
    {
    case 14:
        printf("Ace");
        break;

    case 11:
        printf("Jack");
        break;

    case 12:
        printf("Queen");
        break;

    case 13:
        printf("King");
        break;

    default:
        printf("%d", card);
        break;
    }

    printf(" of ");

    switch (suit)
    {
    case 3:
        printf("Hearts");
        break;

    case 2:
        printf("Diamonds");
        break;

    case 1:
        printf("Spades");
        break;

    case 0:
        printf("Clubs");
        break;
    }
}
