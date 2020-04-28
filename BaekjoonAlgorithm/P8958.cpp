// Baekjoon 8958
// 문제
// OX퀴즈

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);

    int test_case;
    int score_sum ;
    int now_score;
    string bingo;

    cin >> test_case;

    for(int i=0;i<test_case;i++){
        cin >> bingo;
        now_score = 0;
        score_sum = 0;

        for(int j=0;j<bingo.length();j++){
            if(bingo[j] == 'O'){
                now_score ++;
                score_sum += now_score;
            }
            else {
                now_score = 0;
            }
        }

        cout << score_sum << endl;
    }

}