#include <stdio.h>

#include <stdlib.h>

#include <assert.h>

#include <math.h>

int main()

{

    int n, t;

    scanf("%d %d", &n, &t);

    long width[1000000];

    for (int i = 0; i < n; i++)

    {

        scanf("%ld", &width[i]);
    }

    int min = 0;

    int j, k;

    for (int i = 1; i <= t; i++)

    {

        scanf("%d %d", &j, &k);

        min = width[j];

        while (j <= k)

        {

            if (width[j] < min)

                min = width[j];

            j++;
        }

        printf("%d\n", min);
    }

    return 0;
}