#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
  vector<int> answer;
  vector<int> rank = {6, 6, 5, 4, 3, 2, 1};
  int zeroCnt = 0;
  int correctCnt = 0;

  for (int i = 0; i < lottos.size(); i++)
  {
    if (lottos[i] == 0)
      zeroCnt++;
    else if (find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
    {
      correctCnt++;
    }
  }

  answer.push_back(rank[correctCnt + zeroCnt]);
  answer.push_back(rank[correctCnt]);

  return answer;
}

int main()
{
  vector<int> result = solution({44, 1, 0, 0, 31, 25}, {31, 10, 45, 1, 6, 19});

  cout << result[0] << " " << result[1] << endl;
}