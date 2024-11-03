#include <iostream>
#include <vector>

using namespace std;

void input_matrix(vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "요소 [" << i << "][" << j << "] 입력: ";
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(const vector<vector<int>>& matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "행렬의 행과 열의 개수를 입력하세요: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix1(rows, vector<int>(cols));
    vector<vector<int>> matrix2(rows, vector<int>(cols));
    vector<vector<int>> result(rows, vector<int>(cols));

    cout << "첫 번째 행렬의 요소들을 입력하세요:\n";
    input_matrix(matrix1, rows, cols);

    cout << "두 번째 행렬의 요소들을 입력하세요:\n";
    input_matrix(matrix2, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    cout << "두 행렬의 덧셈 결과:\n";
    print_matrix(result, rows, cols);

    return 0;
}
