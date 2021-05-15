// ProblemNumber || ProblemName : P1655 - 가운데를 말해요

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

    priority_queue<int> left;
    priority_queue<int> right;

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num;

        cin >> num;

        if (i == 1)
        {
            left.push(num);
        }
        else if (i % 2 == 0)
        { // 짝수 일때
            if (num < left.top())
            {
                right.push(-1 * left.top());
                left.pop();
                left.push(num);
            }
            else
            {
                right.push(-1 * num);
            }
        }
        else
        { // 홀수 일때
            if (num > -1 * right.top())
            {
                left.push(-1 * right.top());
                right.pop();
                right.push(-1 * num);
            }
            else
            {
                left.push(num);
            }
        }
        cout << left.top() << "\n";
    }
}