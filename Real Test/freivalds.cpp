#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdio.h>

using namespace std;
using Mat = vector<vector<int>>;

void MultiMatrix(Mat& XY, Mat& X, Mat& Y, int X_row, int X_col, int r_row, int r_col)
{
	int i, j, k;
    for(i = 0; i < X_row; i++) {
        for(j = 0; j < r_col; j++) {
            for(k = 0; k < X_col; k++) {
				//cout << i << ", " << k << ", " << j << "    ";
				//cout << X[i][k] << " * " << Y[k][j] << endl;
                XY[i][j] += X[i][k] * Y[k][j];
            }
        }
    }

}

bool Freivalds(Mat& A, Mat& B, Mat& C) {
	int  t = 10;
	//cout << "Freivalds" << endl;
	while (t--) {
		vector<int> r(1);
		Mat R(B[0].size(), r);
		for_each(R.begin(), R.end(), [](vector<int>& mat)->void {mat[0] = rand()%2;});

		//for(int i=0; i<B[0].size(); i++) { cout << R[i][0] << " "; } cout << endl;

		vector<int> Br(1);
		Mat BR(B.size(), Br);
		MultiMatrix(BR, B, R, B.size(), B[0].size(), R.size(), R[0].size());
		vector<int> Cr(1);
		Mat CR(C.size(), Cr);
		MultiMatrix(CR, C, R, C.size(), C[0].size(), R.size(), R[0].size());
		//cout << "CR" << endl;
		/*for(int i=0; i<CR.size(); i++) {
			for_each(CR[i].begin(), CR[i].end(), [](int n)->void { cout << n << " ";});
			cout << endl;
		}*/

		Mat ABR(A.size(), Br);
		MultiMatrix(ABR, A, BR, A.size(), A[0].size(), BR.size(), BR[0].size());
		//cout << "ABR" << endl;
		/*for(int i=0; i<ABR.size(); i++) {
			for_each(ABR[i].begin(), ABR[i].end(), [](int n)->void { cout << n << " ";});
			cout << endl;
		}*/
		for(int i=0; i<ABR.size(); i++) {
			for(int j=0; j<ABR[i].size(); j++) {
				if(ABR[i][j] - CR[i][j]) {
					return false;
				}
			}
		}

	}
	return true;
}


int main()
{
	/*Mat r(20, vector<int>(1,0));
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            cout << r[i][j] << " ";
        }
        cout<< endl;
    }*/
    Mat A, B, C;
	A = {{2, 3},
	     {3, 4},
		 {4, 5},
		 {5, 6},
		 {6, 7}};
		 //5 * 2
	B = {{1, 1, 1, 1},
	     {2, 2, 2, 2}};
		 //2 * 4
	C = {{8, 8, 8, 9},
	     {11, 11, 11, 11},
		 {14, 14, 14, 14},
		 {17, 17, 17, 17},
		 {20, 20, 20, 20}};
	bool ans = Freivalds(A, B, C);
	cout << "ans : " << ans << endl;

    return 0;
}