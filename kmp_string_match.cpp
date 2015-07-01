#include<iostream>
#include<string>
#include<vector>
using namespace std;

void compute_prefix(vector<int>& pi_, string P)
{
    pi_[0] = 0;
    int k = 0;
    for(int q = 1; q < P.size(); q++) {
        while(k > 0 && P[q] != P[k])
            k = pi_[k];
        if (P[q] == P[k])
            k++;
        pi_[q] = k;
    }
}

void kmp_match(string T, string P)
{
    vector<int> pi_(P.size());
    compute_prefix(pi_, P);
    for(int i = 0; i < pi_.size(); i++)
        cout<<pi_[i]<<" ";
    cout<<endl;
    int q = 0, k = 0;
    for(k = 0; k < T.size(); k++) {
        while(q > 0 && P[q] != T[k]) {
            q = pi_[q-1];
        }
        if (P[q] == T[k])
            q++;
        if (q == P.size())
            cout<<"Found match with k = "<<k<<endl;
    }
}

int main()
{
    kmp_match("sivivia", "ivia");
    return 0;
}
