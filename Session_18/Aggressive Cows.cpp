class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int l = 1;
        int h = stalls.back() - stalls.front();
        int ans = 0;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (canPlace(stalls, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
    
private:
    bool canPlace(vector<int>& arr, int k, int mid) {
        int last = arr[0];
        int count = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - last >= mid) {
                last = arr[i];
                count++;
                
                if (count == k)
                    return true;
            }
        }
        
        return false;
    }
};
