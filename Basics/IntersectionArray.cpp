#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
    unordered_set<int> s(arr1.begin(), arr1.end());
    vector<int> result;
    for (int num : arr2) {
        if (s.find(num) != s.end()) {
            result.push_back(num);
            s.erase(num);  
        }
    }
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 36, 54, 7};
    vector<int> arr2 = {2, 36, 7, 21, 1, 12, 3, 1};
    vector<int> result = intersection(arr1, arr2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
