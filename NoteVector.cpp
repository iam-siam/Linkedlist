#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define line(x) cout << x << " ";
// #define line(x) cout << x << " ";


void display_2d_vector(vector<vector<int>> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void display(vector<int>& nums) {

    for (int i = 0; i < nums.size(); i++) {
        line(nums[i]);
    }
}


// it will print vector, like a snake walking

//   @-----
//        |
//   ------       
//   |
//   ------
//        |
//   ------
void snake_pattern_vector_print(vector<vector<int>>& nums) {

    int len = nums.size();
    int temp_column, k = 0;
    vector<vector<int>> vec(len, vector<int>(nums[0].size()));

    for (int row = 0; row < len; row+=2) {
        for (int column = 0; column <= len; column++) {


            if (column < len)
                vec[row][column] = nums[row][column];


            if (column == len) {
                temp_column = column;
                temp_column -= 1;
                while (temp_column >= 0) {
                    vec[row+1][k++] = nums[row+1][temp_column];
                    temp_column--;
                }
                k = 0;
            }

        }
        

    }

    display_2d_vector(vec);


}



bool twod_sorting(vector<int>& v1, vector<int>& v2, int i, int j) {
    return v1[i] < v2[j];
}

void sort_martix_diagonal(vector<vector<int>>& nums) {


    for (int i = 0; i < nums.size(); i++) {
        sort(nums[i].rbegin(), nums[i].rend(), twod_sorting);
    }
}



int main() {

    vector<vector<int>> nums = {{40,20,10,30},{50,30,90,80},{90,1,24,33}, {43,53,63,73}};
    // {{10,20,30,40},
    //  {50,60,70,80},
    //  {90,11,22,33},
    //  {43,53,63,73}};
    sort_martix_diagonal(nums);

}