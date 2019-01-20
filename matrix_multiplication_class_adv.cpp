#include <iostream>
#include <vector>
using namespace std;
#include "matrix_ops.h"

	
int main(){
	matrix_h::Matrix C;
	matrix_h::Matrix D;
	
	C.set_size();
	C.input_matrix();
	
	D.set_size();
	D.input_matrix();
	
	MatrixOps run;
	cout << endl;
	cout << "Output 1 is :" << endl;
	Matrix output1=run.pdt_matrix(C,D);
	cout << endl;
	cout << "Output 2 is :" << endl;
	Matrix output2=run.add_matrix(C,D);
	cout << endl;
	cout << "Output 3 is :" << endl;
	Matrix output3=run.pdt_matrix(output1,C);
	cout << endl;
	cout << "Output 4 is :" << endl;
	Matrix output4=run.add_matrix(output2,C);
	return 0;	
}	

