// Baekjoon 1543
// 문제
// 그리디
// 문서 검색

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string document_name;
    string search;

    int cnt = 0;

    getline(cin,document_name);
    getline(cin,search);

    int search_length = search.length();

    while(document_name.length() >= search_length){

        int index = document_name.find(search);
        if(index == -1) break;
        else {
            cnt ++;
            document_name.erase(document_name.begin(),document_name.begin()+index+search_length);
        }
    }

    cout << cnt << endl;
}