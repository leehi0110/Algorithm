// ProblemNumber || ProblemName : 멀쩡한 사각형
// 문제
// 멀쩡한 사각형의 개수를 구하시오

using namespace std;

long long GCD(long long a, long long b) {
    return b ? GCD(b,a%b) : a;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long lw = static_cast<long long>(w);
    long long lh = static_cast<long long>(h);
    
    long long mul = lw*lh;
    
    return mul - (lw + lh - GCD(lw,lh));
    
}
