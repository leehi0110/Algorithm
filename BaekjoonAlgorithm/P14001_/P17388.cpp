// ProblemNumber || ProblemName : P17388 - 와글와글 숭고한
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

  vector<int> score;
  int sum = 0;

  for(int i=0;i<3;i++) {
    int s;

    cin >> s;

    score.push_back(s);
    sum += s;
  }

  if(sum >= 100) {
    cout << "OK" << endl;
  } else {
    int minIdx = min_element(score.begin(), score.end()) - score.begin();

    if(minIdx == 0) cout << "Soongsil" << endl;
    else if(minIdx == 1) cout << "Korea" << endl;
    else cout << "Hanyang" << endl;
  }
}