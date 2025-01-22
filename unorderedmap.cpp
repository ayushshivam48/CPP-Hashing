#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_map<int,string> record;
    //roll no ,name

    record.insert(make_pair(3,"ria"));
    record[1]="bali";
    record[2]="anni";
    record[4]="tony";

    for(auto pair:record){
        cout<<"Roll No:"<<pair.first<<endl;
        cout<<"Name:"<<pair.second<<endl;
    }cout<<endl;

    //record.insert(make_pair(3,"ansh"));  //this pair doesn't work
    record[3]="ansh";  //that's why we apply this to make changes
    for(auto pair:record){
        cout<<"Roll No:"<<pair.first<<endl;
        cout<<"Name:"<<pair.second<<endl;
    }
}