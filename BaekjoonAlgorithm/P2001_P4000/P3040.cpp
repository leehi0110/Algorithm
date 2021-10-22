// ProblemNumber || ProblemName : P3040 - 백설 공주와 일곱 난쟁이
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

  vector<int> nums;

  for(int i=0;i<9;i++) {
    int num;

    cin >> num;

    nums.push_back(num);
  }

  sort(nums.begin(), nums.end());

  do {

    int sum = 0;
    for(int i=0;i<7;i++) {
      sum += nums[i];
    }

    if(sum == 100) break;

  } while(next_permutation(nums.begin(), nums.end()));

  for(int i=0;i<7;i++) {
    cout << nums[i] << endl;
  }
}