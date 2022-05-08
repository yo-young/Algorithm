#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stdio.h>

using namespace std;
using Mat = vector<vector<int>>;

void MultiMatrix(Mat& XY, Mat& X, Mat& Y, int X_row, int X_col, int r_col)
{
	int i, j, k;
    for(i = 0; i < X_row; i++) {
        for(j = 0; j < r_col; j++) {
            for(k = 0; k < X_col; k++) {
				cout << i << ", " << j << ", " << k << "    ";
				cout << X[i][k] << " * " << Y[k][j] << endl;
                XY[i][j] += X[i][k] * Y[k][j];
            }
        }
    }

}

bool Freivalds(Mat& A, Mat& B, Mat& C, int K, int x, int y) {
	int  t = 20;
	cout << "Freivalds" << endl;
	while (t--) {
		vector<int> r(K);
		Mat R;
		generate(r.begin(),r.end(), []()->int {return rand() % 2; });
		for_each(r.begin(), r.end(), [](int n)->void {cout << n << " ";}); cout << endl;
		R.push_back(r);
		cout << "size : " << R[0].size() << endl;

		vector<int> Br(K);
		Mat BR;
		BR.push_back(Br);
		MultiMatrix(BR, B, R, B.size(), B[0].size(), R.size());

		/*for (int i = 0; i < K; i++) {	
			Br[i]=inner_product(r.begin(), r.end(), B[y+i].begin()+x, 0);
		}*/

		//for_each(Br.begin(), Br.end(), [](int n)->void {cout << n << " ";});
		//for (int i = 0; i < K; i++) {
			//if (inner_product(Br.begin(), Br.end(), A[i].begin(), 0) - inner_product(r.begin(), r.end(), C[i].begin(), 0) != 0)
				return false;
		//}
	}
	cout << "true" << endl;
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
	B = {{1, 0, 7, 5},
	     {1, 2, 8, 7}};
	C = {{6, 5},
	     {8, 7}};
	bool ans = Freivalds(A, B, C, 10, 10, 0);
	cout << ans << endl;

    return 0;
}