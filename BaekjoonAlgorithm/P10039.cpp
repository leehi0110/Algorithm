// Baekjoon 10039
// 문제
// 평균 점수

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int sum=0;
    vector<int> score(5);
    
    for(int i=0;i<5;i++){
        cin >> score[i];
        if(score[i] < 40){
            sum += 40;
        }
        else {
            sum += score[i];
        }
    }
    cout << sum/5 << endl;
}