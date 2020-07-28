// Baekjoon 1100
// 문제
// 문자열 처리
// 하얀 칸

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    vector <string> chess(8);
    int white_cnt = 0;
    bool color_flag = false; // 흰색일때 true

    for(int i=0;i<8;i++){
        cin >> chess[i];
    }

    for(int i=0;i<8;i++){
        color_flag = !color_flag;
        for(int j=0;j<chess[i].length();j++){
            if(chess[i][j] == 'F' && color_flag){
                white_cnt++;
            }
            color_flag = !color_flag;
        }
    }

    cout << white_cnt << endl;
}