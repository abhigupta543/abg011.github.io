#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i=0; i<N; i++) cin >> A[i];
        int index = 0;
        for(int i=31; i>-1; i--){
            int maxEle = INT_MIN, maxInd = -1;
            for(int j=index; j<N; j++){
                int val = (A[j]>>i)&1;
                //cout << A[j] << "val - " << val << endl;
                if(val && (A[j] > maxEle)){
                    maxEle = A[j];
                    maxInd = j;
                }
            }
            //cout << maxEle << " " << maxInd << endl;
            if(maxInd == -1) continue;
            //for(int k=0; k<N; k++) cout << A[k];
            //cout << endl;
            for(int j=0; j<N; j++){
                int val = (A[j]>>i)&1;
                //cout << A[j] << "val - " << val << endl;
                if(val && j!=maxInd){
                    A[j] = A[j]^maxEle;
                }
            }

            int temp = A[maxInd];
            A[maxInd] = A[index];
            A[index] = temp;
            index++;
            //for(int k=0; k<N; k++) cout << A[k];
            //cout << endl;
        } 
        int result = 0;
        for(int i=0; i<index; i++){
            result ^= A[i];
        }
        cout << result << endl;
    }
    return 0;
}