/*
	Write a function to find the longest common prefix string amongst an array of strings.
	If there is no common prefix, return an empty string "".
*/

/*	O(N * logN)
	class Solution {
		public:
		string longestCommonPrefix(vector<string>& v) {
			string ans = "";
			sort(v.begin(), v.end());
			int n = v.size();
			string first = v[0];
			string last = v[n-1];
			for(int i = 0; i < min(first.size(), last.size()); i++){
				if(first[i] != last[i]){
					return ans;
				}
				ans += first[i];
			}
			return ans;
		}
};
*/

// O(N * M) - sometimes better than O (N * log(N))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pfx = "";
        int min_len = strs[0].size();
        for(auto s : strs)
            min_len = min(min_len, (int)s.size());
        char sym;
        for(int i = 0; i < min_len; i++){
            sym = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != sym){
                    return pfx;
                }
            }
            pfx += sym;
        }
        return pfx;
    }
};