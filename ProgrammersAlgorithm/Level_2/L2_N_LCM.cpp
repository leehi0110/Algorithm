#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int LCM(int a,int b);
int GCD(int a,int b);

int solution(vector<int> arr) {
    int lcm = 1;

    for(int i=0;i<arr.size();i++){
        lcm = LCM(lcm,arr[i]);
    }
    return lcm;
}

int GCD(int a,int b)
{
    int c;

    while(b != 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
} // 최대 공약수

int LCM(int a,int b)
{
    return (a*b)/GCD(a,b);
} // 최소공배수
