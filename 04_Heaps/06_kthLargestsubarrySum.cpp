class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int sum;
        
        int cnt = K;
        
        for(int i=0;i<N;i++){
            sum = Arr[i];
            if(cnt){
                pq.push(sum);
                cnt--;
            }
            else if(pq.top() < sum){
                pq.pop();
                pq.push(sum);
            }
            
            
            for(int j=i+1;j<N;j++){
                sum += Arr[j];
                    if(cnt){
                        pq.push(sum);
                        cnt--;
                    }
                    else if(pq.top() < sum){
                        pq.pop();
                        pq.push(sum);
                    }
            }
        }
        
        return pq.top();
    }
};