// Baekjoon 1546
// 문제
// 평균

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int course_number;
    double input_score;
    double max_score=0;
    double change_score_sum=0;

    cin >> course_number; // 과목수

    vector <double> real_score;

    for(int i=0;i<course_number;i++){
        cin >> input_score;
        if(input_score > max_score) max_score = input_score; 

        real_score.push_back(input_score);
    }

    for(int i=0;i<real_score.size();i++){
        double changeScore = real_score[i]/max_score*100;
        change_score_sum += changeScore;
    }

    cout.fixed;
    cout.precision(9);
    cout << change_score_sum/static_cast<double>(course_number) << endl;

}