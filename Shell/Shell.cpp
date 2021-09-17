
#include <iostream>

using namespace std;

//int main()
//{
//	int k[17] = {0,503,87,512,61,908,170,897,275,653,426,154,509,612,677,765,703};
//	int H[6] = {0,1,1,2,4,8};
//	int s, h, R, i, K;
//	int t = 6;
//
//D1:	t = t - 1;
//	s = t;
//	int j = 17;
//	for (int p = 1; p < 17; p++) {
//		cout << (k[p]) << ' ';
//		if (p == 16) {
//			cout << endl;
//		}
//	}
//	if (s == 0){
//	return 0;
//	}
//	goto D2;
//
//D2:	h = H[s];
//	j = j - 1;
//	goto D3;
//
//D3:	i = j - h;
//	K = k[j];
//	R = k[j];
//	goto D4;
//
//D4:	if (K >= k[i]){
//	goto D6;
//}
//	goto D5;
//D5:	k[i+h] = k[i];
//	i = i - h;
//	if (i > 0) {
//	goto D4;
//	}
//	goto D6;
//D6:	k[i + h] = R;
//	if (j <= 17 && j > h) {
//		goto D2;
//	}
//	goto D1;
//}


int  main() {

	return 0;
}

void Myshell(){
		int R[16] = { 503,87,512,61,908,170,897,275,653,426,154,509,612,677,765,703 };
	int N, K,q = 5;
	int h[5] = { 1,2,3,5,7 };
		for (int s = h[q - 1]; q != 0; q--) {
			s = h[q - 1];
			for (int p = 0; p < 16; p++) {
				cout << R[p] << ' ';
				if (p == 15) {
					cout << endl;
				}
			}
			for (int i = 0; i < 16; i++) {
				for (int j = i + s; j < 16; j += s) {
					if (R[i] > R[j]) {
						K = R[j];
						R[j] = R[i];
						R[i] = K;
					}
				}
			}
		}
		for (int p = 0; p < 16; p++) {
			cout << R[p] << ' ';
			if (p == 15) {
				cout << endl;
			}
		}


}


void StandardShell(int size,int* R[]){
	int N, K;
	for (int s = size / 2; s > 0; s /= 2) {
		for (int p = 0; p < 16; p++) {
			cout << R[p] << ' ';
			if (p == 15) {
				cout << endl;
			}
		}
		for (int i = 0; i < 16; i++) {
			for (int j = i + s; j < 16; j += s) {
				if (R[i] > R[j]) {
					K = R[j];
					R[j] = R[i];
					R[i] = K;
				}
			}
		}
	}
	for (int p = 0; p < 16; p++) {
		cout << R[p] << ' ';
		if (p == 15) {
			cout << endl;
		}
	}

}



