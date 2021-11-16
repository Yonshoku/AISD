#include <iostream>

using namespace std;

int main()
{
    int n = 4;
    int m = 10;
    
    int matrix[n][m];
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
    
    // Clockwise from outside
    int index = 0, level = 0;
    int i, j = 1;
    
    while (index < n * m) {
        
        // Fill upper line 
        for (int j = level - 1; j < m - level; j++) {
            if (j < 0) continue;
            
            matrix[level][j] = arr[index];
            index++;
        } 
        
        // Fill right line
        if (index < n * m) {
            for (int i = level + 1; i < n - level; i++) {
                matrix[i][m - level - 1] = arr[index];
                index++;
            }
        } 
        
        // Fill bottom line
        if (index < n * m) {
            for (int j = m - level - 2; j >= level; j--) {
                matrix[n - level - 1][j] = arr[index];
                index++;
            }
        }
        
        // Fill left line
        if (index < n * m) {
            for (int i = n - level - 2; i > level + 1; i--) {
                matrix[i][level] = arr[index];
                index++;
            }
        } 
        
        level += 1;
    }
    
    // Print 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
            matrix[i][j] = 0;
        }
        cout << endl;
    }
    
    cout << endl;
    cout << endl;
    
    
    // Counterclockwise from outside
    index = 0;
    level = 0;
    while (index < n * m) {
        
        // Fill upper line 
        for (int j = m - level - 1; j > level - 1; j--) {
            if (j < 0) continue;
            
            matrix[level][j] = arr[index];
            index++;
        } 
        
        // Fill left line
        if (index < n * m) {
            for (int i = level + 1; i < n - level; i++) {
                matrix[i][level] = arr[index];
                index++;
            }
        } 
        
        // Fill bottom line
        if (index < n * m) {
            for (int j = level + 1; j < m - level; j++) {
                matrix[n - level - 1][j] = arr[index];
                index++;
            }
        }
        
        // Fill right line
        if (index < n * m) {
            for (int i = n - level - 2; i > level; i--) {
                matrix[i][m - level - 1] = arr[index];
                index++;
            }
        } 
        
        level += 1;
    }
    
    // Print 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
