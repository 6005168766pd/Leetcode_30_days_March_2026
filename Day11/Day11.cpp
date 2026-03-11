class Solution {
public:
    int result=0;
    int counter=0;
    int bitwiseComplement(int n) {
        // Approach 1
        // if(n==0) return 1;
        // while(n){
        //     int r=n%2;
        //     result += pow(2,counter++)*(!r);
        //     n/=2;
        // }
        // return result;
        // Approach 2
        if(n==0)  return 1;
        int bits = floor(log2(n))+1;    // finding no. of bits
        int mask = (1<<bits)-1;       // mask=111... size of mask equal to that of n.
        return mask^n;
    }
};
