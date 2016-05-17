//Name: Sean Basler   Section: B

#include<iostream>
#include<string>

using namespace std;

//initial location of bender 
void bStart(char** maze, const int rowSize, const int colSize, int& theX, int& theY)
{
	theX = 0;
	theY = 0;
	
	for(int k = 0; k < rowSize; k++)
	{
		for(int j = 0; j < colSize; j++)
		{
			if(maze[k][j] == 'B')
			{
				theX = k;
				theY = j;
				return;
			} 
		}
	}
	
	cout<<"Something wrong with bStart";
	return;
}

//pathfinding
bool escape(char** maze, const int rowSize, const int colSize, 
			const int firstX, const int firstY)
{	
	for(int c = 0; c < 4; c++)
	{
		int x, y;//grid location
		
		//decision
		if(c == 0)
		{
			x = firstX + 1;
			y = firstY;
		}
		else if(c == 1)
		{
			x = firstX - 1;
			y = firstY;
		}
		else if(c == 2)
		{
			x = firstX;
			y = firstY + 1;
		}
		else//c == 3
		{
			x = firstX;
			y = firstY - 1;
		}
		//changes the map
		if(maze[x][y] != '#' && maze[x][y] != 'T' 
			&& maze[x][y] != '.')
		{
			if(maze[x][y] == 'E')
			{
				return true;
			}
			else
			{
				maze[x][y] = '.';
				bool solve = escape(maze, rowSize, colSize, x, y);
				if(solve)
					return true;
				else
					maze[x][y] = ' ';
			}
		}
	}
	
	return false;
}

int main()
{
	int row, col;//rows and columns in a maze
	int mapNum = 0; //number of maps calculated
	int firstX, firstY;
	
	do
	{
		char** maze;//create maze
		
		cin>>col>>row;
		//cerr << col << " - " << row << endl;
		if(col != 0 && row != 0)
		{
			cout<<endl;
			cout<<"Map : "<<mapNum<<endl;
			cin.ignore();
		
			//allocate maze
			maze = new char*[row];
			for(int k = 0; k < row; k++)
			{
				maze[k] = new char[col];
			}
			//filter out extra variables
			
			char dummy;
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					cin.get(maze[i][j]);
					//cerr << "-" << maze[i][j] << endl;
				}
				cin.get(dummy);
			}
			
			//cerr << "READ!" << endl;
			
			//recursive pathfinding function
			bStart(maze,row,col,firstX,firstY);
			if(escape(maze, row, col, firstX, firstY))
			{
				//print maze
				maze[firstX][firstY] = 'B';
				for(int p = 0; p < row; p++)
				{
					for(int t = 0; t < col; t++)
					{
						cout << maze[p][t];
					}
					cout << endl;
				}
			}
			else
			{
				cout<<endl;
				cout<<"There was no path. Error"<<endl;
			}
			
			//deallocate maze
			for(int d = 0; d < row; d++)
			{
				delete [] maze[d];
			}
			delete [] maze;
			
			mapNum++;//increments number of the map
		}
 	}	while(row != 0 && col != 0);
	
	cout<<endl;
	return 0;
}
