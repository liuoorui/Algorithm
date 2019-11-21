class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<size_t> window;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (!window.empty() && i + 1 > window.front() + k)
                window.pop_front();
            while (!window.empty() && nums[i] >= nums[window.back()])
                window.pop_back();
            window.push_back(i);

            if (i + 1 >= k)
                ans.push_back(nums[window.front()]);
        }

        return ans;
    }
};
