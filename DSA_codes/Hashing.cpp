#include <iostream>
#include <vector>

using namespace std;

int main() {
    int data_points[]={57,13,82,29,4,91,36,68,11,47,7,31,52};
    const int table_size=17;

    vector<int> storage[table_size];

    for(int j=0;j<sizeof(data_points)/sizeof(data_points[0]);++j) 
    {
        int hash_value=data_points[j]%table_size;
        storage[hash_value].push_back(data_points[j]);
    }

    cout<<"My Hash Map:"<<endl;
    for(int k=0;k<table_size;++k) {
        cout<<"Position "<<k<<": ";
        if(storage[k].empty()) 
        {
            cout<<"-";
        } else {
            for(int element:storage[k]) {
                cout<<element<<", ";
            }
        }
        cout<<endl;
    }

    return 0;
}
