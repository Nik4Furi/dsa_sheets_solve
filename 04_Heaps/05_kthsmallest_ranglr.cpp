  int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        priority_queue<int> pq;
        
        for(int i=l;i<=r;i++)
            pq.push(arr[i]);
            
        int ind = r-l+1-k;
        
        while(ind){
            pq.pop();
            ind--;
        }
        
        return pq.top();
    }