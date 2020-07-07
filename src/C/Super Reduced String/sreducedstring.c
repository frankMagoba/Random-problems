#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int main()
{
    char *s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
    int l, i = 0, flag;
    l = strlen(s);
    do
    {
        flag = 0;
        for (i = 0; i < l - 1;)
        {
            if (s[i] == s[i + 1])
            {
                flag = 1;
                for (int j = i; j < l - 2; j++)
                    s[j] = s[j + 2];
                l = l - 2;
            }
            else
                i++;
        }
        s[l] = '\0';
    } while (flag == 1 && l > 0);
    if (l != 0)
        printf("%s", s);
    else
        printf("Empty String");
    return 0;
}