
#include <iostream>

using namespace std;

int main()
{
	int k[17] = {0,293,180,389,639,928,107,324,723,422,840,206,599,445,359,841,378};
	int H[5] = {0,1,2,4,8};
	int s,h,i,K,R;
	int t = 5;

D1:	t = t - 1;
	s = t;
	h = H[s];
	int j = 17;
	for (int p = 1; p < 17; p++) {
		cout << (k[p]) << ' ' ;
		if (p == 16) {
			cout << endl;
		}
	}
	if (s == 0){
	return 0;
	}
	goto D2;

D2:	j = j - 1;
	if (j > h) {
		goto D3;
	}
	else{
		goto D1;
	}

D3:	i = j - h;
	K = k[j];
	R = k[j];
	goto D4;

D4:	if (K >= k[i]){
	goto D6;
}
else {
	goto D5;
}
D5:	k[i+h] = k[i];
	i = i - h;
	if (i > 0) {
	goto D4;
	}
	goto D6;
D6:	k[i + h] = R;
	goto D2;
}