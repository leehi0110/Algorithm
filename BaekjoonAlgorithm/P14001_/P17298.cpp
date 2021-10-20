// ProblemNumber || ProblemName : P17298 - 오큰수
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
  vector<int> numbers;
  stack<pair<int,int>> st;
  
  cin >> n;

  vector<int> result(n+1,-1);

  for(int i=0;i<n;i++) {
    int number;
    cin >> number;

    numbers.push_back(number);
  }

  for(int i=0;i<numbers.size();i++) {
    int idx = i+1;
    int number = numbers[i];

    if(!st.empty()) {
      while(1) {
        if(!st.empty() && st.top().second < number) {
          result[st.top().first] = number;
          st.pop();
        } else break;
      }
    }

    st.push({idx, number});
  }

  for(int i=1;i<result.size();i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
