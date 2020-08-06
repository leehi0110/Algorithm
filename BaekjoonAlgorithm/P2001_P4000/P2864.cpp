// Baekjoon 2864
// 문제
// 문자열
// 5와 6의 차이

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string n, m;
    string max_n = "",max_m = "";
    string min_n = "",min_m = "";

    cin >> n >> m;

    for(int i=0;i<n.length();i++){
        if(n[i] == '5'){
            max_n += "6";
            min_n += n[i];
        }
        else if(n[i] == '6'){
            max_n += n[i];
            min_n += "5";
        }
        else {
            max_n += n[i];
            min_n += n[i];
        }
    }

    for(int i=0;i<m.length();i++){
        if(m[i] == '5'){
            max_m += "6";
            min_m += m[i];
        }
        else if(m[i] == '6'){
            max_m += m[i];
            min_m += "5";
        }
        else {
            max_m += m[i];
            min_m += m[i];
        }
    }

    cout << stoi(min_m) + stoi(min_n) << " " << stoi(max_m) + stoi(max_n) << endl;
}
