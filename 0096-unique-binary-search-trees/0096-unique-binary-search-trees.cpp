class Solution {
public:

    int solve(int n, vector<int>& memo)
    {
        if(n <= 1)
            return 1;

        if(memo[n] != -1)
            return memo[n];

        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            sum += solve(i, memo) * solve(n - 1 - i, memo);
        }

        memo[n] = sum;

        return memo[n];
    }

    int numTrees(int n)
    {
        vector<int> memo(n + 1, -1);

        return solve(n, memo);
    }
};