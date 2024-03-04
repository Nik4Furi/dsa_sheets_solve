  vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        int i=0;
        int j=0;
        vector<int>mx;
        int maxi=INT_MIN;
        deque<int>dq;
        while(j<n){
            while(dq.size() >0 && dq.back()<arr[j]){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j-i+1 == k){
                mx.push_back(dq.front());
                if(dq.front()==arr[i]){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return mx;
    }