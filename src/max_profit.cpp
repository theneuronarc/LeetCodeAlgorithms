/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include "std_headers.h"

int maxProfit(int* prices, int pricesSize) {
	int buy = 0, sell = 1;
	int minBuy = sell;
	int profit = (pricesSize > 1 ? prices[sell] - prices[buy] : 0);

	for (int day = 2; day < pricesSize; day++) {
		if (prices[day] - prices[buy] > profit) {
			profit = prices[day] - prices[buy];
			sell = day;
		}

		if (prices[day] - prices[minBuy] > profit) {
			buy = minBuy;
			sell = day;
			profit = prices[sell] - prices[buy];
		}

		minBuy = (prices[minBuy] > prices[day] ? day : minBuy);
	}
	return (profit > 0 ? profit : 0);
}

int maxProfit2(int* prices, int pricesSize) {
	int buy = 0, sell = 1;
	int profit = (pricesSize > 1 ? prices[sell] - prices[buy] : 0);

	while (sell < pricesSize - 1) {
		if (prices[sell] - prices[buy] < 0) {
			buy++;
			sell++;
			continue;
		}

		if (prices[sell + 1] >= prices[sell]) {
			sell++;			
		}
		else {
			profit += (prices[sell] - prices[buy]);
			buy = sell + 1;
			sell = buy + 1;			
		}
	}

	if (sell >= pricesSize)
		return profit;
	else {
		int lastProfit = prices[sell] - prices[buy];
		profit += (lastProfit > 0 ? lastProfit : 0);
		return profit;
	}
}

int maxProfit3(int* prices, int pricesSize) {
	int buy = 0;
	int minBuy = 1;
	int largestProfit[2] = { 0 };

	for (int day = 1; day < pricesSize; day++) {

		int p1 = largestProfit[0];
		int p2 = largestProfit[1];
		int p3 = (minBuy < day ? prices[day] - prices[minBuy] : 0);
		int p4 = prices[day] - prices[buy];

		if (p4 >= p2 + p3) {
			largestProfit[1] = p4;
			minBuy = day + 1;
			continue;
		}

		if (p1 < p2 || p1 < p3) {
			largestProfit[0] = largestProfit[1];
			largestProfit[1] = p3;
		}	
	}
}