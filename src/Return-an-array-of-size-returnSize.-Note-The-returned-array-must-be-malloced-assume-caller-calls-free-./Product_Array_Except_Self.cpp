/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    if(!nums || !numsSize)
        return 0;
    int* res = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int product = 1;
    res[0] = 1;
    for(int i = 0; i < numsSize - 1; i++){
        res[i+1] = 1;
        product *= nums[i];
        res[i+1] = product;
    }
    
    product = 1;
    for(int i = numsSize - 1; i > 0;  i--){
        product *= nums[i];
        res[i-1] *= product;
    }
    
    return res;
}
