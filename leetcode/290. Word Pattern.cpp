class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        int cnt = 0;
        for(int i = 0; i < str.size(); i++) {
            int j = i;
            if(cnt == pattern.size()) return false;
            string word;
            while(j < str.size() && str[j] != ' ') {
                word += str[j];
                j++;
            }
            if(m.find(pattern[cnt])==m.end()) {
                m[pattern[cnt]] = word;
            }else if(m[pattern[cnt]] != word) {
                return false;
            }
            i = j;
            cnt++;
        }
        if(cnt < pattern.size() ) return false;
        for(int i = 0; i < pattern.size(); i++) {
            for(int j = i+1; j < pattern.size(); j++) {
                if(m[pattern[i]] == m[pattern[j]] && pattern[i] != pattern[j]) return false;
            }
        }
        return true;
    }
};
