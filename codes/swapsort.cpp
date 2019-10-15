#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

}

int minSwaps(int A[], int N){
    vector<int> B;
    for(int i=0; i<N; i++) B.push_back(A[i]);
    sort(B.begin(), B.end());
    vector<vector<int>> adjList(N);
    unordered_map<int, int> umap;
    for(int i=0; i<N; i++) umap.insert(pair<int, int>(B[i], i));
    for(int i=0; i<N; i++){
        int x = umap.find(A[i])->second;
        adjList[i].push_back(x);
    }
    int count = 0;
    bool visited[N] = {0};
    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i] = 1;
            bool cycle = 0;
            int edges = 0;
            int temp = i;
            while(!cycle){
                temp = adjList[temp][0];
                edges++;
                visited[temp] = 1;
                if(temp == i) cycle = 1;
            }
            count+=edges-1;
        }
    }
    return count;
}
