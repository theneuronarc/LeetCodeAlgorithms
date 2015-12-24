/*
https://leetcode.com/problems/word-ladder-ii/
*/

#include "std_headers.h"

class Solution2 {
	bool match(string &str1, string& str2) {
		int mismatches = 0;
		int size = str1.size();
		const char* cstr1 = str1.data();
		const char* cstr2 = str2.data();
		for (int i = 0; i < size && mismatches < 2; i++) {
			if (cstr1[i] == cstr2[i])
				continue;
			else
				mismatches++;
		}

		if (mismatches != 1)
			return false;
		else
			return true;
	}

	void createGraph(vector<string> &wordList, vector<vector<int>> &graph) {
		int n = wordList.size();
		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (match(wordList[i], wordList[j])) {
					graph[i].push_back(j);
					if (i != 0 && j != 1)
						graph[j].push_back(i);
				}
			}
		}
	}


	int bfs(int source, int end, vector<vector<int>> & graph) {
		int nodeCount = graph.size();
		bool* isVisited = (bool*)calloc(nodeCount, sizeof(bool));
		int* parent = (int*)calloc(nodeCount, sizeof(int));
		int currentNode;
		std::queue<int> fifo;
		fifo.push(source);
		parent[0] = -1;
		while (!fifo.empty()) {
			currentNode = fifo.front();
			fifo.pop();
			isVisited[currentNode] = true;
			int* adList = graph[currentNode].data();
			int listSize = graph[currentNode].size();

			for (int i = 0; i < listSize; i++) {
				if (isVisited[adList[i]])
					continue;
				isVisited[adList[i]] = true;
				parent[adList[i]] = currentNode;
				fifo.push(adList[i]);
			}

			if (isVisited[end])
				break;
		}
		if (isVisited[end]) {
			int count = 0;
			int currentParent = parent[end];
			while (currentParent != -1) {
				count++;
				currentParent = parent[currentParent];
			}
			return count;
		}
		else
			return 0;
	}

	

	int searchPaths(int source, int end, vector<vector<int>> & graph) {
		return bfs(source, end, graph);
	}

public:
	int ladderLength(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<string> vecWordList;		
		if (wordList.empty())
			return 0;

		int minLen;
		int start = 0, end = 1;

		vecWordList.push_back(beginWord);
		vecWordList.push_back(endWord);

		for (unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); it++) {
			vecWordList.push_back(*it);
		}

		vector<vector<int>> graph(vecWordList.size(), vector<int>());
		createGraph(vecWordList, graph);
		return searchPaths(start, end, graph);
	}
};

class Solution {
	bool match(string &str1, string& str2) {
		int mismatches = 0;
		for (int i = 0; i < str1.size() && mismatches < 2; i++) {
			if (str1[i] == str2[i])
				continue;
			else
				mismatches++;
		}

		if (mismatches != 1)
			return false;
		else
			return true;
	}

	void createGraph(vector<string> &wordList, vector<vector<int>> &graph) {
		int n = wordList.size();
		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (match(wordList[i], wordList[j])) {
					graph[i].push_back(j);
					if(i!=0 && j!=1)
						graph[j].push_back(i);
				}
			}
		}
	}


	int bfs(int source, int end, vector<vector<int>> & graph, vector<vector<int>> &res) {
		vector<int> isVisited(graph.size(), false);
		vector<int> parent(graph.size(), 0);
		int currentNode;
		std::queue<int> fifo;
		fifo.push(source);
		parent[0] = -1;
		while (!fifo.empty()) {
			currentNode = fifo.front();
			fifo.pop();
			isVisited[currentNode] = true;

			for (int i = 0; i < graph[currentNode].size(); i++) {
				if (isVisited[graph[currentNode][i]])
					continue;
				isVisited[graph[currentNode][i]] = true;
				parent[graph[currentNode][i]] = currentNode;
				fifo.push(graph[currentNode][i]);
			}

			if (isVisited[end])
				break;
		}
		if (isVisited[end]) {
			int currentParent = parent[end];
			vector<int> path;
			path.push_back(end);
			while (currentParent != -1) {
				path.push_back(currentParent);
				currentParent = parent[currentParent];
			}
			//res.push_back(path);
			return path.size();
		}
		else
			return 0;


	}

	void dfs(int source, int end, vector<int>& parent, vector<bool>& isVisited, int curLen, int& minLen,
				vector<vector<int>> & graph, vector<vector<int>> &res) {
		if (curLen > minLen)
			return;
		isVisited[source] = true;
		if (source == end) {
			int currentParent = parent[end];
			vector<int> path;
			path.push_back(end);
			while (currentParent != -1) {
				path.push_back(currentParent);
				currentParent = parent[currentParent];
			}
			minLen = min(minLen, path.size());
			printList(path);
			res.push_back(path);
			isVisited[source] = false;
			return;
		}

		for (int i = 0; i < graph[source].size(); i++) {
			printf("\n%d -> %d", source, graph[source][i]);
			if (isVisited[graph[source][i]])
				continue;
			parent[graph[source][i]] = source;
			
			dfs(graph[source][i], end, parent, isVisited, curLen + 1, minLen,graph, res);
		}

		isVisited[source] = false;
	}


	int searchPaths(int source, int end, vector<vector<int>> & graph, vector<vector<int>> &res) {
		vector<bool> isVisited(graph.size() + 1024, false);
		vector<int> parent(graph.size() + 1024, 0);
		int minLen = INT_MAX;
		//isVisited[source] = true;
		minLen = bfs(source, end, graph, res);
		//res.clear();
		//parent[source] = -1;
		//dfs(source, end, parent, isVisited, 1, minLen, graph, res);
		return minLen;
	}

public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		vector<string> vecWordList;
		vector<vector<int>> res;
		vector<vector<string>> wordLadder;
		if (wordList.empty())
			return wordLadder;

		int minLen;
		int start = 0, end = 1;
		
		vecWordList.push_back(beginWord);
		vecWordList.push_back(endWord);

		for (unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); it++) {
			vecWordList.push_back(*it);
		}

		vector<vector<int>> graph(vecWordList.size(), vector<int>());
		createGraph(vecWordList, graph);
		minLen = searchPaths(start, end, graph, res);

		for(int i = 0; i < res.size(); i++) {
			if (res[i].size() > minLen)
				continue;

			vector<string> path;

			for (int j = res[i].size()-1;j >= 0; j--) {
				path.push_back(vecWordList[res[i][j]]);
			}
			printList(path);
			wordLadder.push_back(path);

		}
		return wordLadder;
	}
};

class Solution1 {
public:
	int diffCount(const string &a, const string &b) {
		int ret = 0;
		for (int i = 0; i < (int)a.size(); i++) {
			ret += (a[i] != b[i]);
		}
		return ret;
	}
	void constructMap(vector<int>* g, string beginWord, string endWord,
		vector<string> &wordList) {
		int n = wordList.size();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (diffCount(wordList[i], wordList[j]) == 1) {
					g[i].push_back(j);
					if (i != 0 && j != n - 1)
						g[j].push_back(i);
				}
			}
		}
	}
	void bfs(vector<int>* g, vector<int>* ret, int n) {
		vector<bool> vi(n + 2, false);
		queue<int> qu;
		qu.push(0);
		vi[0] = true;

		while (!qu.empty()) {
			int len = qu.size();
			vector<int> viSet;
			while (len--) {
				int s = qu.front();
				qu.pop();
				for (int i = 0; i < (int)g[s].size(); i++) {
					int t = g[s][i];
					if (vi[t] == false) {
						if (ret[t].empty()) {
							qu.push(t);
							viSet.push_back(t);
						}
						ret[t].push_back(s);
					}

				}
			}
			for (int i = 0; i < (int)viSet.size(); i++) {
				vi[viSet[i]] = true;
			}
			if (vi[n - 1] == true)
				return;
		}
	}
	void dfs(vector<vector<string> > &ret, vector<int> *ans, int t,
		vector<string> &tmp, vector<string> &wordList) {
		if (t == 0) {
			tmp.push_back(wordList[0]);
			ret.push_back(tmp);
			tmp.pop_back();
			return;
		}
		tmp.push_back(wordList[t]);
		for (int i = 0; i < (int)ans[t].size(); i++) {
			dfs(ret, ans, ans[t][i], tmp, wordList);
		}
		tmp.pop_back();
	}
	vector<vector<string> > findLadders(string beginWord, string endWord,
		unordered_set<string> &wordList) {
		vector<vector<string> > ret;
		vector<string> vwordList;
		vwordList.push_back(beginWord);
		for (unordered_set<string>::iterator it = wordList.begin(); it != wordList.end();
		it++) {
			vwordList.push_back(*it);
		}
		vwordList.push_back(endWord);

		int n = vwordList.size();
		vector<int>* g = new vector<int>[n] , *ans = new vector<int>[n];
		constructMap(g, beginWord, endWord, vwordList);
		bfs(g, ans, n);
		vector<string> tmp;
		dfs(ret, ans, n - 1, tmp, vwordList);
		for (int i = 0; i < (int)ret.size(); i++) {
			reverse(ret[i].begin(), ret[i].end());
			printList(ret[i]);
		}
		return ret;
	}
};
/*
unordered_set<string> wordList({ "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr",
"gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die",
"war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali",
"pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui",
"ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana",
"gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh",
"sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax",
"jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye",
"oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for",
"joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara",
"dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire",
"irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy",
"nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop",
"but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew",
"web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub",
"ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam",
"new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip",
"cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set",
"qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro",
"few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum",
"rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox",
"ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram",
"let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam",
"zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao",
"aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who",
"bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur",
"ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax",
"mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin",
"mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi",
"yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob" });
*/
void findLaddersMain2() {
	Solution obj;
	
	unordered_set<string> wordList({ "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", 
		"gay", "sip", "kay", "per", "val", "mes", "ohs", "now", "boa", "pal", "bar", "die",
		"war", "hay", "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali",
		"pay", "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui", 
		"ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu", "ana",
		"gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal", "lie", "noh", 
		"sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie", "yet", "too", "tax", 
		"jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac", "nut", "why", "bye", "lye", 
		"oct", "old", "fin", "feb", "chi", "sap", "owl", "log", "tod", "dot", "bow", "fob", "for",
		"joe", "ivy", "fan", "age", "fax", "hip", "jib", "mel", "hus", "sob", "ifs", "tab", "ara",
		"dab", "jag", "jar", "arm", "lot", "tom", "sax", "tex", "yum", "pei", "wen", "wry", "ire",
		"irk", "far", "mew", "wit", "doe", "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy",
		"nag", "ron", "soy", "gin", "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop",
		"but", "orb", "fen", "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew",
		"web", "hod", "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub",
		"ere", "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam",
		"new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum", "pip",
		"cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad", "ats", "set",
		"qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao", "mom", "mas", "pro", 
		"few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may", "shy", "rid", "bat", "sum", 
		"rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava", "rap", "den", "fla", "auk", "cox", 
		"ibo", "hey", "saw", "vim", "sec", "ltd", "you", "its", "tat", "dew", "eva", "tog", "ram",
		"let", "see", "zit", "maw", "nix", "ate", "gig", "rep", "owe", "ind", "hog", "eve", "sam",
		"zoo", "any", "dow", "cod", "bed", "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao",
		"aug", "mum", "hoe", "bah", "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", 
		"bet", "gos", "son", "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", 
		"ada", "bin", "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax",
		"mid", "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin",
		"mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay", "poi",
		"yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee", "wig", "sly",
		"rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit", "hem", "joy", "bum",
		"rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw", "nub", "bit", "bur", "sid", 
		"sun", "oil", "red", "doc", "moe", "caw", "eel", "dix", "cub", "end", "gem", "off", "yew", 
		"hug", "pop", "tub", "sgt", "lid", "pun", "ton", "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did", "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov", "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode", "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot", "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "err", "him", "all", "pad", "hah", "hie", "aim", "ike", "jed", "ego", "mac", "baa", "min", "com", "ill", "was", "cab", "ago", "ina", "big", "ilk", "gal", "tap", "duh", "ola", "ran", "lab", "top", "gob", "hot", "ora", "tia", "kip", "han", "met", "hut", "she", "sac", "fed", "goo", "tee", "ell", "not", "act", "gil", "rut", "ala", "ape", "rig", "cid", "god", "duo", "lin", "aid", "gel", "awl", "lag", "elf", "liz", "ref", "aha", "fib", "oho", "tho", "her", "nor", "ace", "adz", "fun", "ned", "coo", "win", "tao", "coy", "van", "man", "pit", "guy", "foe", "hid", "mai", "sup", "jay", "hob", "mow", "jot", "are", "pol", "arc", "lax", "aft", "alb", "len", "air", "pug", "pox", "vow", "got", "meg", "zoe", "amp", "ale", "bud", "gee", "pin", "dun", "pat", "ten", "mob" });

	//unordered_set<string> wordList({"abc", "dbc", "cbc", "kbc"});
	obj.findLadders("cet", "ism", wordList);
}