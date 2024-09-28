#include "Matrix.hpp "

using namespace std;

int main() {

    vector<vector<double>> val = { {1, 3}, {7, 9} };
    Matrix A(2, 2, val);


    vector<vector<double>> values = { {2, 3}, {5, 6} };
    Matrix B(2, 2, values);


    cout << "Matrix A:" << endl;
    A.display();
    cout << endl;

    cout << "Matrix B:" << endl;
    B.display();
    cout << endl;


    B(0, 1) = 10;
    cout << "Matrix B after changing element (0,1) to 10:" << endl;
    B.display();
    cout << endl;


    Matrix C = A + B;
    cout << "Matrix A + B:" << endl;
    C.display();
    cout << endl;

    Matrix D = A - B;
    cout << "Matrix A - B:" << endl;
    D.display();
    cout << endl;

    Matrix E = A * B;
    cout << "Matrix A * B:" << endl;
    E.display();
    cout << endl;


    try {
        cout << "Attempting to access element (3, 1) in matrix B:" << endl;
        double value = B(3, 1);
    }
    catch (const Matrix::MatrixException& ex) {
        cerr << "Exception caught: " << ex.what() << endl;
    }


    Matrix F(2, 2);
    cout << "Enter values for matrix F:" << endl;
    cin >> F;

    cout << "Matrix F:" << endl;
    cout << F;

    return 0;
}
