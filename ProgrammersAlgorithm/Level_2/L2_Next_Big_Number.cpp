#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int solution(int n) {
    int bigN = n;

    while(1){
        bigN ++;

        string s1 = bitset<30>(n).to_string();
        string s2 = bitset<30>(bigN).to_string();

        if(count(s1.begin(),s1.end(),'1') == count(s2.begin(),s2.end(),'1')) break;
    }
    return bigN;
}