#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    int minimumDistances(vector<int> A);
};
Solution::Solution() {}
int Solution::minimumDistances(vector<int> A)
{
    // Complete this function
    map<int, int> mp;
    vector<int> res;
    int pos(0);
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        if (mp.find(*iter) != mp.end())
        {
            res.push_back((abs(mp[*iter] - pos)));
            pos++;
            continue;
        }
        mp[*iter] = pos++;
    }
    if (res.size() == 0)
    {
        return -1;
    }
    return *(min_element(res.begin(), res.end()));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int a_i = 0; a_i < n; a_i++)
    {
        cin >> a[a_i];
    }
    int result = sol.minimumDistances(a);
    cout << result << endl;
    return 0;
}