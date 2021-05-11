// ProblemNumber || ProblemName : P2161 - 카드 1

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
  cin >> n;
  vector<int> card;

  for (int i = 0; i < n; i++)
  {
    card.push_back(i + 1);
  }

  while (card.size() != 1)
  {

    cout << card[0] << " ";
    card.erase(card.begin());

    card.push_back(card[0]);
    card.erase(card.begin());
  }
  cout << card[0] << endl;
}
