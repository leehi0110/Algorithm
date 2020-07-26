// Baekjoon 5543
// 문제
// 상근날드

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> burger;
    vector <int> drink;
    int cheap;
    
    for(int i=0;i<5;i++){
        int price;
        cin >> price;

        if(i<3){
            burger.push_back(price);
        }
        else {
            drink.push_back(price);
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            if(i == 0 && j == 0){
               cheap = burger[i] + drink[j];
            }
            else {
                if(burger[i] + drink[j] < cheap){
                    cheap = burger[i] + drink[j];
                }
            }
        }
    }

    cout << cheap-50 << endl;


}