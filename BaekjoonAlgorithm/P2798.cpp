// Baekjoon 2798
// 문제
// 블랙잭

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n , m;
    int max_sum = 0;

    cin >> n >> m;

    vector <int> card(n);

    for(int i=0;i<n;i++){
        cin >> card[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(card[i] + card[j] + card[k] <= m){
                    if(card[i] + card[j] + card[k] > max_sum){
                        max_sum = card[i] + card[j] + card[k];
                    }
                }
            }
        }
    }

    cout << max_sum;
}