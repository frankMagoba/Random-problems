#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr)
{
    int iMax = -9 * 6 * 6;
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            int iSum = 0;
            for (int i = r, m = 0; i <= r + 2; ++i, ++m)
            {
                for (int j = c, n = 0; j <= c + 2; ++j, ++n)
                {
                    if (m != 1)
                    {
                        iSum += arr[i][j];
                    }
                    else
                    {
                        if (n == 1)
                        {
                            iSum += arr[i][j];
                        }
                    }
                }
            }
            iMax = std::max(iMax, iSum);
        }
    }
    return iMax;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++)
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
