typedef struct {
    int start;
    int end;
    int count;
}Range;

class Solution {
    unordered_map<int, Range*> startMap;
    unordered_map<int, Range*> endMap;
public:
    int longestConsecutivex(vector<int>& nums) {
        int maxLength = 0;
        
        
        for(int i = 0; i < nums.size(); i++){
            int startRange = nums[i] + 1;
            int endRange = nums[i]-1;
            
            if(startMap[nums[i]] || endMap[nums[i]])
                continue;
            
            if(startMap[startRange] || endMap[endRange]){
                Range* pSr = startMap[startRange];
                Range* pEr = endMap[endRange];
                if(pSr){
                    pSr->start = nums[i];
                    pSr->count++;
                    startMap.erase(startRange);
                    startMap[nums[i]] = pSr;
                    maxLength = max(maxLength, pSr->count);
                }
                
                 if(pEr){
                    pEr->end = nums[i];
                    pEr->count++;
                    endMap.erase(endRange);
                    endMap[nums[i]] = pEr;
                    maxLength = max(maxLength, pEr->count);
                }
                
                if(pSr && pEr){
                    pEr->end = pSr->end;
                    pEr->count = pEr->count + pSr->count - 1;
                    startMap.erase(nums[i]);
                    endMap.erase(nums[i]);
                    endMap[pEr->end] = pEr;
                    delete pSr;
                    maxLength = max(maxLength, pEr->count);
                }
            }
            else{
                Range* pR = new Range;
                pR->start = nums[i];
                pR->end = nums[i];
                pR->count = 1;
                maxLength = max(maxLength, pR->count);
                
                startMap[nums[i]] = pR;
                endMap[nums[i]] =  pR;
            }
        }
        
        return maxLength;
    }
};
