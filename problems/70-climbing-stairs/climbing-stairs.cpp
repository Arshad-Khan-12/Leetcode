class Solution {
public:
    int climbStairs(int n) {
        // If there is only 1 step, there's exactly 1 way to climb it.
        if (n == 1) return 1;
        
        // Initialize the number of ways to reach step 0 and step 1.
        int waysAtStepMinusTwo = 1; // Ways to reach step 0.
        int waysAtStepMinusOne = 1; // Ways to reach step 1.
        
        // Variable to hold the number of ways to reach the current step.
        int waysAtCurrentStep = 0;
        
        // Iterate from step 2 to step n.
        for (int step = 2; step <= n; step++) {
            // The number of ways to reach the current step is the sum of ways to reach
            // the two previous steps.
            waysAtCurrentStep = waysAtStepMinusTwo + waysAtStepMinusOne;
            
            // Update the values for the next iteration.
            waysAtStepMinusTwo = waysAtStepMinusOne;
            waysAtStepMinusOne = waysAtCurrentStep;
        }
        
        // Return the total number of ways to reach step n.
        return waysAtCurrentStep;
    }
};
