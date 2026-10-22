/*
    ASSIGNMENT 5.3:
    Create a pseudocode and program that is used to multiply two 2x2 matrices whose data is input from the user,
    then display the input matrices and its multiplication result.

    Matrix multiplication has the following mechanism.

            [a11  a12]      [b11  b12]
    A  =    [a21 a22]   B = [b21  b22]

            [a11*b11 + a12*b21    a11*b12 + a12*b22]
    C  =    [a21*b11 + a22*b21    a21*b12 + a22*b22]
*/

#include <iostream>
using namespace std;

int main() {
    int matrixA[2][2];
    int matrixB[2][2];
    int matrixC[2][2];

    cout<<"Enter values for 2x2 matrix A: \n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<"Enter element [" <<i<< "][" <<j<< "]: ";
            cin>>matrixA[i][j];
        }
    }

    cout<<"\nEnter values for 2x2 matrix B: \n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<"Enter element [" <<i<< "][" <<j<< "]: ";
            cin>>matrixB[i][j];
        }
    }

    cout<<"\nMatrix A:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<matrixA[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\nMatrix B:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<matrixB[i][j]<<"\t";
        }
        cout<<endl;
    }

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            matrixC[i][j]=0;
            for(int k=0;k<2;k++) {
                matrixC[i][j]= matrixC[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout<<"\nA x B:\n";
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout<<matrixC[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}

/*]
PSEUDOCODE

START
    DECLARE matrixA[2][2], matrixB[2][2], matrixC[2][2] AS INTEGER

    OUTPUT "Enter values for 2x2 matrix A:"
    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            OUTPUT "Enter element [i][j]:"
            INPUT matrixA[i][j]
        END FOR
    END FOR

    OUTPUT "Enter values for 2x2 matrix B:"
    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            OUTPUT "Enter element [i][j]:"
            INPUT matrixB[i][j]
        END FOR
    END FOR

    OUTPUT "Matrix A:"
    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            OUTPUT matrixA[i][j]
        END FOR
        OUTPUT newline
    END FOR

    OUTPUT "Matrix B:"
    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            OUTPUT matrixB[i][j]
        END FOR
        OUTPUT newline
    END FOR

    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            matrixC[i][j] ← 0
            FOR k ← 0 TO 1 DO
                matrixC[i][j] ← matrixC[i][j] + matrixA[i][k] * matrixB[k][j]
            END FOR
        END FOR
    END FOR

    OUTPUT "A x B:"
    FOR i ← 0 TO 1 DO
        FOR j ← 0 TO 1 DO
            OUTPUT matrixC[i][j]
        END FOR
        OUTPUT newline
    END FOR
END
*/
