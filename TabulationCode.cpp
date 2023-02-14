#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 123;
int knapSack(int x, int wt[], int val[], int n)
{
    int i, j;
    vector<vector<int>> K(n + 1, vector<int>(x + 1));

    for(i=0;i<=n;i++){
        for(j =0;j<=x;j++){
            if(i==0 || j==0){
                K[i][j] = 0;
            }else if(wt[i - 1]<=j){
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]],K[i - 1][j]);
            }else{
                K[i][j] = K[i - 1][j];
            }
        }
    }
    return K[n][x];
}


int main()
{
    int val[mx], wt[mx], n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val[i];
    }for(int i=0;i<n;i++){
        cin >> wt[i];
    }

    int x;
    cin >> x;
    cout << "Ans:" << knapSack(x, wt, val, n);
    return 0;
}
