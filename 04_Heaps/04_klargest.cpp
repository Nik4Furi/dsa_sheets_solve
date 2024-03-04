vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    
	    priority_queue<int> pq;
	    
	    for(int i=0;i<n;i++)
	        pq.push(arr[i]);
	       
	   vector<int> ans;
	   
	        
	    while(k--){
	        int top = pq.top();
	        pq.pop();
	        ans.push_back(top);
	    }
	    
	    return ans;
	}
