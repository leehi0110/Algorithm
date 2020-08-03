// Baekjoon 1302
// 문제
// 탐색
// 베스트 셀러

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int max_cnt = 0;
    string max_name;

    cin >> n;

    map <string,int> book_info;

    for(int i=0;i<n;i++){
        string book_name;

        cin >> book_name;

        if(book_info.find(book_name) == book_info.end()){
            book_info.insert(pair<string,int>(book_name,1));
        }
        else {
            book_info[book_name]++;
        }
    }

    map <string,int>::iterator iter;

    for(iter = book_info.begin();iter != book_info.end();iter++){
        if(iter->second > max_cnt){
            max_cnt = iter->second;
            max_name = iter->first;
        }
    }

    cout << max_name << endl;

}