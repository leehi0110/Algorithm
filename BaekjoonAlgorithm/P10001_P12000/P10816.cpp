// Baekjoon 10816
// 문제
// 숫자 카드 2

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int card_cnt;
    map <int,int> my_card;

    cin >> card_cnt;

    while(card_cnt--){
        int card_number;

        cin >> card_number;

        if(my_card.find(card_number) == my_card.end()){
            my_card.insert(pair<int,int>(card_number,1));
        }
        else {
            my_card[card_number]++;
        }
    }

    int check_card_cnt;

    cin >> check_card_cnt;

    while(check_card_cnt--){
        int card_number;

        cin >> card_number;
        
        if(my_card.find(card_number) == my_card.end()){
            cout << 0 << " ";
        }
        else {
            cout << my_card[card_number] << " ";
        }
    }
    cout << endl;
}