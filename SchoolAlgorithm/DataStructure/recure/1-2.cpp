// 1주차
// 재귀-2

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void recure_print(int num);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;

    cin >> n;

    recure_print(n);
}

void recure_print(int num)
{
    if(num > 10){
        recure_print(num/10);
    }
    else {
        cout << num << endl;
        return;
    }

    cout << num%10 << endl;
}