#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Brute Force Approach
double findMaxAverageBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int maxSum = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += nums[j];
        }
        maxSum = max(maxSum, sum);
    }
    return (double)maxSum/k;
}

double findMaxAverageSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();

    int sum = 0;
    for (int i = 0; i < k; i++) sum += nums[i];

    int max_sum = sum;

    for (int i = k; i < n; i++) {
        sum -= nums[i-k];
        sum += nums[i];
        max_sum = max(max_sum, sum);
    }
    return (double) max_sum/k;
}

int main() {
    vector<int> arr = {1,12,-5,-6,50,3};
    int k = 4;

    double max_average = findMaxAverageSlidingWindow(arr, k);

    cout << max_average << endl;

    return 0;
}