#include <iostream>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){

	    cin>>n;
	    int arr[100];

	    int i,j;

	    for(i=0;i<n;i++)
	        cin>>arr[i];

	    int max_so_far=1;
	    int max_till_now=1;
	    int min_till_now=1;

	    for(i=0;i<n;i++){

	        if(arr[i]==0){
	            max_till_now=1;
	            min_till_now=1;
	        }
	        else if(arr[i]>0){
	            max_till_now=arr[i]*max_till_now;
	            min_till_now=arr[i]*min_till_now;
	        }
	        else{
	            int x=max_till_now;
	            max_till_now=max(arr[i]*min_till_now,1);
	            min_till_now=arr[i]*x;

	        }


	        max_so_far=max(max_so_far,max_till_now);


	    }
	    cout<<max_so_far<<"\n";
	}


	return 0;
}
