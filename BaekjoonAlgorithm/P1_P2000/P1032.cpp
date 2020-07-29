// Baekjoon 1032
// 문제
// 문자열 처리
// 명령 프롬프트

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string result = "";

    cin >> n;

    vector <string> search_result(n);

    for(int i=0;i<n;i++){
        cin >> search_result[i];
    }

    if(n == 1){
        cout << search_result[0];
        return 0;
    }

    for(int i=0;i<search_result[0].length();i++){
        char temp = search_result[0][i];
        for(int j=1;j<search_result.size();j++){
            if(search_result[j][i] != temp){
                result += "?";
                break;
            }
            
            if(j+1 == search_result.size()){
                result += temp;
            }
        }
    }

    cout << result << endl;
}