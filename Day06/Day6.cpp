// Approach 1:
class Solution {
public:
    bool checkOnesSegment(string s) {
        int segments = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
                segments++;
                if(segments > 1)
                    return false;
            }
        }

        return true;
    }
};
// Approach 2
class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '1' && s[i-1] == '0')
                return false;
        }
        return true;
    }
};
