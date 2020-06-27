#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector <string> a_vec, b_vec;
    vector <string> result_u,result_i;
    vector <string>::iterator iter;

    std::transform(str1.begin(),str1.end(),str1.begin(),::toupper);
    std::transform(str2.begin(),str2.end(),str2.begin(),::toupper);

    for(int i=0;i<str1.size()-1;i++){
        string tmp = "";
        if((str1[i] >= 'A' && str1[i] <= 'Z') && (str1[i+1] >= 'A' && str1[i+1] <= 'Z')){
            tmp += str1[i];
            tmp += str1[i+1];
            a_vec.push_back(tmp);
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        string tmp = "";
        if((str2[i] >= 'A' && str2[i] <= 'Z') && (str2[i+1] >= 'A' && str2[i+1] <= 'Z')){
            tmp += str2[i];
            tmp += str2[i+1];
            b_vec.push_back(tmp);
        }
    }

    sort(a_vec.begin(),a_vec.end());
    sort(b_vec.begin(),b_vec.end());

    result_u.resize(a_vec.size()+b_vec.size());
    iter = set_union(a_vec.begin(), a_vec.end(), b_vec.begin(), b_vec.end(), result_u.begin());
    result_u.resize(iter - result_u.begin());
    // 합집합
    result_i.resize(a_vec.size()+b_vec.size());
    iter = set_intersection(a_vec.begin(), a_vec.end(), b_vec.begin(), b_vec.end(), result_i.begin());
    result_i.resize(iter - result_i.begin());
    // 교집합

    double a = static_cast<double>(result_i.size());
    double b = static_cast<double>(result_u.size());

    return b == 0 ? 65536 : static_cast<int>((a/b)*65536);
}