#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){

    map<string,int> directory;

    directory["Naman"]=3456;
    directory["Chetan"]=1234;
    directory["Yash"]=9876;
    directory["Vivek"]=7689;
    directory["Priya"]=1234;
    directory["Riya"]=3425;
    directory["Akshat"]=8795;

    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Phone No - "<<element.second<<endl;
    }cout<<endl;

    //directory.insert(make_pair("Priya",6789)); //pairs can't be inserted
    directory["Priya"]=2398;
    for(auto element:directory){
        cout<<"Name - "<<element.first<<endl;
        cout<<"Phone No - "<<element.second<<endl;
    }cout<<endl;

}