# Leetcode
My leetcode practice

## 280 Perfect Square
use static dp to store your dp[] result and save much time!
```
static vector<int> dp()
```
## 907 Sum of Subarray Minimums
**monotonic stack**

using the data structure of monotonic stack to find previous smaller and next smaller data of the current data

see <https://leetcode.com/problems/sum-of-subarray-minimums/solutions/2700011/sum-of-subarray-minimums/> for details

for example: we have {0,2,4,6,8,10,5,7}
stack bottom-- 0--2--4--6--8--10-- stack top
for each data in stack, the upper ones are bigger than current data and the below ones are less than cur
{0,2,4} [6] {8,10}
to add 5, because 5 is less than 10, so next smaller for 10 is 5, and previous smaller for 10 is 8
pop(10)
[5] {0,2,4,6,8} next smaller for 8 is 5 and previous smaller for 8 is 6

[5]{0,2,4,6} next smaller for 6 is 5 and previous smaller for 6 is 4

[5]{0,2,4} add 5 to stack {0,2,4,5}

...

to rest of number in stack have qualities that its next smaller is arr.end() and previous smaller is previous number in stack




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
