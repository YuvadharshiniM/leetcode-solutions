class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int v1 = 0, v2 = 0, vc1 = 0, vc2 = 0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            int ele = nums[i];
            if(v1==ele) vc1++;
            else if(v2==ele) vc2++;
            else if(vc1==0) {v1=ele; vc1=1;}
            else if(vc2==0) {v2=ele; vc2=1;}
            else {
                vc1--;
                vc2--;
            }
        }

        vc1=0;
        vc2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==v1) vc1++;
            else if(nums[i]==v2) vc2++;
        }
        List<Integer> res = new ArrayList<>();
        if(vc1 > n/3) res.add(v1);
        if(vc2 > n/3) res.add(v2);

        return res;
    }
}