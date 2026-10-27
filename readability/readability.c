#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_grade(int letters, int words, int sentences);

int main (void)
{
    string text = get_string("Insert text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = get_grade(letters, words, sentences);

    //Print the grade level
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade <= 0 )
    {
        printf("Before Grade 1\n");
    }
    else
        printf("Grade %d\n", grade);
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 0;

    //Increases word counter based on white spaces.
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    return words + 1;
}

int count_sentences(string text)
{
    int sentences = 0;

    //Increase senteces counter based on ".", "!" or "?".
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == 46)
        {
            sentences++;
        }
        else if (text[i] == 33)
        {
            sentences++;
        }
        else if (text[i] == 63)
        {
            sentences++;
        }

    }

    return sentences;
}

int get_grade(int letters, int words, int sentences)
{

    float l = letters;
    float w = words;
    float s = sentences;

    float L = l / w * 100;
    float S = s / w * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int final_index = round(index);

    return final_index;
}
