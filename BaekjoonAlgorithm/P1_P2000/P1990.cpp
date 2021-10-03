// ProblemNumber || ProblemName : P1990 - 소수인팰린드롬
// 하면서 좀 더 깊게 생각하게 된 것들
// ->

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;
bool isPalindromes(int n);
bool isPrimes(int n);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  vector<int> palindromes;

  cin >> a >> b;

  if(b > 10000000) b = 10000000;

  for(int i=a;i<=b;i++) {
    if(isPalindromes(i)) palindromes.push_back(i);
  }

  for(int i=0;i<palindromes.size();i++) {
    if(isPrimes(palindromes[i])) cout << palindromes[i] << endl;
  }
  cout << -1 << endl;
}

bool isPrimes(int n) {
  
  for(int i=2;i<=sqrt(n);i++) {
    if(n%i == 0) return false;
  }
  return true;
}

bool isPalindromes(int n){
  string s1 = to_string(n);
  string s2 = s1;

  reverse(s1.begin(), s1.end());

  if(s1 == s2) return true;
  else return false;
}
