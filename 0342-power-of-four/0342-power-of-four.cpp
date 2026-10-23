class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1) return false;
        if(n==1) return true;
        if((n & (n-1))==0 && (n-1)%3==0) return true;
        else return false;
    }
};