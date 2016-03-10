class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int idx = 0;
        int size = nums.size();
        int res = -1;
        while(idx < size){
            if(nums[idx] == idx || nums[idx] == size){
                if(nums[idx] == size)
                    res = idx;
                idx++;
                continue;
            }
            swap(nums[idx], nums[nums[idx]]);
        }
        
        return res == -1 ? size : res;
    }
};
