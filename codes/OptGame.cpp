#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i=0; i<N; i++) cin >> arr[i];
        int dp[N][N];
        int gap = 0;
        for(gap = 0; gap<N; gap++){
            for(int i=0, j=gap; j<N; i++, j++){
                int x = ((i+2) <= j) ? dp[i+2][j] : 0;
                int y = ((i+1) <= (j-1)) ? dp[i+1][j-1] : 0;
                int z = (i <= (j-2)) ? dp[i][j-2] : 0;

                dp[i][j] = max(arr[i] + min(x,y), arr[j] + min(y, z));
            }
        } 
        cout << dp[0][N-1] << endl;
    }
    return 0;
}