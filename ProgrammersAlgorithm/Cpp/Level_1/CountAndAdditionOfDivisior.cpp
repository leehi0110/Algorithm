#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getDivisorCnt(int number);
int solution(int left, int right)
{
  int answer = 0;

  for (int i = left; i <= right; i++)
  {
    if (getDivisorCnt(i) % 2 == 0)
      answer += i;
    else
      answer -= i;
  }

  return answer;
}

int getDivisorCnt(int number)
{

  int cnt = 0;

  for (int i = number; i > 0; i--)
  {
    if (number % i == 0)
      cnt++;
  }

  return cnt;
}

int main()
{
  // int result = solution(13, 17);
  int result = solution(24, 27);

  cout << result << endl;
}