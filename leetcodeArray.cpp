#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;




void display_vector(vector<int> &n) {
    for (int i = 0; i < n.size(); i++) {
        cout << n[i] << " ";
    }
    cout << endl;
}


void display_2d_vector(vector<vector<int>> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    //cout << endl;
}



void push_first(vector<int> & n, int data) {
    
    vector<int> :: iterator iter = n.begin();
    n.insert(iter, data);

}



vector<bool> kidsWithCandies(vector<int> & n, int extraCandies) {

    vector<bool> t_f;


    int max_candies = n[0];
    for (int i = 1; i < n.size(); i++) {
        if (n[i] > max_candies)
            max_candies = n[i];
    }

    // int *max_candies = max_element(n.begin(), n.end());

    for (int j = 0; j < n.size(); j++) {
        if (n[j]+extraCandies >= max_candies)
            t_f.push_back(true);
        else
            t_f.push_back(false);

    }

    return t_f;


}



int maximum_wealth(vector<vector<int>> & accounts) {

    vector<int> store_wealth;

    int rich_cus, len = accounts.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; accounts[i].size(); j++) {
            rich_cus += accounts[i][j];
        }
        store_wealth.push_back(rich_cus);
        rich_cus = 0;
    }

    int max = *max_element(store_wealth.begin(), store_wealth.end());
    return max;

}



vector<int> shuffle(vector<int>& nums, int n) {

    vector<int> final_arr;
    int len = nums.size();

    for (int i = 0; i < len/2; i++) {
        final_arr.push_back(nums[i]);
        final_arr.push_back(nums[n++]);
    }
    return final_arr;
}


vector<int> decompress_RLE_list(vector<int>& nums) {

    int f_pair, s_pair, len = nums.size();
    vector<int> final_arr;

    for (int i = 0; i < len; i+=2) {
        f_pair = nums[i];
        s_pair = nums[i+1];
        for (int j = 0; j < f_pair; j++) {
            final_arr.push_back(s_pair);
        }
    }

    return final_arr;
    // display_vector(final_arr);
    
}




void create_target_array(vector<int>& nums, vector<int>& index) {

    int len = nums.size();
    vector<int> f_arr;

    for (int i = 0; i < len; i++) {
        f_arr.insert(f_arr.begin()+index[i], nums[i]);
    }
    
    display_vector(f_arr);

}



int find_numbers(vector<int>& nums) {

    int data, temp;
    int cnt = 0, len = nums.size(), x = 0;
    vector<int> even;

    for (int i = 0; i < len; i++) {
        data = nums[i];
        temp = data;
        while (temp != 0) {
            temp = temp/10;
            cnt++;
        }

        // cout << cnt << " ";
        if (cnt%2 == 0)
            even.push_back(x++);
        cnt = 0;
    }

    return even.size();
    
    
}


//uncomplete
bool twod_sorting(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

void sort_martix_diagonal(vector<vector<int>>& nums) {

    sort(nums.begin(), nums.end());
    display_2d_vector(nums);

}



//uncomplete
void rotate_image(vector<vector<int>>& matrix) {

    int row = matrix.size(), indx = 0, k = 0;
    int clm = matrix[k].size();
    int row_inx = 0, clm_inx = 0;


    for (int i = row-1; i >= 0; i--) {
        matrix[i][indx] = matrix[row_inx][clm_inx++];
    }

}







//note
void diagonal_sum(vector<vector<int>>& mat) {

    int len = mat.size(), pd = 0, sd = 0, t = len-1;
    int middle_num = len/2, val = 0;

    if (len%2 != 0) {
        for (int i = 0; i < len; i++) {

            for (int j = 0; j < len; j++) {
                if (i == j)
                    pd += mat[i][j];
                
                if (i == middle_num)
                    val = mat[i][i];
                    
            }
        }

        for (int k = 0; k < len; k++) {
            sd += mat[k][t];
            t--;
        }
        
        cout << pd+sd-val;
    }

    else {
        for (int i = 0; i < len; i++) {

            for (int j = 0; j < len; j++) {
                if (i == j)
                    pd += mat[i][j];
                
                if (i == middle_num)
                    val = mat[i][i];
                    
            }
        }

        for (int k = 0; k < len; k++) {
            sd += mat[k][t];
            t--;
        }
        cout << pd+sd;
    }


 
}



vector<int> finalPrices(vector<int>& prices) {
        
    int len = prices.size();
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (prices[i] >= prices[j]) {
                prices[i] -= prices[j];
                break;
            }
        }
    }

    return prices;
}



// note
int sumOfUnique(vector<int>& nums) {

    map<int, int> u;
    map<int, int> :: iterator iter;
    
    for (int i = 0; i < nums.size(); i++) {
        u[nums[i]]++;
    }
    
    int sum = 0;
    for (iter = u.begin(); iter != u.end(); iter++) {
        if ((*iter).second == 1)
            sum += (*iter).first;
    }
    
    return sum;


}




//note 
void replaceElements(vector<int>& arr) {


    int n = arr.size();
    int maxi = arr[n - 1];
    arr[n - 1] = -1;
    
    for(int i = n - 2; i >= 0; i--) {

        int temp = arr[i];
        arr[i] = maxi;
        maxi = max(maxi, temp);
    }
    

  

    display_vector(arr);


}



//note
int arrayPairSum(vector<int>& nums) {

    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;





}



//note
int cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void kWeakestRows(vector<vector<int>>& mat, int k) {


    map<int, int> dont_know;
    int len = mat.size(), solders = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 1) {
                solders++;
                if (solders == mat[i].size()) {
                    dont_know[i] = solders;
                    solders = 0;
                    break;
                }
            }
            else {
                dont_know[i] = solders;
                solders = 0;
                break;
            }
        }
    }

    vector<int> return_kth_weakest_row;
    vector<pair<int, int>> vec(dont_know.begin(), dont_know.end());

    sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < k; i++) {
        return_kth_weakest_row.push_back(vec[i].first);
    }

    display_vector(return_kth_weakest_row);

   

}

//uncomplete
void find_common_char(vector<string>& A) {

    string s = A[0];
    vector<string> res;
    int j=0, k;
    char search;
    while(j != s.length()) {
        search = s[j];
        k = 0;
            for(int i=1; i<A.size(); i++) {
                if(A[i].find(search) != -1) {
                    A[i].erase(A[i].find(search),1);
                    k++;
                }         
            }
        if(k == A.size()-1)
            res.push_back(string(1, search));
        j++;
    }


}


// note
int countStudents(vector<int>& students, vector<int>& sandwich) {

    int len = students.size();
    int j = 0;
    for (int i = 0; i < len+len; i++) {

        if (students[j] != sandwich[j]) {
            int front_student = students[0];
            students.erase(students.begin());
            students.push_back(front_student);
        }

        if (students[j] == sandwich[j]) {
            students.erase(students.begin());
            sandwich.erase(sandwich.begin());
        }

    }
    // int unable_to_eat = sandwich.size();
    return sandwich.size();
    
}



//note
static int compare(pair<int, int>& a, pair<int, int>& b) {
    return (a.second == b.second) ? a.first > b.first : a.second < b.second;
}

void frequency_sort(vector<int>& nums) {

    map<int, int> mp;
    map<int, int> :: iterator iter;

    int len = nums.size();
    
    for (int i = 0; i < len; i++) {
        mp[nums[i]]++;    
    }


    vector<pair<int, int>> freq;
    vector<int> res;
    for (auto x : mp)
        freq.push_back(x);

    sort(freq.begin(), freq.end(), compare);
    
    for (auto x : freq) {
        for (int i = 0; i < x.second; i++) {
            res.push_back(x.first);
        }
    }

   

}







//note

static int manhattan_distance(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}


int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

    int len = points.size(), e;
    map<int, int> distance_index;
    map<int, int> :: iterator iter;
    vector<int> m;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 1; j++) {
            if (points[i][j]==x || points[i][j+1]==y) {
                int f = abs(x - points[i][j]);
                int s = abs(y - points[i][j+1]);
                int t = f+s;
                distance_index[i] = t;
            }
            if (points[i][j]==x && points[i][j]==y) {
                return i;
                break;
            }
        }
    }

    vector<int> f;
    vector<pair<int, int>> md(distance_index.begin(), distance_index.end());
    sort(md.begin(), md.end(), manhattan_distance);

    for (int i = 0; i < md.size(); i++)
        f.push_back(md[i].first);


    // for (auto x : f)
    //     cout << x << " "; 

    for (iter = distance_index.begin(); iter != distance_index.end(); iter++) {
        cout << (*iter).first << " " << (*iter).second << " " << endl;
    }

    // if (f.empty())
    //     return -1;
        
    return f[0];

}



//note
double trimMean(vector<int>& arr) {

    int x = arr.size()/20;
    double sum = 0;

    for (int i = x; i < arr.size()-x; i++)
        sum += arr[i];

    return (double(sum)/(arr.size()-2*x));



}



double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    int len = nums1.size()+nums2.size();

    vector<int> merged(len);
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());

    double median = 0;
    if (len%2 != 0)
        median = merged[len/2];
    
    else {
        median = (merged[len/2] + merged[(len/2)-1])/2.00;
    }

    return median;


}



//uncomple '' note
void shiftGrid(vector<vector<int>>& grid, int k) {

    int len = grid.size(), last_digit = 0;
    int f[len][len];
    int clen = grid[0].size();





    last_digit = grid[len-1][len-1];
    for (int row = 0; row < len; row++) {

        for (int clm = 1; clm <= len; clm++) {
            if (clm == len) {
                int temp = grid[row][clm-1];
                f[row+1][0] = temp;
            }
            else 
                f[row][clm] = grid[row][clm-1];       
        }
    f[0][0] = last_digit;
    }






    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

}




void z_pattern_vector_printing(vector<vector<int>>& nums) {



}



int main() {


    vector<vector<int>> nums = {{10,20,30,40},{50,60,70,80},{90,11,22,33}, {43,53,63,73}};

    int k = 1;

    sort_martix_diagonal(nums);
    

}