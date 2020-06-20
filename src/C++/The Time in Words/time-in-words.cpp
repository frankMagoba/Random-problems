#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string words[30] = {string("one"), string("two"), string("three"), string("four"), string("five"), string("six"), string("seven"), string("eight"), string("nine"), string("ten"), string("eleven"), string("twelve"), string("thirteen"), string("fourteen"), string("fifteen"), string("sixteen"), string("seventeen"), string("eighteen"), string("nineteen"), string("twenty"), string("twenty one"), string("twenty two"), string("twenty three"), string("twenty four"), string("twenty five"), string("twenty six"), string("twenty seven"), string("twenty eight"), string("twenty nine")};

int main()
{
    int H, M;
    cin >> H >> M;
    if (M == 0)
    {
        printf("%s o' clock\n", words[H - 1].c_str());
    }
    else if (M == 1)
    {
        printf("one minute past %s\n", words[H - 1].c_str());
    }
    else if (M == 15)
    {
        printf("quarter past %s\n", words[H - 1].c_str());
    }
    else if (M < 30)
    {
        printf("%s minutes past %s\n", words[M - 1].c_str(), words[H - 1].c_str());
    }
    else if (M == 30)
    {
        printf("half past %s\n", words[H - 1].c_str());
    }
    else if (M == 45)
    {
        printf("quarter to %s\n", words[H % 12].c_str());
    }
    else if (M == 59)
    {
        printf("one minute to %s\n", words[H % 12].c_str());
    }
    else
    {
        printf("%s minutes to %s\n", words[60 - M - 1].c_str(), words[H % 12].c_str());
    }

    return 0;
}