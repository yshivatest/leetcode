#include<iostream>
#include<vector>
using namespace std;
int num_com = 0;
void combinations_helper(int k, int start, vector<int>& x, vector<vector<int>>& r, vector<int>& a)
{
    if (k == 1) {
        for(int i = start; i < x.size(); i++) {
            a.push_back(x[i]);
            r.push_back(a);
            a.pop_back();
            num_com++;
        }
    } else {
        for (int i = start; i <= x.size() - k; i++) {
            a.push_back(x[i]);
            combinations_helper(k-1, i+1, x, r, a);
            a.pop_back();
        }
    }
}

vector<vector<int>> combinations(vector<int>& x, int k) {
    vector<vector<int>> res;
    vector<int> a;
    combinations_helper(k, 0, x, res, a);
    return res;
}

int main()
{
    int size;
    cin>>size;
    int k;
    cin>>k;
    vector<int> x(size);
    for(int i = 0; i < size; i++)
        x[i] = i+1;
    auto y = combinations(x, k);
    cout<<"Num combinations = "<<num_com<<endl;
    for(auto i:y) {
        for(auto j:i)
            cout<<j<<",";
        cout<<endl;
    }
}
