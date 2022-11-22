# Leetcode
My leetcode practice

## 280 Perfect Square
use static dp to store your dp[] result and save much time!
```
static vector<int> dp()
```
## 1927 BFS searching
some tricks:
1.
``` use vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};```
so that to search a pos' neighbor 
use
```
for(auto dir:dirs){
  int next_i=cur_i+dir.first,next_j=cur_j+dir.second;
}

