#include<stdio.h>
# define MAX 7
 
void wall_off();
void print_maze();
void making_maze();
void set_status();

struct node{
char img;
int pre_x;
int pre_y;
int status[4];
}arr[MAX][MAX];


int main()
{
making_maze();
wall_off();
print_maze();
}

void set_status()
{
int i,j;

	for(i = 1 ; i<MAX-1 ; i=i+1)
	{
		for(j = 1 ; j<MAX-1 ; j=j+1)
		{
		   if(arr[i-1][j] == '#')
			arr[i][j].status[1] = 8;
		   if(arr[i][j+1] == '#')
			arr[i][j].status[2] = 8;
		   if(arr[i+1][j] == '#')
			arr[i][j].status[3] = 8;
		   if(arr[i][j-1] == '#')
			arr[i][j].status[4] = 8;
		}	

	}

}


// walled => 8
//  * 1 *
//  4 - 2 
//  * 3 *


void print_maze()
{
int i,j;

	for(i = 0 ; i<MAX ; i++)
	{
		for(j = 0 ; j<MAX ; j++)
			printf("%c ",arr[i][j].img);
		printf("\n");
	}

}


void wall_off()
{
int i,j;

	i = 0;
	for(j = 0 ; j<MAX ; j++)
		arr[i][j].img = '#';

	i = MAX - 1;
	for(j = 0 ; j<MAX ; j++)
		arr[i][j].img = '#';

	j = 0;
	for(i = 0 ; i<MAX ; i++)
		arr[i][j].img = '#';

	j = MAX - 1;
	for(i = 0 ; i<MAX ; i++)
		arr[i][j].img = '#';

}


void making_maze()
{
int i,j;

//filling everything | '*' will represent undecided 
for(i = 0 ; i<MAX ; i++)
{	for(j = 0 ; j<MAX ; j++)
		arr[i][j].img = '*';
}

//filling blocks which will always be walls : '#'
for(i = 0 ; i<MAX ; i=i+2)
{	for(j = 0 ; j<MAX ; j=j+2)
		arr[i][j].img = '#';
}

//filling blocks which will always be path : '.'
for(i = 1 ; i<MAX ; i=i+2)
{	for(j = 1 ; j<MAX ; j=j+2)
		arr[i][j].img = '.';
}

}
