#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int *nums = (int*) malloc((digits.size()+1)*sizeof(int)), 
            i = digits.size(), carry = 1;
        nums[0] = 1;
        
        while (i > 0) {
            int num = digits[i-1] + carry;
            
            nums[i--] = num % 10;
            carry = num / 10;
        }
        
        if (carry) return vector<int>(nums, nums+digits.size()+1);
        else return vector<int>(nums+1, nums+digits.size()+1);
    }
};