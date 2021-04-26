#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
  int answer = 0;

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  for (int i = 0, j = 0; j < B.size();)
  {
    if (A[i] < B[j])
    {
      answer++;
      i++;
    }
    j++;
  }

  return answer;
}

int main()
{
  int result = solution({5, 1, 3, 7}, {2, 2, 6, 8});
  // int result = solution({2, 2, 2, 2}, {1, 1, 1, 1});

  cout << result << endl;
}