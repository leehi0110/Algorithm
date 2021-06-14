// ProblemNumber || ProblemName : P1202 - 보석 도둑
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 주어진 범위를 주의 깊게 봐야된다.
// -> 모든 보석의 가치의 합이 int를 넘어갈 수 있기 때문에 long long 을 이용해서 결과를 출력한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int gemNum, bagNum;
    long long result = 0;
    priority_queue<pair<int, int>> gem;
    multiset<int> bag;

    cin >> gemNum >> bagNum;

    for (int i = 0; i < gemNum; i++)
    {
        int weight, value;

        cin >> weight >> value;

        gem.push({value, weight});
    }

    for (int i = 0; i < bagNum; i++)
    {
        int weight;

        cin >> weight;
        bag.insert(weight);
    }

    while (!gem.empty() && !bag.empty())
    {
        int value = gem.top().first;
        int weight = gem.top().second;

        gem.pop();

        auto it = bag.lower_bound(weight);

        if (it != bag.end())
        {
            result += static_cast<long long>(value);
            bag.erase(it);
        }
    }

    cout << result << endl;
}