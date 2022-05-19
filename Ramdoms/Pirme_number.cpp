#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // input;
    int count = 0;
    for(int i=1;i<=n;i++) { // 1 2 3  4
        if (n % i == 0) {
            count = count + 1;
        }
    }
    if(count == 2) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}