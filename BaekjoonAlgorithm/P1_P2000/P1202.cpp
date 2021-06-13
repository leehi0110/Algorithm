// ProblemNumber || ProblemName : P1202 - 보석 도둑
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int result = 0;
    priority_queue<pair<int, int>> gem;
    vector<int> bag;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int weight, value;

        cin >> weight >> value;

        gem.push({value, weight});
    }

    for (int i = 0; i < k; i++)
    {
        int weight;

        cin >> weight;

        bag.push_back(weight);
    }

    sort(bag.begin(), bag.end());

    while (!gem.empty())
    {
        int value = gem.top().first;
        int weight = gem.top().second;

        gem.pop();

        for (int j = 0; j < bag.size(); j++)
        {
            if (bag[j] >= weight)
            {
                result += value;
                bag.erase(bag.begin() + j);
                break;
            }
        }
    }

    cout << result << endl;
}

// 3 2
// 1 65
// 5 23
// 2 99
// 10
// 2

// 3 2
// 5 97
// 4 98
// 5 99
// 5
// 4