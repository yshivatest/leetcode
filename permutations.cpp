#include<iostream>
#include<vector>
using namespace std;
int num_perm = 0;
void permutations_helper(int idx, vector<int> x, vector<vector<int>>& r)
{
    if (idx == x.size()-1) {
        r.push_back(x);
        num_perm++;
    } else {
        for (int i = idx; i < x.size(); i++) {
            swap(x[i], x[idx]);
            permutations_helper(idx+1, x, r);
            swap(x[idx], x[i]);
        }
    }
}

vector<vector<int>> permutations(vector<int> x)
{
    vector<vector<int>> result;
    permutations_helper(0, x, result);
    return result;
}

int main()
{
    int size;
    cin>>size;
    vector<int> x(size);
    for(int i = 0; i < size; i++) {
        x[i] = i+1;
    }
    auto y = permutations(x);
    cout<<"Num permutations = "<<num_perm<<endl;
    for(auto i : y) {
        for(auto j : i)
            cout<<j<<",";
        cout<<endl;
    }
}
