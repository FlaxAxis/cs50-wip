#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    string text = get_string("Text: "); /*asks for text */

    for (int i = 0; i < strlen(text); i++) /* goes through each character in the text */
    {
        if (isalpha(text[i])) /* counts letters */
        {
            letters += 1;
        }
        else if (isspace(text[i])) /* counts spaces */
        {
            words += 1;
        }
        else if (text[i] == 33 | text[i] == 46 | text[i] == 63) /* counts end punctuation */
        {
            sentences += 1;
        }
        else
        {
            continue;
        }
    }

    float lettersper = letters * 100/words;
    float sentencesper = sentences * 100/words;
    float coleman = (0.0588 * lettersper) - (0.296 * sentencesper) - 15.8;
    int grade = round(coleman);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}