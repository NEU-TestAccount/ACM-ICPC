# 后缀自动机

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Node *iter;
const int Sigma = 26;
struct Node
{
  Node *nxt[Sigma], *link;
  friend void insert(Node * &cur, int ch)
  {

  }
};
```
