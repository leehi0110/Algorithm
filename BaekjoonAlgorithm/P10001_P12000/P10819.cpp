// ProblemNumber || ProblemName : P10819 - 차이를 최대로
// 하면서 좀 더 깊게 생각하게 된 것들
// -> #include <algorithm>의 next_permutation()을 이용해 모든 조합을 구할 수 있다.
// -> next_permutation()을 사용할 경우 배열은 오름차순으로
// -> prev_permutation()을 사용할 경우 배열을 내림차순으로 정렬한 뒤 사용한다.
// -> next_permutation()은 완전히 역순이 될때까지 순열의 순서를 바꿔주고 완전히 역순이 된 마지막 순열 다음은 처음으로 되돌아간뒤 false를 반환

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int maxResult = 0;
  vector<int> arr;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int num;

    cin >> num;
    arr.push_back(num);
  }

  sort(arr.begin(), arr.end());
  do
  {
    int result = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
      result += abs(arr[i] - arr[i + 1]);
    }

    if (maxResult < result)
      maxResult = result;
  } while (next_permutation(arr.begin(), arr.end()));

  cout << maxResult << endl;
}