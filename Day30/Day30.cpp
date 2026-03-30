class Solution {
public:
    bool checkStrings(string s1, string s2) {
        //Approach 1: Using even and odd string
        string evens1 = "";
        string odds1= "";
        string odds2 = "";
        string evens2 =  "";
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                evens1 += s1[i];
                evens2 += s2[i];
            }
            else{
                odds1  += s1[i];
                odds2 += s2[i];
            }
        }
        sort(evens1.begin(),evens1.end());
        sort(evens2.begin(),evens2.end());
        sort(odds1.begin(),odds1.end());
        sort(odds2.begin(),odds2.end());
        if((evens1 == evens2) && (odds1 == odds2)){
            return true;
        }
        return false;
        // Approach 2: Using even and odd map
        // vector<int> even(26,0);
        // vector<int> odd(26,0);
        // for(int i=0;i<s1.size();i++){
        //     if(i%2==0){
        //       even[s1[i]-'a']++;
        //       even[s2[i]-'a']--;
        //     }
        //     else{
        //     odd[s1[i]-'a']++; 
        //     odd[s2[i]-'a']--;
        //     }
            
        // }
        // for(int i=0;i<26;i++){
        //     if(even[i]!=0){
        //         return false;
        //     }
        //     if(odd[i]!=0){
        //         return false;
        //     }
        // }
        // return true;
    }
};
