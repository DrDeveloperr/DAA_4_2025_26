class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canEat(piles, mid, h)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool canEat(const vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int pile : piles)
            hours += (pile + k - 1) / k;
        return hours <= h;
    }
};
