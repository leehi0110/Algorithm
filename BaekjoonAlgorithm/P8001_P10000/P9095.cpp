// ProblemNumber || ProblemName : P9095 - 1, 2, 3 더하기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int table[12];

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int testCase;

  memset(table, 0, 11 * sizeof(int));

  cin >> testCase;

  table[0] = 0;
  table[1] = 1;
  table[2] = 2;
  table[3] = 4;

  for (int i = 4; i <= 11; i++)
  {
    table[i] = table[i - 1] + table[i - 2] + table[i - 3];
  }
  // Logic

  for (int i = 0; i < testCase; i++)
  {
    int temp;
    cin >> temp;

    cout << table[temp] << endl;
  }
}

// [1] = 1
// 1

// [2] = 2
// 1 + 1
// 2

// [3] = 4
// 1 + 1 + 1
// 1 + 2 / 2 + 1
// 3

// [4] = 7
// 1 + 1 + 1 + 1
// 1 + 1 + 2 / 1 + 2 + 1 / 2 + 1 + 1 / 2 + 2
// 1 + 3 / 3 + 1

// [5] = 13
// 1 + 1 + 1 + 1 + 1
// 1 + 1 + 1 + 2 / 1 + 1 + 2 + 1 / 1 + 2 + 1 + 1 / 2 + 1 + 1 + 1 / 1 + 2 + 2 / 2 + 1 + 2 / 2 + 2 + 1
// 1 + 1 + 3 / 1 + 3 + 1 / 3 + 1 + 1
// 2 + 3 / 3 + 2
