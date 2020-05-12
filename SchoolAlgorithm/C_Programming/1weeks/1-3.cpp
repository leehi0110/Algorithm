// 1주차
// C 프로그래밍 시작하기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int a;

    cin >> a;

    cout << '\n';
    
    for(int i=0;i<4;i++){
        if(i == 1 || i == 2){
            cout << a << "    " << a << "\n";
        }
        else {
            for(int j = 0;j<6;j++){
                cout << a;
            }
            cout << "\n";
        }
    }
}