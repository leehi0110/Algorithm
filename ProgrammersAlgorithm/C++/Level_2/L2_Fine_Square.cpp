#include <iostream>
#include <algorithm>

using namespace std;
long long GCD(long long a, long long b);

long long solution(int w,int h) {
    long long answer = 1;
    long long lw = static_cast<long long>(w);
    long long lh = static_cast<long long>(h);
    long long block = GCD(lw,lh);

    return (lw*lh) - (lw+lh-block);
}

long long GCD(long long a, long long b)
{
    long long c;

    if(b>a){
        swap(a,b);
    }

    while(b){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}