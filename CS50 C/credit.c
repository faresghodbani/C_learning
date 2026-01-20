#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long number = get_long("Number: ");

    int sum = 0;
    int position = 0;
    long temp = number;

    while (temp > 0)
    {
        int digit = temp % 10;

        if (position % 2 == 1)
        {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
        position++;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int length = position;
    long start = number;
    while (start >= 100)
    {
        start /= 10;
    }

    if (length == 15 && (start == 34 || start == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (start >= 51 && start <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
