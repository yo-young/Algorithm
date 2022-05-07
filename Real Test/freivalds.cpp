#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
using Mat = vector<vector<int>>;
bool Freivalds(Mat& A, Mat& B, Mat& C, int K, int x, int y) {
	int  t = 20;
	while (t--) {
		vector<int> r(K);
		generate(r.begin(),r.end(), []()->int {return rand() % 2; });
		vector<int> Br(K);
		for (int i = 0; i < K; i++) {	
			Br[i]=inner_product(r.begin(), r.end(), B[y+i].begin()+x, 0);
		}
		for (int i = 0; i < K; i++) {
			if (inner_product(Br.begin(), Br.end(), A[i].begin(), 0) - inner_product(r.begin(), r.end(), C[i].begin(), 0) != 0)
				return false;
		}
	}
	return true;
}
*/
int main()
{
    vector<vector<int>> A, B, C;
    

    return 0;
}