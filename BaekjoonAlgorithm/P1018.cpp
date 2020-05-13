// Baekjoon 1018
// 문제
// 체스판 다시 칠하기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int min = 1000000000;
    char first_color;

    cin >> n >> m;
    
    vector <vector <char>> chess(n,vector<char>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> chess[i][j];
        }
    }

    for(int i=0;i<m-7;i++){
        for(int j=0;j<n-7;j++){



        }
    }
}