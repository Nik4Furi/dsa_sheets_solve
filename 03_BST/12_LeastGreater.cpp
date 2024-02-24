
class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        
         map<int, int> mp;
        
        mp[arr[n - 1]]++;
        arr[n - 1] = -1;
        
        for (int i = n - 2; i >= 0; i--) { // O(N)
            mp[arr[i]]++; // O(logN)
            auto ub = mp.upper_bound(arr[i]); // O(logN)
            
            if (ub != mp.end()) {
                arr[i] = ub->first;
            } else {
                arr[i] = -1;
            }
        }
        return arr;
        
    }
};