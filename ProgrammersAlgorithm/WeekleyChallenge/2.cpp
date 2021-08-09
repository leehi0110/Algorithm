#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<vector<int>> scores)
{
  string answer = "";

  for (int i = 0; i < scores.size(); i++)
  {
    int sum = 0;
    double avg;
    int maxScore = -1;
    int minScore = 101;
    int maxIdx = 0, minIdx = 0;

    for (int j = 0; j < scores.size(); j++)
    {
      if (scores[j][i] > maxScore)
      {
        maxScore = scores[j][i];
        maxIdx = j;
      }
      else if (scores[j][i] == maxScore)
      {
        maxIdx += j;
      }

      if (scores[j][i] < minScore)
      {
        minScore = scores[j][i];
        minIdx = j;
      }
      else if (scores[j][i] == minScore)
      {
        minIdx += j;
      }

      sum += scores[j][i];
    }

    if (maxScore == scores[i][i] && maxIdx == i)
    {
      avg = double(sum - maxScore) / (scores.size() - 1);
    }
    else if (minScore == scores[i][i] && minIdx == i)
    {
      avg = double(sum - minScore) / (scores.size() - 1);
    }
    else
    {
      avg = double(sum) / scores.size();
    }

    if (avg >= 90)
      answer += "A";
    else if (avg >= 80)
      answer += "B";
    else if (avg >= 70)
      answer += "C";
    else if (avg >= 50)
      answer += 'D';
    else
      answer += "F";
  }

  return answer;
}

int main()
{
  // string result = solution({{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}});

  string result = solution({{50, 90}, {50, 87}});

  cout << result << endl;
}