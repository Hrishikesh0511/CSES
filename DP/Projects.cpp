// There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day.
// What is the maximum amount of money you can earn?
// Input
// The first input line contains an integer n: the number of projects.
// After this, there are n lines. Each such line has three integers a_i, b_i, and p_i: the starting day, the ending day, and the reward.
// Output
// Print one integer: the maximum amount of money you can earn.
// Constraints

// 1 \le n \le 2 \cdot 10^5
// 1 \le a_i \le b_i \le 10^9
// 1 \le p_i \le 10^9

// Example
// Input:
// 4
// 2 4 4
// 3 6 6
// 6 8 2
// 5 7 3

// Output:
// 7
// Approach:
// By seeing the constraints we can say that it has to be solved in near to nlogn time
// bascially the first option I had is to go with greedy So I will just sort it based on the amount and pick up the last element
// in the series and check whether I can do any other project after this or before this
// For the above example if we apply it the first project we pick up 3 6 6 and we can clearly see that no other project before this or after this can be chosen
// so the total amount I gained in this approach is 6 But which is not the maximum possible.So the greedy approach clearly fails here.
// So the only other option we had here is to explore all the possible ways
// Now I will sort the projects based on their starting times
// Now before chosing the project I had two choices in every step i.e., either to chose the project(if compatible completion time of the last project is less than starting time of current project)
// or avoid the project and go for the next project
// so to memoize the solution I had one difficulty that is by the given constraints it is not possible to construct dp array of size 1e9 * 1e5
// To avoid this instead of storing the lasttime I will store the last index where I had taken
// But this approach fails tooo.. because it is an O(N^2) approach
// so we think of an approach as before but instead of linearly searching for the next possible project one we just do a binary search thing as it is already sorted
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool compare(ll a,ll b){
    return a<=b;
}
ll f(int indx, vector<vector<ll>> &arr, vector<ll> &dp, vector<ll> &startDate)
{
    if (indx == arr.size())
    {
        return 0;
    }
    if (dp[indx] != -1) return dp[indx];

    ll take = 0, nottake = 0;
    ll j = abs(lower_bound(startDate.begin(), startDate.end(), arr[indx][1],compare) - startDate.begin());
    take = arr[indx][2] + f(j, arr, dp, startDate);
    nottake = f(indx + 1, arr, dp, startDate);
    return dp[indx] = max(take, nottake);
}
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3));
    vector<ll> dp(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    sort(arr.begin(), arr.end());
    vector<ll> startDate(n);
    for (int i = 0; i < n; i++)
    {
        startDate[i] = arr[i][0];
    }
    // sort(startDate.begin(), startDate.end());
    cout << f(0, arr, dp, startDate) << endl;
}