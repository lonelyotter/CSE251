#include <stdio.h>
#include <string.h>

/* 
 * Name : <Insert name>
 * Program to experiment with character arrays
 */

#define MaxWord 20

int main()
{
    char c;
    char str[MaxWord + 1];
    int len = 0;
    int wordCount = 0;
    int totalLength = 0;
    int maxLength = 0;
    char longestWord[MaxWord + 1];

    puts("Enter text. Include a dot ('.') to end a sentence to exit:");
    do
    {
        c = getchar();
        if (c != ' ' && c != '.' && c != '\n')
        {
            /* This is a character of a word */
            /* Only save it if we have space */
            if (len < MaxWord)
            {
                str[len] = c;
                len++;
            }
        }
        else
        {
            /* The word is done */
            if (len != 0)
            {
                wordCount++;
                totalLength += len;
                str[len] = 0;
                if (len > maxLength)
                {
                    strcpy(longestWord, str);
                    maxLength = len;
                }
                printf("%s\n", str);
                len = 0;
            }
        }
    } while (c != '.');
    printf("average word length: %.2f\n", (double)totalLength / (double)wordCount);
    printf("The longest word: %s\n", longestWord);
}
