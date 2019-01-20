#ifndef matrix_ops_h
#define matrix_ops_h

#include <iostream>
#include <vector>
using namespace std;
#include "matrix.h"


class MatrixOps{
	public:	
		Matrix pdt_matrix(matrix_h::Matrix A, matrix_h::Matrix B){// Takes matrix objects as inputs
			int row1=A.row;
			int col1=A.col;
			int row2=B.row;
			int col2=B.col;
			matrix_h::Matrix output;
			output.auto_size(row1,col2);
			
			
			if (col1==row2){
				for (int i=0;i<row1;i++)
				{
					for (int k=0;k<col2;k++)
					{
						for (int j=0;j<col1;j++)
						{
							output.matrix_rep[i][k]=output.matrix_rep[i][k]+(A.matrix_rep[i][j])*(B.matrix_rep[j][k]);
						}
					}
				}
			cout << "The matrix product is as follows: " << endl << endl;	
			output.show_matrix();
			}
			
			else{
				cout << "Matrix product is not possible." << endl;
			}
			return output;	
		}
			
		Matrix add_matrix(matrix_h::Matrix A, matrix_h::Matrix B){// Takes matrix objects as inputs
			int row1=A.row;
			int col1=A.col;
			int row2=B.row;
			int col2=B.col;
			matrix_h::Matrix output;
			output.auto_size(row1,col2);
			
			if ((row1==row2) && (col1==col2)){
				for (int i=0;i<row1;i++)
				{
					for (int j=0;j<col1;j++)
					{
							output.matrix_rep[i][j]=output.matrix_rep[i][j]+(A.matrix_rep[i][j])+(B.matrix_rep[i][j]);
					}
				}
				cout << "The matrix addition is as follows: " << endl << endl;
				output.show_matrix();
			}
			else{
				cout << "Matrix addition is not possible" << endl;
			}
			
			return output;
		}
	};
	


#endif
	



