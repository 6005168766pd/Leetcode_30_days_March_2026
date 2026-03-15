class Solution {
    #define ll long long
    bool check(long long mid,int mH, vector<int>& workerTimes) {
        ll h=0;
        for(auto &t:workerTimes) {
            h+=(ll)(sqrt(2.0*mid/t +0.25)-0.5);
            if(h>=mH) {
                return true;
            }
        }
        return h>=mH;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxtime=*max_element(begin(workerTimes),end(workerTimes));
        ll l=1;
        ll r=(ll)maxtime*mountainHeight*(mountainHeight+1)/2;
        ll result=0;
        while(l<=r) {
            ll mid=l+(r-l)/2;
            if(check(mid,mountainHeight,workerTimes)) {
                result=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return result;
    }
};
