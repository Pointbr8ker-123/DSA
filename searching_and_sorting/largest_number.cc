#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int>& nums) {
    vector<string> new_nums;
    new_nums.reserve(nums.size());

    for (int n : nums) new_nums.push_back(to_string(n));

    sort(new_nums.begin(), new_nums.end(), [](string a, string b) {
        return a + b > b + a;
    });

    if (new_nums[0] == "0") return "0";

    string ans = "";
    for (string& a : new_nums) ans += a;
    return ans;
}