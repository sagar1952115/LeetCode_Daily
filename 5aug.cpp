 Recursion --------->
 Will give TLE in long test cases.
 time complexity is pow(2,n)
 
 int solve(vector<int>& nums, int target)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solve(nums,target-nums[i]);
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
       return solve(nums,target);
    }
    
    Memoisation--------------->
    
     int solve(vector<int>& nums, int target,vector<int> &dp)
    {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[target]!=-1)
            return dp[target];
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solve(nums,target-nums[i],dp);
        }
        dp[target]=ans;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
       vector<int> dp(target+1,-1);
       return solve(nums,target,dp);
    }
    
    Top-down approach/Tabular approach------------------>
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1,0);
        
        dp[0]=1;
        for(int  i=1;i<=target;i++)
        {
            for(auto it:nums)
            {
                if(i-it>=0)
                dp[i]+=dp[i-it];
            }
        }
        
       return dp[target];
    }
