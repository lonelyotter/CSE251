#include <stdio.h>
#include <math.h>
/*
 * Name : Song Haochen
 * 
 * This is my first CSE 251 C program!!!
 */
int main()
{
    // printf("The cylinder has a radius of %5.2f and a height of %8.1f\n", radius, height);
    // printf("My first C program\n");
    // printf("Aren't you impressed?\n");

    double radius = 7.88;
    double height = 12.231;
    // printf("The cylinder has a radius of %5.2f and a height of %8.1f\n", radius, height);

    int wins = 11;
    int losses = 2;
    // printf("MUS had an %d-%d season in 2010!\n", wins, losses);

    double volume, diameter, hypot;
    int games;
    volume = radius * radius * M_PI * height;
    games = wins + losses;
    // printf("volume: %f\n", volume);
    // printf("games: %d\n", games);

    double near = 10;
    double far = 22.5;
    hypot = sqrt(near * near + far + far);
    // printf("hypot: %f\n", hypot);

    double bottleVolume = 1700; /* Milliliters */
    double cupVolume = 350;     /* Milliliters */
    int numCups;

    numCups = (int)(bottleVolume / cupVolume);
    printf("Number of cups: %d\n", numCups);
}
