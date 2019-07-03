
#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <vector>
using namespace std;

class Matrix{
	public:
		int row=1,col=1;
	
		vector<vector<int> > matrix_rep;
		
		void auto_size(int row1,int col1){// creates an empty matrix with required rows and columns, USER does not input
			row=row1;
			col=col1;
			matrix_rep.resize(row,vector<int>(col,0));
		}
		
	
		
		void set_size(){  // assigns matrix given input row, column size and matrix's elements, USER creation
			
			cout << "Enter matrix size as rows x columns : " << endl ;
			cin >> row>> col;	
		}
		
		
		void input_matrix(){ // USER creation
			cout << "Enter matrix elements : " << endl ;
			matrix_rep.resize(row,vector<int>(col,0));
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<col;j++)
				{
					cin >> (matrix_rep)[i][j];
				}
			}
		}
	
		void show_matrix(){ // Just prints each element of a matrix
			cout << "Matrix Output is as follows: " << endl;
			for (int i=0;i<row;i++)
			{
				for (int j=0;j<col;j++)
				{
					cout << matrix_rep[i][j] << " ";
				}
				cout << endl;
			} 
		}
		
		
		
	};

			
#endif

