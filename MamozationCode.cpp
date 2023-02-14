#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 123;
int knapsack(int a[], int wt[], int W, int n){
    int t[n + 1][W + 1];
    memset(t, -1, sizeof(t));
    if(W == 0 || n == 0){
        return 0;
    }if(t[n][W] != -1){
        return t[n][W];
    }if(wt[n - 1] <= W){
        return t[n][W] = max(a[n - 1] + knapsack(a, wt, W - wt[n - 1], n - 1), knapsack(a, wt, W, n - 1));
    }else{
        return t[n][W] = knapsack(a, wt, W, n - 1);
    }
}



int main()
{
    int a[mx], wt[mx],n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }for (int i = 0; i < n; i++){
        cin >> wt[i];
    }
    
    int W;
    cin >> W;
    cout <<"Ans:"<< knapsack(p, wt, W, n) << endl;
    return 0;
}