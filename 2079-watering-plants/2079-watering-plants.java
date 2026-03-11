class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int cap = capacity;
        int steps = 0;
        for(int i = 0;i < plants.length;i++){
            if(capacity < plants[i]){
                steps += 2 * i;
                capacity = cap;
            }
                capacity-=plants[i];
                steps++;
        }
        return steps;
    }
}