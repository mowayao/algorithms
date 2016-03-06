class Solution {
public:
    map<int,bool>vis;
    bool isHappy(int n) {
        if(n <= 0) return false;
        if(n==1) return true;
        if(vis[n]) return false;
        vis[n] = true;
        int ret = 0;
        while(n) {
            int tmp = n%10;
            ret += tmp*tmp;
            n /= 10;
        }
        return isHappy(ret);

    }

};
