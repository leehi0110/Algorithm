// ProblemNumber || ProblemName : P1068 - 트리
// 하면서 좀 더 깊게 생각하게 된 것들
// -> 처음 입력이 들어오는 0의 번호를 가진 노드가 항상 루트가 아니다
// -> -1이 들어올때 i, 즉 i번의 노드가 루트 노드가 된다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int node;
int root;
int deleteNode;
int upTree[51];
vector<vector<int>> downTree(51);

int calLeaf(int nodeNum);
int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> node;

  for (int i = 0; i < node; i++)
  {
    int parent;

    cin >> parent;

    if (parent == -1)
    {
      root = i;
    }
    else
    {
      downTree[parent].push_back(i);
      upTree[i] = parent;
    }
  }

  cin >> deleteNode;

  if (deleteNode == root)
    cout << 0 << endl;
  else
  {
    int deleteParent = upTree[deleteNode]; // 삭제할 노드의 부모 노드 번호
    auto it = find(downTree[deleteParent].begin(), downTree[deleteParent].end(), deleteNode);
    downTree[deleteParent].erase(it);

    cout << calLeaf(root) << endl;
  }
}

int calLeaf(int nodeNum)
{
  if (downTree[nodeNum].size() == 0)
    return 1;
  else
  {
    int result = 0;
    for (int i = 0; i < downTree[nodeNum].size(); i++)
    {
      result += calLeaf(downTree[nodeNum][i]);
    }

    return result;
  }
}
