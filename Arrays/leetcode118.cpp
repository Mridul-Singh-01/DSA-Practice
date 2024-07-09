// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

#include <bits/stdc++.h>
using namespace std;

int ncr(int row, int col)
{
    int res = 1;
    for (int i = 0; i < col; i++)
    {
        res *= (row - i);
        res /= i + 1;
    }
    return res;
}

vector<int> genrateRow(int row)
{
    int ans = 1;
    vector<int> res;
    res.push_back(1);
    for (int i = 1; i < row; i++)
    {
        ans *= (row - i);
        ans /= i;
        res.push_back(ans);
    }
    return res;
}

vector<vector<int>> genrateTree(int row)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= row; i++)
    {
        ans.push_back(genrateRow(i));
    }
    return ans;
}

int main()
{
    int row = 5;
    int col = 3;
    cout << "The element at row " << row << " and columm " << col << " is : ";
    cout << ncr(row - 1, col - 1) << endl;
    vector<int> res = genrateRow(row);
    cout << "The " << row << "th row of Pascal triangle is : ";
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << "\nPascal Tree for " << row << " rows looks like : " << endl;
    vector<vector<int>> tree = genrateTree(row);
    for (auto &row : tree)
    {
        for (auto &column : row)
        {
            cout << column << " ";
        }
        cout << endl;
    }
    return 0;
}