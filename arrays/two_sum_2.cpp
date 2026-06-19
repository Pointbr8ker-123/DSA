#include <iostream>
#include <vector>
using namespace std;

// Works only for sorted arrays
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size()-1;
    vector<int> two_sum(2);
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left+1, right+1};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> numbers = {2,7,11,15}; 
    int target = 9;

    vector<int> two_sum = twoSum(numbers, target);

    cout << "{ ";
    for (int i: two_sum) cout << i << " ";
    cout << "}" << endl;

    return 0;
}