/*
Given two n-ary trees. Check if they are mirror images of each other or not. You are also given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each array has 2*e space separated values u,v denoting an edge from u to v for the both trees.


Example 1:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 3, 1, 2}
Output:
1
Explanation:
   1          1
 / \        /  \
2   3      3    2 
As we can clearly see, the second tree
is mirror image of the first.
Example 2:

Input:
n = 3, e = 2
A[] = {1, 2, 1, 3}
B[] = {1, 2, 1, 3}
Output:
0
Explanation:
   1          1
 / \        /  \
2   3      2    3 
As we can clearly see, the second tree
isn't mirror image of the first.
*/

//use two maps in respect of i, consider next ele
//then traverse 1 map one by and one and check its reverse is equal to m2 eles
// tC O(e), sC O(e)


class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        
        unordered_map<int,vector<int>> m1,m2;
        
        for(int i=0;i<2*e;i+=2){
            m1[A[i]].push_back(A[i+1]);
            m2[B[i]].push_back(B[i+1]);
        }
        
        for(auto it:m1){
            reverse(it.second.begin(),it.second.end());
            
            if(it.second != m2[it.first]) return false;
        }
        return true;
    }
};