// 1주차
// recure-6

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void gcd(int a,int b);

int main()
{
    // ios_base :: sync_with_stdio(false);
    // cin.tie(NULL);
    
    int a,b;

    cin >> a >> b;

    if(a > b) gcd(a,b);
    else gcd(b,a);
}

void gcd(int a,int b)
{

    if(a%b == 0){
        cout << b << endl;
        return;
    }
    else {
        gcd(b,a%b);
        // return;
    }
}