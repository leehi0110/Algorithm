// Baekjoon 2164
// 문제
// 카드2

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  int top_card;
  deque <int> card;

  cin >> n;

  for(int i=1;i<n+1;i++){
    card.push_back(i);
  }

  while(card.size() != 1){
    card.pop_front();
    
    top_card = card.front();
    card.pop_front();

    card.push_back(top_card);
  }

  cout << card[0] << endl;
}