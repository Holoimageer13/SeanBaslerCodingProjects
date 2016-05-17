//Name: Sean Basler    Section: B	
//Date: 9/5/14		   Instructor: Professor Morales

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int W, H;//Width of array(W) and Height of array(H)
	int row, col;//the row and column number and the highest sum
	int sum = 0;//highest sum
	int initialSum;//all sums
	int* T;//number of arrays(T), 
	int* colSum; 
	int* rowSum; //Column Sums, Row Sums
	int** grid;//the grid
	
	//Creation of pointers
	T = new int;	
		
	//Input 
	cin>>*T;//number of grids
	
	//Calculation and Output
	for(int k = 0; k<*T; k++)
	{
		cin>>W;
		cin>>H;//input for grid height and width
		
		// allocate grid[W][H]
		grid = new int*[W];
		for(int p = 0; p < W; p++)
			grid[p] = new int[H];
	
		colSum = new int[W];
		rowSum = new int[H];

		for(int p = 0; p<W; p++)
		{
			colSum[p] = 0;
		}
		
		for(int t = 0; t<H; t++)
		{
			rowSum[t] = 0;
		}

		for(int i = 0; i<H; i++)
		{
			for(int j = 0; j<W; j++)
			{
				cin>>grid[j][i];//fills grid
			}
		}
		
		if(W <= H)
		{
			for(int i = 0; i<W; i++)
			{
				for(int j = 0; j<H; j++)
				{
					rowSum[j] += grid[i][j];//adds up rows
					colSum[i] += grid[i][j];//adds columns
				}
			}
		}
		else 
		{
			for(int i = 0; i<H; i++)
			{
				for(int j = 0; j<W; j++)
				{
					rowSum[i] += grid[j][i];//adds up rows
					colSum[j] += grid[j][i];//adds columns
				}
			}
		}
		
		for(int j = 0; j<H; j++)
		{
			for(int i = 0; i<W; i++)
			{
				initialSum = rowSum[j] + (colSum[i] - grid[i][j]);
				if(initialSum > sum)
				{
					sum = initialSum;
					col = i;
					row = j;
				}
			}
		}
	
		cout<<"#"<<k<<": ("<<col<<", "<<row<<") "<<sum<<endl;
		sum = 0;
		
		//Destruction internal pointers
		for(int p = 0; p<W; p++)
			delete [] grid[p];
		delete [] grid;
		delete [] colSum;
		delete [] rowSum;
	}	
	
	//Destruction of pointers
	delete T;
	
	return 0;
}
