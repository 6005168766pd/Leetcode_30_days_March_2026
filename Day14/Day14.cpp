class Solution {
public:
    void solve(int n, string &curr, int &count, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
      
            curr.push_back(ch);

        
            solve(n, curr, count, k, result);

    
            if (!result.empty()) return;

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        
        solve(n, curr, count, k, result);

        return result;
    }
};
