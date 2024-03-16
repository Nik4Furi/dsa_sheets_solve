// you are required to complete this function 
// function should print the required range

//---------- User defined var
class Node{
    public:
    int data;
    int row;
    int col;
    
    Node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};

//------------- Sort
class cmp{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          
          
          //App, use minHeap to store all k's elements and finding minium range
          int maxi = INT_MIN, mini = INT_MAX;
          
          //store first k eles
          priority_queue<Node*,vector<Node*>,cmp> minH; //min heap
          
          for(int i=0;i<k;i++){
              Node* temp = new Node(KSortedArray[i][0],i,0);
              
              maxi = max(temp->data,maxi);
              mini = min(temp->data,mini);
              
              minH.push(temp);
          }
          
          //--------- Now traverse the heap and finding the range
          int st=mini,end=maxi;
          
          while(!minH.empty()){
              Node* top = minH.top();
              minH.pop();
              
              mini = top->data;
              
              if(maxi -mini < end-st)
                st = mini,end=maxi;
            
                //updating the next
                if(top->col+1 < n){
                    int ele = KSortedArray[top->row][top->col+1];
                    maxi = max(maxi,ele);
                    minH.push(new Node(ele,top->row,top->col+1));
                }
                else break;
              
          }
          
          return {st,end};
    }
};