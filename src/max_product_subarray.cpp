/*
https://leetcode.com/problems/maximum-product-subarray/
*/
#include "std_headers.h"

#define max(a,b) (a>b?a:b)

int maxProduct(int* nums, int numsSize) {
	int even = 1;
	int totalProduct = 1, maxProduct = nums[0];
	int afterProduct = 0, beforeProduct = 0;
	for (int i = 0; i < numsSize; i++) {
		if (!nums[i]) {
			even = 1;
			totalProduct = 1;
			beforeProduct = 0;
			maxProduct = max(maxProduct, 0);
		}
		else {
			if (nums[i] < 0) {
				even = !even;
			}

			totalProduct *= nums[i];
			if (even) {
				maxProduct = max(maxProduct, totalProduct);
			}
			else {
				if (!beforeProduct) {
					beforeProduct = totalProduct;
				}
				else {
					maxProduct = max(maxProduct, totalProduct / beforeProduct);
				}
			}
		}
	}

	return maxProduct;
}