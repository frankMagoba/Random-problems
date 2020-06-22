#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void choco(int n, int m, int c)
{
    int nos = n / m;
    int ans = nos;
    while (nos >= c)
    {
        ans++;
        nos = nos - c;
        nos++;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        choco(n, c, m);
    }
    return 0;
}