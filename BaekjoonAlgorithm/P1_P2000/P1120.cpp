// Baekjoon 1120
// 문제
// 문자열

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string x, y;
    int min_dif;

    cin >> x >> y;

    min_dif = x.length();

    for(int i=0;i<=y.length()-x.length();i++){
        int temp = 0;
        for(int j=0;j<x.length();j++){
            if(x[j] != y[i+j]) temp ++;
        }
        if(temp < min_dif) min_dif = temp;
    }
    cout << min_dif << endl;
}