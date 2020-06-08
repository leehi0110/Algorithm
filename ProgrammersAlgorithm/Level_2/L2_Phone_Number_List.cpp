#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool length_order(string a,string b);

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(),phone_book.end(),length_order);

    for(int i=0;i<phone_book.size();i++){
        for(int j=i+1;j<phone_book.size();j++){
            if(phone_book[j].find(phone_book[i]) == 0){
                answer = false;
                break;
            }
        }
        if(!answer) break;
    }


    return answer;
}

bool length_order(string a,string b){
    return a.length() < b.length() ? true : false;
}