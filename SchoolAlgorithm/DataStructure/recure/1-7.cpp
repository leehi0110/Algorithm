// 1주차
// recure-7

#include <iostream>
#include <vector>
#include <string>

using namespace std;
int recureFind(string s,char target,int n);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);

    string s;
    char target;

    cin >> s;
    cin >> target;

    cout << recureFind(s,target,s.length()-1);
}

int recureFind(string s,char target,int n)
{
    if(n == 0){
        return s[n] == target ? 1 : 0;
    }
    else {
        return s[n] == target ? 1 + recureFind(s,target,n-1) : 0 + recureFind(s,target,n-1);
    }
}