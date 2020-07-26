// Baekjoon 2309
// 문제
// 일곱 난쟁이

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    vector <int> tall;
    vector <int> real;
    vector <int>::iterator traverse;
    int height_sum,i,j;

    for(int i=0;i<9;i++){
        int height;

        cin >> height;
        tall.push_back(height);
    }

    i = 0;
    j = 1;

    while(1){

        height_sum = 0;

        for(int k=0;k<9;k++){
            if(k != i && k != j){
                height_sum += tall[k];
            }
        }

        if(height_sum == 100) break;
        else j++;

        if(j == 9) {
            i++;
            j = i+1;
        }
    }

    for(int k=0;k<9;k++){
        if(k != i && k != j){
            real.push_back(tall[k]);
        }
    }

    sort(real.begin(),real.end());

    for(int k : real){
        cout << k << endl;
    }
}