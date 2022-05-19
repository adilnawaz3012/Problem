/*
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 

and if the value is not present in the vector then it returns the end iterator.
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.

lower_bound -> >= [ equal or greater than ]
upper_bound -> > [ always greater than ]
if element is not present then both will give same value
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,2,4,5};
    cout << *upper_bound(nums.begin(), nums.end(), 3) << endl;
    cout << *lower_bound(nums.begin(), nums.end(), 3) << endl;
    vector<int> nums1 = {1,2,3,4,5};
    cout << *upper_bound(nums1.begin(), nums1.end(), 3) << endl;
    cout << *lower_bound(nums1.begin(), nums1.end(), 3) << endl;
    vector<int> nums2 = {0,1,2,3,4,5};
    cout << *upper_bound(nums2.begin(), nums2.end(), 10) << endl;
    cout << *lower_bound(nums2.begin(), nums2.end(), 10) << endl;
    return 0;
}