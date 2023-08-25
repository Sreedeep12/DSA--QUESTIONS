class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        vector<int> output;
        int index = 0, sum = 0;
        solve(candidates, output, index, ans, target, sum);
        vector<vector<int>> ans2(ans.begin(), ans.end());
        return ans2;
    }

    void solve(vector<int>& nums, vector<int>& output, int index, set<vector<int>>& ans, int target, int sum) {
        if (sum == target) {
            ans.insert(output);
            return;
        }
        if (sum > target || index >= nums.size()) {
            return; // Prune the search if sum exceeds target or index is out of bounds
        }

        // Exclude current element
        solve(nums, output, index + 1, ans, target, sum);

        // Include current element
        output.push_back(nums[index]);
        solve(nums, output, index, ans, target, sum + nums[index]);
        output.pop_back();
    }
};
