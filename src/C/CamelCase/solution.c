#include <stdio.h>
#include <string.h>
int main()
{
    char str[100000];
    scanf("%s", str);
    int ans = 1, i; //ans=1 because all letters in the first word are small
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        { //checking uppercase letter
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}