class Solution {
public:
    vector<vector<int>> checkLCP(string word){
        int n = word.length();
        vector<vector<int>> lcp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            lcp[i][n-1] = (word[i]==word[n-1])?1:0;
        }
        for(int j=0;j<n;j++){
            lcp[n-1][j] = (word[j]==word[n-1])?1:0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(word[i]==word[j]){
                    lcp[i][j] = 1+ lcp[i+1][j+1];
                }
                else{
                    lcp[i][j]=0;
                }
            }
        }
        return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n,'$');
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[i][j]!=0){
                    word[i]=word[j];
                    break;
                }
            }
            if(word[i]=='$'){
                vector<bool> forbidden(26,false);
                for(int j=0;j<i;j++){
                    if(lcp[j][i]==0){
                        forbidden[word[j]-'a']=true;
                    }
                }
                for(int idx=0;idx<26;idx++){
                   if(forbidden[idx]==false){
                    word[i]=idx + 'a';
                    break;
                   }
                }
                if(word[i]=='$'){
                    return "";
                }
            }
        }
        return checkLCP(word)==lcp ? word : "";
    }
};
