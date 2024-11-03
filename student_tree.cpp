#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int midterm;
    int final;
};

struct TreeNode {
    Student student;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(const Student& student) {
    TreeNode* newNode = new TreeNode();
    newNode->student = student;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

TreeNode* insert(TreeNode* root, const Student& student) {
    if (root == nullptr) {
        return createNode(student);
    }
    if (student.name < root->student.name) {
        root->left = insert(root->left, student);
    } else if (student.name > root->student.name) {
        root->right = insert(root->right, student);
    }
    return root;
}

TreeNode* search(TreeNode* root, const string& name) {
    if (root == nullptr || root->student.name == name) {
        return root;
    }
    if (name < root->student.name) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << "이름: " << root->student.name << ", 중간 점수: " << root->student.midterm << ", 기말 점수: " << root->student.final << endl;
        inorder(root->right);
    }
}

void deleteTree(TreeNode* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    int numStudents;
    cout << "학생 수를 입력하세요: ";
    cin >> numStudents;

    TreeNode* root = nullptr;

    for (int i = 0; i < numStudents; i++) {
        Student student;
        cout << (i + 1) << "번째 학생의 이름을 입력하세요: ";
        cin >> student.name;
        cout << student.name << "의 중간 점수를 입력하세요: ";
        cin >> student.midterm;
        cout << student.name << "의 기말 점수를 입력하세요: ";
        cin >> student.final;
        root = insert(root, student);
    }

    cout << "\n트리의 중위 순회 결과:\n";
    inorder(root);

    string searchName;
    cout << "\n검색할 학생의 이름을 입력하세요: ";
    cin >> searchName;
    TreeNode* result = search(root, searchName);
    if (result != nullptr) {
        cout << "찾음 - 이름: " << result->student.name << ", 중간 점수: " << result->student.midterm << ", 기말 점수: " << result->student.final << endl;
    } else {
        cout << "해당 학생을 찾을 수 없습니다.\n";
    }

    deleteTree(root);
    return 0;
}
