#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){

    multimap<string,int> directory;

    directory.insert(make_pair("Naman",3456));
    directory.insert(make_pair("Chetan",1234));
    directory.insert(make_pair("Yash",9876));
    directory.insert(make_pair("Vivek",7689));
    directory.insert(make_pair("Priya",1234));
    directory.insert(make_pair("Riya",3425));
    directory.insert(make_pair("Akshat",8795));
    directory.insert(make_pair("Priya",2398));

    //directory["shivam"]=777; //not allowed sq indexing
    for(auto pair:directory){
        cout<<"Name - "<<pair.first<<endl;
        cout<<"Phone No - "<<pair.second<<endl;
    }cout<<endl;
    cout<<"No of times appear:"<<directory.count("Priya")<<endl;

}