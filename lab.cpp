// optimal binary rooted tree using optimal binary search tree algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void optimalBST(vector<int>& keys, vector<int>& freq, vector<vector<int>>& cost, vector<vector<int>>& root);
void printOptimalBST(vector<vector<int>>& root, int i, int j, int r);
int main() 
{
    vector<int> keys = {1, 2, 3, 4, 5};
    vector<int> freq = {1, 2, 3, 4, 5};
    vector<vector<int>> cost(keys.size() + 1, vector<int>(keys.size() + 1));
    vector<vector<int>> root(keys.size() + 1, vector<int>(keys.size() + 1));
    optimalBST(keys, freq, cost, root);
    printOptimalBST(root, 1, keys.size(), 0);
    return 0;
}
void optimalBST(vector<int>& keys, vector<int>& freq, vector<vector<int>>& cost, vector<vector<int>>& root) 
{
    int n = keys.size();
    for (int i = 1; i <= n + 1; i++) 
    {
        cost[i][i - 1] = 0;
        cost[i][i] = freq[i - 1];
        root[i][i] = i;
    }
    cost[n + 1][n] = 0;
    for (int d = 1; d <= n - 1; d++) 
    {
        for (int i = 1; i <= n - d; i++) 
        {
            int j = i + d;
            int min = INT_MAX;
            int minIndex = -1;
            for (int k = i; k <= j; k++) 
            {
                if (cost[i][k - 1] + cost[k + 1][j] < min) 
                {
                    min = cost[i][k - 1] + cost[k + 1][j];
                    minIndex = k;
                }
            }
            cost[i][j] = min + freq[j - 1];
            root[i][j] = minIndex;
        }
    }
}
void printOptimalBST(vector<vector<int>>& root, int i, int j, int r) 
{
    int k = root[i][j];
    if (k == 0) 
    {
        return;
    }
    if (k == r) 
    {
        cout << "k" << k << " is the root" << endl;
    } else if (k < r) 
    {
        cout << "k" << k << " is the left child of k" << r << endl;
    } else 
    {
        cout << "k" << k << " is the right child of k" << r << endl;
    }
    printOptimalBST(root, i, k - 1, k);
    printOptimalBST(root, k + 1, j, k);
}
