class Solution {
public:
    int minOperations(string s) {
        int start0 = 0; 
        int start1 = 0; 
        
        for(int i = 0; i < s.size(); i++){
            char expected0 = (i % 2 == 0) ? '0' : '1';
            char expected1 = (i % 2 == 0) ? '1' : '0';
            
            if(s[i] != expected0) start0++;
            if(s[i] != expected1) start1++;
        }
        
        return min(start0, start1);
    }
};
