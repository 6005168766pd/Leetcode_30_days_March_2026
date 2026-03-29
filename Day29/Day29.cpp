class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Approach 1: tricky approach with O(1)
        // bool condition1 = (s1[0]==s2[0] && s1[2]==s2[2]) || (s1[0]==s2[2] && s1[2]==s2[0]);
        // bool condition2 = (s1[1]==s2[3] && s1[3]==s2[1]) || (s1[1]==s2[1] && s1[3]==s2[3]);
        // if(condition1 && condition2)  return true;
        // return false;
        // Approach 2: Using even and odd string checks
        // string evens1 = "";
        // string odds1= "";
        // string odds2 = "";
        // string evens2 =  "";
        // evens1 += s1[0];
        // evens1 += s1[2];
        // evens2 += s2[0];
        // evens2 += s2[2];
        // odds1  += s1[1];
        // odds1 += s1[3];
        // odds2  += s2[1];
        // odds2 += s2[3];
        // sort(evens1.begin(),evens1.end());
        // sort(evens2.begin(),evens2.end());
        // sort(odds1.begin(),odds1.end());
        // sort(odds2.begin(),odds2.end());
        // if((evens1 == evens2) && (odds1 == odds2)){
        //     return true;
        // }
        // return false;
        // Approach 3 : using Even and Odd Map
        vector<int> even(26,0);
        vector<int> odd(26,0);
        for(int i=0;i<4;i++){
            if(i%2==0){
              even[s1[i]-'a']++;
              even[s2[i]-'a']--;
            }
            else{
            odd[s1[i]-'a']++; 
            odd[s2[i]-'a']--;
            }
            
        }
        for(int i=0;i<26;i++){
            if(even[i]!=0){
                return false;
            }
            if(odd[i]!=0){
                return false;
            }
        }
        return true;
    }
};
