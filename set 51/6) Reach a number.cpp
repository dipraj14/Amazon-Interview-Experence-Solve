/*
Given an infinite integer number line, find the minimum steps required to 
reach a particular point. 0 is the starting point and at the ith step we can move 
+i or -i step from the current position.

*/
// https://leetcode.com/problems/reach-a-number/
// https://www.youtube.com/watch?v=kz_0GjhFOzc ---> part 1
// https://www.youtube.com/watch?v=XO6fIfo85gk&t=24s ---> part 2
class Solution {
public:
    int reachNumber(int target) {
      target = abs(target);
        int steps = 0;
        
        int sum = 0;
        
        while(sum < target){
            steps += 1;
            sum += steps;
        }
        while((sum - target) %2 !=0){
            steps += 1;
            sum += steps;
        }
        
        return steps;
        
    }
};