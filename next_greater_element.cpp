#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){

  int i,n,a[1000];

  cin >> n;

  stack<int> s;

  for(i=0;i<n;i++)
    cin>>a[i];

  for(i=0;i<n;i++){

    while(!s.empty() and a[i]>s.top()){

      printf("greater=%d element=%d\n",a[i],s.top());
      s.pop();
    }
    s.push(a[i]);

  }
  while(!s.empty()){

    printf("greater=-1 element=%d\n",s.top());
    s.pop();

  }


  return 0;


}
