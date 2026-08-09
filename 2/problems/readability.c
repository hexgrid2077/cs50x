#include <cs50.h>
#include <ctype.h> // This will help.
#include <stdio.h>
#include <string.h>

float get_sentences(string text);
float get_words(string text);
float get_letters(string text);

int main(void)
{
    string text = "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.";
    float sentences = get_sentences(text);
    float words = get_words(text);
    float letters = get_letters(text);

    printf("Sentences: %f\n", sentences);
    printf("Words: %f\n", words);
    printf("Letters: %f\n", letters);

    float L = letters / (words / 100);
    float S = sentences / (words / 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    printf("Index: %f\n", index);
    // L is the average number of letters per 100 words in the text
    // S is the average number of sentences per 100 words in the text.

    // Once we have that then we can pass out the grades.
}

float get_sentences(string text)
{
    float sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}

float get_words(string text)
{
    float words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    return words+1;
}

float get_letters(string text)
{
    float letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i])) // The isalpha thing here.
        {
            letters += 1;
        }
    }
    return letters;
}