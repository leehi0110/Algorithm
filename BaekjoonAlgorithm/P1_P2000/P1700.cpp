// ProblemNumber || ProblemName : P1700 - 멀티탭 스케쥴링
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 어떤 순서로 멀티탭을 빼고 껴야 하는지 규칙을 정하는 것이 풀이의 핵심

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int changeCnt = 0;
    queue<int> que;
    vector<int> order;
    vector<int> orderCnt(101, 0);
    vector<int> use;

    cin >> n >> k;

    if (n >= k)
    {
        cout << changeCnt << "\n";
        return 0;
    }

    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;

        order.push_back(temp);
        que.push(temp);
        orderCnt[temp]++;
    }

    while (!que.empty())
    {
        int nowOrder = que.front();
        que.pop();

        if (find(use.begin(), use.end(), nowOrder) != use.end())
        {
            orderCnt[nowOrder]--;
            order.erase(order.begin());
            continue;
        } // 현재 꽂아야 하는것이 이미 멀티탭에 꽂혀있는 경우
        else if (use.size() < n)
        {
            use.push_back(nowOrder);
            orderCnt[nowOrder]--;
            order.erase(order.begin());
            continue;
        } // 멀티탭이 남아있는 경우
        else
        {
            int minUse = -1;
            int lastUseIdx = -1;
            int lastUseVal;

            for (int i = 0; i < use.size(); i++)
            {
                if (orderCnt[use[i]] == 0)
                {
                    minUse = i;
                    break;
                }

                int nextUse = find(order.begin(), order.end(), use[i]) - order.begin();
                if (lastUseIdx < nextUse)
                {
                    lastUseIdx = nextUse;
                    lastUseVal = order[lastUseIdx];
                }
            }
            if (minUse != -1)
            {
                use.erase(use.begin() + minUse);
                use.push_back(nowOrder);
                orderCnt[nowOrder]--;
            }
            else
            {
                use.erase(find(use.begin(), use.end(), lastUseVal));
                use.push_back(nowOrder);
                orderCnt[nowOrder]--;
            }
            order.erase(order.begin());
            changeCnt++;

        } // 현재꽂아야 하는 것이 멀티탭에 꽂혀있지 않고 멀티탭의 여유 공간이 0인 경우
    }

    cout << changeCnt << "\n";
}

// 우선적으로 플러그에서 빼야되는 경우
// 1. 사용횟수가 더 이상 없는 경우(orderCnt[?] == 0)
// 2. 사용횟수가 더 높더라도 더 나중에 사용되는 경우
// 3. 사용횟수가 가장 낮은 경우