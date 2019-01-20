#include <iostream>
#include <vector>
using namespace std;

// Just prints each element of a matrix
void show_matrix(vector<vector<int> > output){
	int row1=output.size();
	int col2=output[0].size();
	for (int i=0;i<row1;i++)
	{
		for (int j=0;j<col2;j++)
		{
			
			cout << output [i][j] << " ";
		}
		cout << endl;
	} 
}
// assigns matrix given input row, column size and matrix's elements
void input_matrix(int row, int col, vector<vector<int> > * pointer){
	
	for (int i=0;i<row;i++){
		(*pointer)[i].resize(col);
	}
	for (int i=0;i<row;i++)
	{
		
		for (int j=0;j<col;j++)
		{
			
			cin >> (*pointer)[i][j];
		}
	}
}

// Matrix product
vector<vector<int> > pdt_matrix(vector<vector<int> > * pointer1,vector<vector<int> > * pointer2){
	int row1=(*pointer1).size();
	int col1=(*pointer1)[0].size();
	int row2=(*pointer2).size();
	int col2=(*pointer2)[0].size();
	vector<vector<int> > output(row1);
	for (int i=0;i<row1;i++){
		(output)[i].resize(col2);
	}
	
	for (int i=0;i<row1;i++)
	{
		for (int k=0;k<col2;k++)
		{
			for (int j=0;j<col1;j++)
			{
				(output)[i][k]=(output)[i][k]+((*pointer1)[i][j])*((*pointer2)[j][k]);
			}
		}
	}
	return output;
}

	
int main() {
	cout << "Enter matrix 1 size as rows x columns : " << endl ;
	int row1=0, col1=0;
	cin >> row1>> col1;
	vector<vector<int> > matrix1(row1);
	vector<vector<int> > * ptr1=&matrix1;
	
	cout << "Enter matrix 1 elements : " << endl ;
	input_matrix(row1,col1,ptr1);
	
	cout << "Enter matrix 2 size as rows x columns : " << endl ;
	int row2=0, col2=0;
	cin >> row2>> col2;
	vector<vector<int> > matrix2(row2);
	vector<vector<int> > * ptr2=&matrix2;
	
	cout << "Enter matrix 2 elements : " << endl ;
	input_matrix(row2,col2,ptr2);
	
	
	
	cout << "The product of matrices is as follows: " << endl;
	vector<vector<int> > output(row1);
	output=pdt_matrix(ptr1,ptr2);
	
	show_matrix(output);
	return 0;
}

