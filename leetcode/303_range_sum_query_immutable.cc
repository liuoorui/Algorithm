class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = nums;
        sums_.resize(nums_.size(), 0);
        
        int sum = 0;
        for (size_t i = 0; i < nums_.size(); ++i) {
            sum += nums_[i];
            sums_[i] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return sums_[j] - sums_[i] + nums_[i];
    }
private:
    vector<int> sums_;
    vector<int> nums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
