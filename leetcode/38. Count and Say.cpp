class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for(int i = 1; i < n; i++) {
            string tmp = "";
            for(int j = 0; j < ret.size(); j++) {
                int k = j;
                while(k < ret.size() && ret[j]==ret[k]) k++;
                tmp += (k-j)+'0';
                tmp += ret[j];
                j = k-1;
            }
            ret = tmp;
        }
        return ret;
    }

};
