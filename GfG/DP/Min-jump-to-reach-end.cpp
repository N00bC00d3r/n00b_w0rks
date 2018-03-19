// Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

//solution:

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    int ar[n],visited[n];
	    for(i=0;i<n;i++)
	    cin>>ar[i];
	    memset(visited,false,sizeof(visited));
	    queue<pair<int,int>> q;
	    if(ar[0]==0)
	    cout<<-1<<"\n";
	    else
	    {
	        int ans=-1;
	        q.push(make_pair(0,0));
	        visited[0]=true;
	        while(!q.empty())
	        {
	            pair<int,int> temp=q.front();
	            q.pop();
	            if(temp.first==n-1)
	            {
	                ans=temp.second;
	                break;
	            }
	            int d=temp.second;
	            int ind=temp.first;
	            for(int j=ind+1;j<=ind+ar[ind];j++)
	            {
	                if(!visited[j])
	                {
	                    q.push(make_pair(j,d+1));
	                }
	            }
	        }
	        cout<<ans<<"\n";
	        
	        
	    }
	}
	return 0;
}
