#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

#define MAX 20

int main() {
    int n;
    float p[MAX], q[MAX];
    float cost[MAX][MAX], w[MAX][MAX];
    int root[MAX][MAX];

    cout << "========================================" << endl;
    cout << "   OPTIMAL BINARY SEARCH TREE (OBST)   " << endl;
    cout << "      (Iterative Table Filling)        " << endl;
    cout << "========================================" << endl;

    cout << "\nEnter the number of keys: ";
    cin >> n;

    cout << "\nEnter the probabilities of successful search (p1 to p" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "  p[" << i << "] = ";
        cin >> p[i];
    }

    cout << "\nEnter the probabilities of unsuccessful search (q0 to q" << n << "):" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "  q[" << i << "] = ";
        cin >> q[i];
    }

    // Step 1: Initialize diagonal values (empty subtrees)
    for (int i = 0; i <= n; i++) {
        cost[i][i] = 0;
        w[i][i] = q[i];
    }

    // Step 2: Iteratively fill tables for increasing chain lengths
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len;

            // Compute weight: w[i][j] = w[i][j-1] + p[j] + q[j]
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            // Find the root that gives minimum cost
            cost[i][j] = INT_MAX;
            for (int r = i + 1; r <= j; r++) {
                float c = cost[i][r - 1] + cost[r][j] + w[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Step 3: Print Weight Table
    cout << "\n===== WEIGHT TABLE w[i][j] =====" << endl;
    cout << setw(8) << "i\\j";
    for (int j = 0; j <= n; j++)
        cout << setw(8) << j;
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << setw(4) << i << "   ";
        for (int j = 0; j <= n; j++) {
            if (j >= i)
                cout << setw(8) << fixed << setprecision(2) << w[i][j];
            else
                cout << setw(8) << " ";
        }
        cout << endl;
    }

    // Step 4: Print Cost Table
    cout << "\n===== COST TABLE cost[i][j] =====" << endl;
    cout << setw(8) << "i\\j";
    for (int j = 0; j <= n; j++)
        cout << setw(8) << j;
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << setw(4) << i << "   ";
        for (int j = 0; j <= n; j++) {
            if (j >= i)
                cout << setw(8) << fixed << setprecision(2) << cost[i][j];
            else
                cout << setw(8) << " ";
        }
        cout << endl;
    }

    // Step 5: Print Root Table
    cout << "\n===== ROOT TABLE root[i][j] =====" << endl;
    cout << setw(8) << "i\\j";
    for (int j = 1; j <= n; j++)
        cout << setw(8) << j;
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << i << "   ";
        for (int j = 1; j <= n; j++) {
            if (j > i)
                cout << setw(8) << root[i][j];
            else
                cout << setw(8) << " ";
        }
        cout << endl;
    }

    cout << "\n========================================" << endl;
    cout << "Minimum Search Cost : " << fixed << setprecision(4) << cost[0][n] << endl;
    cout << "Root of Optimal BST : k" << root[0][n] << endl;
    cout << "========================================" << endl;

    return 0;
}
