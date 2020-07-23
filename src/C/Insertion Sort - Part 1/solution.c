#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void print(int ar_size, int *ar)
{
    for (int i = 0; i < ar_size; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

void insertionSort(int ar_size, int *ar)
{
    int small, sorted = 1, position;
    //finding the small value
    for (int i = 0; i < ar_size; i++)
    {
        if (ar[i] > ar[i + 1])
        {
            small = ar[i + 1];
            position = i;
            break;
        }
    }

    //sort the array and print
    while (sorted != 0)
    {

        ar[position + 1] = ar[position];
        print(ar_size, ar);
        if (small < ar[position - 1])
        {
            position--;
            continue;
        }

        ar[position] = small;
        print(ar_size, ar);
        sorted = 0;
    }
}

int main(void)
{

    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for (_ar_i = 0; _ar_i < _ar_size; _ar_i++)
    {
        scanf("%d", &_ar[_ar_i]);
    }

    insertionSort(_ar_size, _ar);

    return 0;
}