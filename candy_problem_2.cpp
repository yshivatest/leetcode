#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    enum dir {
        INC = 0,DEC,EQ  
    };
    
    dir find_dir(int x, int y) {
        return (x < y)? INC:(x==y?EQ:DEC);
    }
    int candy(vector<int>& ratings) {
        if (ratings.empty()) {
            return INT_MIN;
        }
        if (ratings.size() == 1)
            return 1;
        dir d = find_dir(ratings[0], ratings[1]);
        dir curd;
        int ncandy = 0, cur, count;
        int prev;//useful only for DEC
        int eqal;

        if (d == EQ) {
            ncandy = 1;
        } else if (d == INC) {
            ncandy = 1;
            cur = 1;
        } else {
            prev = 1;
            count = 1;
        }
        eqal = 1;
        for (int i = 1; i < ratings.size()-1;i++) {
            dir curd = find_dir(ratings[i], ratings[i+1]);
            if (d == INC) {
                cur++;
                eqal = cur;
                if (curd == DEC) {
                    prev = cur;
                    count = 1;
                } else {
                    ncandy += cur;
                }
            } else if (d == EQ) {
                // no change in eqal
                if (curd == EQ)
                    ncandy += eqal;
                else if (curd == INC) {
                    cur = eqal;
                    ncandy += eqal;
                } else {
                    prev = eqal;
                    count = 1;
                }
            } else if (d == DEC) {
                count++;
                if (curd == DEC)
                    ;
                else if (curd == EQ) {
                    eqal = 1;
                    if (count < prev) {
                        count--;
                        ncandy += (count * (count+1))/2;
                        ncandy += prev;
                    } else {
                        ncandy += (count * (count+1))/2;
                    }
                } else {
                    eqal = 1;
                    ncandy += (count * (count+1))/2;
                    cur = 1;
                }
            }
            d = curd;
        }
        //Handle the last element
        if (d == INC) {
            ncandy += (cur+1);
        } else if (d == EQ) {
            ncandy += 1;
        } else {
            count++;
            if (count < prev) {
                count--;
                ncandy += (count * (count+1))/2;
                ncandy += prev;
            } else {
                ncandy += (count * (count+1))/2;
            }
        }
        return ncandy;
    }
};
int main()
{
	int size;
	/*vector<int> v;
	cout<<"Enter the size of vector\n";
	cin>>size;
	cout<<"Enter the elements\n";
	for(int i = 0, x; i < size; i++) {
                cin>>x; 
		v.push_back(x);
	}*/
	vector<int> v{58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,
			12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,
			38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
	Solution s;
	cout<<s.candy(v)<<endl;
}
