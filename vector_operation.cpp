#include <iostream>
#include <vector>
using namespace std;


//its a shortcut method for printing like this from vector or array => 1 2 3 4
#define debug(x) cout << #x << " " << x << endl;



void display_vector(vector<int> &n) {
    for (int i = 0; i < n.size(); i++) {
        cout << n[i] << " ";
        // debug(i);
    }
    cout << endl;
}



void push_specific_index(vector<int> & n, int index, int data) {

    vector<int> :: iterator iter = n.begin();
    n.insert(iter+index, data);

}

void push_first(vector<int> & n, int data) {
    
    vector<int> :: iterator iter = n.begin();
    n.insert(iter, data);

}

void push_last(vector<int> & n, int data) {

    vector<int> :: iterator iter = n.end();
    n.insert(iter, data);

} 




int main() {

    vector<int> n;
    

    push_first(n, 1);
    push_first(n, 2);
    push_first(n, 3);
    push_first(n, 4);
    push_last(n, 1);
    // push_specific_index(n, 1, 100);
    display_vector(n);

    
        
}






