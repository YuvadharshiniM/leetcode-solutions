class Solution {
    public int[] twoSum(int n[], int tar) {
        for (int i = 0; i < n.length; i++) {
            for (int j = i + 1; j < n.length; j++) {
                if (n[i] + n[j] == tar) {
                    return new int[] { i, j };//
                }
            }
        }
        return new int[] {};
    }
}