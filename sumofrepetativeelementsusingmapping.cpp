#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){

    int n;
    cin>>n;

    vector<int> input(n);

    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    map<int,int> m;
    for(int i=0;i<n;i++){
        m[input[i]]++;  //storing freq of every element in input array
    }

    int sum=0;
    //finding sum of repetative elements
    //pair->element,freq
    for(auto pair:m){
        if(pair.second>1){  //element is repetative
            sum+=pair.first;
        }
    }
    
    cout<<"Ans:"<<sum<<endl;
}