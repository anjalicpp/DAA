//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int mod=1e9+7;
  
  int countofsubsetsum(int n,vector<int>arr,int sum)
  {
      int t[n+1][sum+1];
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<sum+1;j++)
          {
              if(i==0)
              {
                  t[i][j]=0;
              }
              if(j==0)
              {
                  t[i][j]=1;
              }
          }
      }
      
      for(int i=1;i<n+1;i++)
      {
          for(int j=0;j<sum+1;j++)
          {
              if(arr[i-1]<=j)
              {
                  t[i][j]=t[i-1][j]%mod+t[i-1][j-arr[i-1]]%mod;
              }
              else
              t[i][j]=t[i-1][j]%mod;
          }
      }
      return t[n][sum]%mod;
  }
  
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sumarr=0;
        //int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            sumarr+=arr[i]%mod;
        }
        if(sumarr-d<0||(d+sumarr)%2)return 0;
        
        int sum=((d+sumarr)/2)%mod;
        return countofsubsetsum(n,arr,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
