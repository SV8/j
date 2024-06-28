#include <iostream>

using namespace std;

const int MAX_N = 100;
char dorm[MAX_N][MAX_N];
char tempDorm[MAX_N][MAX_N];

int n, m;

void printDorm() {
	cout << endl;
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dorm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void spreadFlu() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempDorm[i][j] = dorm[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dorm[i][j] == '@') {
                if (i > 0 && dorm[i-1][j] == '.') tempDorm[i-1][j] = '@'; // above
                if (i < n-1 && dorm[i+1][j] == '.') tempDorm[i+1][j] = '@'; // below
                if (j > 0 && dorm[i][j-1] == '.') tempDorm[i][j-1] = '@'; // left
                if (j < n-1 && dorm[i][j+1] == '.') tempDorm[i][j+1] = '@'; // right
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dorm[i][j] = tempDorm[i][j];
        }
    }
}

int countFlu() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dorm[i][j] == '@') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dorm[i][j];
        }
    }
    cin >> m;
    cout << endl << "Initial state:" << endl;
    printDorm();
    for (int day = 0; day < m; day++) {
        spreadFlu();
        cout << "After day " << day+1 << ":" << endl;
		printDorm();
    }
    cout << countFlu() << endl;
    return 0;
}
