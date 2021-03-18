// ProblemNumber || ProblemName : 1182 - 부분수열의 합

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dfs(vector<int> arr, int acc, int index, int target);

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    int answer = 0;

    cin >> n >> target;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        answer += dfs(arr, arr[i], i + 1, target);
    }

    cout << answer << endl;
}

int dfs(vector<int> arr, int acc, int index, int target)
{
    int reval = 0;
    if (acc == target)
        reval = 1;

    for (int i = index; i < arr.size(); i++)
    {
        reval += dfs(arr, acc + arr[i], i + 1, target);
    }
    return reval;
}