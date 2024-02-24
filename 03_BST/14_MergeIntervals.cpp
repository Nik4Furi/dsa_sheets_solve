vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         
         sort(intervals.begin(),intervals.end());
         
         vector<vector<int>> ans;
         int n = intervals.size();
         
         for(int i=0;i<n;i++){
             //is empty
             if(ans.empty() || ans.back()[1] < intervals[i][0])
                ans.push_back(intervals[i]);
            //o/w compare
            else
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
         }
         return ans;
    }