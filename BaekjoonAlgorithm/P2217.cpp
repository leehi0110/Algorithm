// Baekjoon 2217
// 문제
// 로프

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int roop_cnt;
    int max_weight = 0;
    int using_roop_cnt = 1;
    multiset <int,greater<int>> roop_weights;
    multiset <int>::iterator iter;

    cin >> roop_cnt;

    for(int i=0;i<roop_cnt;i++){
        int roop_weight;
        
        cin >> roop_weight;
        roop_weights.insert(roop_weight);
    }

    iter = roop_weights.begin();

    while(using_roop_cnt <= roop_weights.size()){
        if(max_weight <= using_roop_cnt * (*iter)){
            max_weight = using_roop_cnt * (*iter);
        }
        iter ++;
        using_roop_cnt++;
    }

    cout << max_weight << endl;

}