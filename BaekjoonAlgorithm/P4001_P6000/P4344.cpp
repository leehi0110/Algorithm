// Baekjoon 4344
// 문제
// 평균은 넘겠지

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    int score;
    int score_sum;
    int avg_cnt;
    double score_avg;
    int student_number;
    
    vector <int> student_score;

    cin >> test_case;

    for(int i=0;i<test_case;i++){
        cin >> student_number;
        score_sum = 0;
        avg_cnt = 0;
        student_score.clear();

        for(int j=0;j<student_number;j++){
            cin >> score;
            student_score.push_back(score);
            score_sum += score;
        }

        score_avg = static_cast<double>(score_sum)/student_number;

        for(int j=0;j<student_number;j++){
            if(student_score[j] > score_avg) avg_cnt ++;
        }

        cout.precision(3);
        cout << fixed << static_cast<double>(avg_cnt)/student_number*100 << "%" << endl;
    } 
}