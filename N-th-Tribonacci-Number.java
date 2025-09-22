class Solution {
    public int tribonacci(int n) {
        if(n==0||n==1) return n;
        if(n==2) return 1;
        int a,b,c,ans ;
        a=0;b=1;c=1;ans=0;
        for(int i=3;i<=n;i++){
            ans = a+b+c;
            a=b;
            b=c;
            c=ans;
        }
        return ans;
    }
}