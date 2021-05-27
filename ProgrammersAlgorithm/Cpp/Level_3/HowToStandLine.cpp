#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k)
{
  vector<int> answer;
  vector<string> ways;

  return answer;
}

int main()
{
  vector<int> result = solution(3, 5);

  for (auto i : result)
  {
    cout << i << " ";
  }
  cout << endl;
}

// 3 5 [1,2,3]
// 3! = 3 2 1

// 123
// 132
// 213
// 231
// 312
// 321

// n =  4 / k =  16 / num = [1,2,3,4]
// 4! = 4 3 2 1

// 16 % 4 = 0

// 1234   2134    3124    4123
// 1243   2143    3142    4132
// 1324   2314    3214    4213
// 1342   2341    3241 o  4231
// 1423   2413    3412    4312
// 1432   2431    3421    4321