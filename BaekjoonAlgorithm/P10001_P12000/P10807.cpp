// ProblemNumber || ProblemName : P10807 - 개수 세기
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int v;
  vector<int> numbers(201,0);

  cin >> n;

  for(int i=0;i<n;i++) {
    int num;
    cin >> num;

    numbers[num+100]++;
  }

  cin >> v;

  cout << numbers[v+100] << endl;
  
}