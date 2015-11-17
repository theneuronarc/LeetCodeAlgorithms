// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#define max(a,b) (a>b?a:b)

class longestStringWithoutRepeating {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 1, end = 0;
		int size = 0, maxSize = 0;
		int stringSize = s.size();
		int Map[128] = { 0 };

		if (stringSize <= 1)
			return stringSize;

		for (unsigned int i = 0; i < s.size(); i++) {
			if (Map[s[i]] >= start) {
				maxSize = max(maxSize, (end - start + 1));
				start = Map[s[i]];
			}
			end = i + 1;
			Map[s[i]] = end + 1;
		}
		maxSize = max(maxSize, (end - start + 1));
		return maxSize;
	}
};