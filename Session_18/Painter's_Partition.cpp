class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, long long maxTime) {
        long long sum = 0;
        int painters = 1;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxTime) return false;
            if (sum + arr[i] > maxTime) {
                painters++;
                sum = arr[i];
            } else {
                sum += arr[i];
            }
        }
        return painters <= k;
    }
    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
