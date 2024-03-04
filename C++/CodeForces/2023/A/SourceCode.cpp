#include <iostream>

using namespace std;

void suspect(int D, int A[], int B[], int key[]) {
    int innocent = false;
    for (int i = 0; i < D; i++)
        if (!(key[i] >= A[i] - B[i] && key[i] <= A[i])) {
            innocent = true;
            break;
        }
    cout << (innocent ? "INNOCENT" : "SUS") << endl;
}

int main() {
    int D, N;
    cin >> D >> N;
    int A[D];
    for (int i = 0; i < D; i++)
        cin >> A[i];
    int B[D];
    for (int i = 0; i < D; i++)
        cin >> B[i];
    int key[N][D];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < D; j++)
            cin >> key[i][j];
    for (int i = 0; i < N; i++)
        suspect(D, A, B, key[i]);
    return 0;
}