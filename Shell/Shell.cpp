
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>

using namespace std;

void Myshell(int* h, int* R, int size) {
	int N, K, q = 5;
	for (int s = h[q - 1]; q != 0; q--) {
		s = h[q - 1];
		/*for (int p = 0; p < size; p++) {
			cout << R[p] << ' ';
			if (p == 15) {
				cout << endl;
			}
		}*/
		for (int i = 0; i < size; i++) {
			for (int j = i + s; j < size; j += s) {
				if (R[i] > R[j]) {
					K = R[j];
					R[j] = R[i];
					R[i] = K;
				}
			}
		}
	}
	/*for (int p = 0; p < size; p++) {
		cout << R[p] << ' ';
		if (p == 15) {
			cout << endl;
		}
	}*/
}



void StandardShell(int h, int* R, int size) {
	int K = 0;
	for (int s = h / 2; s > 0; s /= 2) {
		//for (int p = 0; p < size; p++) {
		//	cout << R[p] << ' ';
		//	if (p == 15) {
		//		cout << endl;
		//	}
		//}
		for (int i = 0; i < size; i++) {
			for (int j = i + s; j < size; j += s) {
				if (R[i] > R[j]) {
					K = R[j];
					R[j] = R[i];
					R[i] = K;
				}
			}
		}
	}
	/*for (int p = 0; p < size; p++) {
		cout << R[p] << ' ';
		if (p == 15) {
			cout << endl;
		}
	}*/
}


int main() {
	int* arr = new int[5000];
	int key = 8;
	int Hkey[5] = {1,6,9,11,15};
	string fileName;
	cin >> fileName;
	ifstream currentFile(fileName, ios::in);
	if (currentFile.is_open()) {
		int N = 0;
		string line;
		while (getline(currentFile, line)) {
			istringstream iss(line);
			if (N >= 5000) {
				cout << "File " + fileName + " has more than 5000 numbers" << endl;
				return 0;
			}
			iss >> arr[N];
			N++;
		}
		auto start = chrono::high_resolution_clock::now();
		Myshell(Hkey,arr,N);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
		cout << duration << " microseconds" << endl;
		ofstream newFile("d" + to_string(N) + "s.txt");
		for (int i = 0; i < N; i++) {
			newFile << arr[i] << endl;
		}
		newFile.close();
		currentFile.close();
		delete[] arr;
	}
	else {
		cout << "Unable to open file" << endl;
	}
	return 0;
}







