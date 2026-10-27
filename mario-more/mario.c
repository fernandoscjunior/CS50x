#include <cs50.h>
#include <stdio.h>

void print_bricks(int num);

int main(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while (num < 1);

    print_bricks(num);
}

void print_bricks(int num)
{
    for (int i = 0; i < num; i++) // Will print row "num" times
    {
        for (int j = 0; j < num; j++) // Will print the left half of the pyramid "num" times
        {
            if (j < num - 1 - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  "); // Print two spaces between the left and right half of the pyramid

        for (int k = num - 1 - i; k < num;
             k++) // Will print the right half of the pyramid "num" times
        {
            if (k > num)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("\n");
    }
}
