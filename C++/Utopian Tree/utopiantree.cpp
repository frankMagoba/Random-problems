#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n)
{
    int h[61], i;
    h[0] = 1;
    for (i = 1; i < 61; i++)
    {
        if (i % 2 != 0)
            h[i] = h[i - 1] * 2;
        else
            h[i] = h[i - 1] + 1;
    }
    return h[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
