// ProblemNumber || ProblemName : P14891 - 톱니바퀴
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

string gear[4];
int score[4] = {1, 2, 4, 8};
int left = 6;
int right = 2;

void rotateGear(int gearNumber, int direction);
void rotateRightSide(int gearNumber, int direction);
void rotateLeftSide(int gearNumber, int direction);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int time;
  int result = 0;

  for (int i = 0; i < 4; i++)
  {
    cin >> gear[i];
  }

  cin >> time;

  for (int i = 0; i < time; i++)
  {
    int gearNumber, direction;
    // 1 시계 방향 , -1 반시계 방향

    cin >> gearNumber >> direction;

    gearNumber--; // 1번부터 시작

    rotateLeftSide(gearNumber - 1, direction);
    rotateRightSide(gearNumber + 1, direction);

    rotateGear(gearNumber, direction);
  }

  for (int i = 0; i < 4; i++)
  {
    if (gear[i][0] == '1')
      result += score[i];
  }

  cout << result << endl;
}

void rotateLeftSide(int gearNumber, int direction)
{
  int leftGear = gearNumber;
  int rightGear = gearNumber + 1;

  if (leftGear >= 0)
  {
    if (gear[rightGear][6] != gear[leftGear][2])
    {
      rotateLeftSide(leftGear - 1, -1 * direction);
      rotateGear(leftGear, -1 * direction);
    }
  }
}

void rotateRightSide(int gearNumber, int direction)
{
  int leftGear = gearNumber - 1;
  int rightGear = gearNumber;

  if (rightGear <= 3)
  {
    if (gear[leftGear][2] != gear[rightGear][6])
    {
      rotateRightSide(rightGear + 1, -1 * direction);
      rotateGear(rightGear, -1 * direction);
    }
  }
}

void rotateGear(int gearNumber, int direction)
{
  string newGear;
  if (direction == 1)
  {
    newGear = gear[gearNumber][7] + gear[gearNumber].substr(0, gear[gearNumber].length() - 1);
  } // 정방향
  else
  {
    newGear = gear[gearNumber].substr(1, gear[gearNumber].length() - 1) + gear[gearNumber][0];
  } // 역방향
  gear[gearNumber] = newGear;
}

// 10101111
// 01111101
// 11001110
// 00000010