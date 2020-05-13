// 1주차
// recure-3

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
        cout << num%10 << endl;
        recure_print(num/10);
    }
    else {
        cout << num << endl;
    }
}