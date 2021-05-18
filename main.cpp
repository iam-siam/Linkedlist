#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

#define log(x) cout << x << endl;

int decending_order(int m, int n) {
    return m > n;
}


int main() {


    list<int> vector_copy;
    list<int> :: iterator it;

    vector_copy.push_back(10);
    vector_copy.push_back(50);
    vector_copy.push_back(1880);
    vector_copy.push_front(666);
    vector_copy.


    int len = vector_copy.size();

    for (it = vector_copy.begin(); it != vector_copy.end(); it++) 
        cout << *it << " ";


    int arr[] = {{23423,234,234,2},{234,456,645,546,4,4},{232,54,5,6,6}};

}