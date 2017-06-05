#include <bits/stdc++.h>
using namespace std;

int main() {

	int t,n;

	cin>>t;
	while(t--){

	    cin>>n;

	    int arr[1000],highest_r[1000],i,high,ans=0,highest=-1;

	    for(i=0;i<n;i++)
	        cin>>arr[i];

	   high=-1;

	    for(i=n-1;i>=0;i--){
	        high=max(arr[i],high);
	        highest_r[i]=high;
	    }

	    for(i=0;i<n;i++){

	        highest=max(arr[i],highest);
	        ans+=min(highest,highest_r[i])-arr[i];

	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
