

class Solution
{
    public:
    
    static bool comparator(struct Item & a, struct Item & b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comparator);
        double profit = 0;
        double currWeight = 0;
        for(int i=0;i<n;i++) {
            if(currWeight + arr[i].weight <= W) {
                currWeight += arr[i].weight;
                profit += arr[i].value;
            } else {
                double rem = (double) arr[i].value / (double)arr[i].weight;
                profit += rem * (W - currWeight);
                break;
            }
        }
        return profit;
    }
        
};