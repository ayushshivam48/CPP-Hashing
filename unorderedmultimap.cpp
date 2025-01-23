#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    unordered_multimap<string, int> fruitcount;
    //roll no ,name

    fruitcount.insert(make_pair("Apple",6));
    fruitcount.insert(make_pair("Banana",3));
    fruitcount.insert(make_pair("Orange",7));
    fruitcount.insert(make_pair("Apple",2));

    for(auto pair:fruitcount){
        cout<<"Fruit:"<<pair.first<<endl;
        cout<<"Count:"<<pair.second<<endl;
    }cout<<endl;
}