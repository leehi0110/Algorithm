#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool comp(string a, string b) {
    string aHead = "", aNumber = "", aTail = "";
    string bHead = "", bNumber = "", bTail = "";
    
    int flag = 0;
    string subStr = "";
    
    for(int i=0;i<a.length();i++) {
        
        if(isdigit(a[i]) && flag == 0) {
            flag = 1;
            aHead = subStr;
            subStr = a[i];
        } else if(!isdigit(a[i]) && flag == 1) {
            flag = 2;
            aNumber = subStr;
            subStr = a[i];
        } else {
            subStr += a[i];
        }
        
        if(i == a.length()-1) aTail = subStr;
    }

    flag = 0;
    subStr = "";
    
    for(int i=0;i<b.length();i++) {
        
        if(isdigit(b[i]) && flag == 0) {
            flag = 1;
            bHead = subStr;
            subStr = b[i];
        } else if(!isdigit(b[i]) && flag == 1) {
            flag = 2;
            bNumber = subStr;
            subStr = b[i];
        } else {
            subStr += b[i];
        }
        
        if(i == b.length()-1) bTail = subStr;
    }

    transform(aHead.begin(), aHead.end(), aHead.begin(),::toupper);
    transform(bHead.begin(), bHead.end(), bHead.begin(),::toupper);
    int intANumber = stoi(aNumber);
    int intBNumber = stoi(bNumber);

    if(aHead == bHead) {
        if(intANumber > intBNumber) return false;
        else return true;
    } else if(aHead > bHead) return false;
    else return true;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(), comp);

    for(auto file : files) {
        cout << file << " ";
    }
    cout << endl;
    return files;
}