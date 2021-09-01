// ProblemNumber || ProblemName : P16172 - 나는 친구가 적다 (Large)
// 하면서 좀 더 깊게 생각하게 된 것들
// -> remove_if 함수를 사용해 특정 조건과 일치하는 문자를 뒤로 보내고 erase함수를 사용해 제거해준다
// -> remove_if(string.begin(), string.end(), [](unsigned char x) { return 조건 });
//
// -> strstr 함수를 이용해 두번째 문자열이 첫번째 문자열에 포함되는지 찾는다(부분 문자열 검색)
// -> strstr((char*)str1.c_str(), (char*)str2.c_str()) 반환값이 NULL이면 존재하지 않는다

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  string target;

  cin >> str;
  cin >> target;

  str.erase(remove_if(str.begin(), str.end(), [](unsigned char x) {
              return isdigit(x);
            }),
            str.end());

  if (strstr((char *)str.c_str(), (char *)target.c_str()) != NULL)
  {
    cout << 1 << endl;
  }
  else
    cout << 0 << endl;
}
