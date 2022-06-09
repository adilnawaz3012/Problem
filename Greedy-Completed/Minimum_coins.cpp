class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> ans;
        vector<int> coins = {1,2,5,10,20,50,100,200,500,2000};
        int n = coins.size();
        int idx = n - 1;
        while(N) {
            if(N - coins[idx] >= 0) {
                ans.push_back(coins[idx]);
                N -= coins[idx];
            } else {
                idx--;
            }
        }
        return ans;
    }
};  