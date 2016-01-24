#include<stdio.h>
# define MAX 5
 
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
int i,j;
making_maze();
wall_off();
print_maze();
set_status();

	for(i = 1 ; i<MAX-1 ; i++)
	{
		for(j = 1 ; j<MAX-1 ; j++)
			printf("%d.%d.%d.%d---",arr[i][j].status[0],arr[i][j].status[1],arr[i][j].status[2],arr[i][j].status[3]);
		printf("\n\n\n");
	}



}

void set_status()
{
int i,j;

	for(i = 1 ; i<MAX-1 ; i=i+1)
	{
		for(j = 1 ; j<MAX-1 ; j=j+1)
		{
//status for walled
		   if(arr[i-1][j].img == '#')
			arr[i][j].status[0] = 8;
		   if(arr[i][j+1].img == '#')
			arr[i][j].status[1] = 8;
		   if(arr[i+1][j].img == '#')
			arr[i][j].status[2] = 8;
		   if(arr[i][j-1].img == '#')
			arr[i][j].status[3] = 8;
//status for undecided
		   if(arr[i-1][j].img == '*')
			arr[i][j].status[0] = 3;
		   if(arr[i][j+1].img == '*')
			arr[i][j].status[1] = 3;
		   if(arr[i+1][j].img == '*')
			arr[i][j].status[2] = 3;
		   if(arr[i][j-1].img == '*')
			arr[i][j].status[3] = 3;
//status for path
		   if(arr[i-1][j].img == '.')
			arr[i][j].status[0] = 1;
		   if(arr[i][j+1].img == '.')
			arr[i][j].status[1] = 1;
		   if(arr[i+1][j].img == '.')
			arr[i][j].status[2] = 1;
		   if(arr[i][j-1].img == '.')
			arr[i][j].status[3] = 1;
				
}	

	}

}


// walled => 8
// unddecided => 3
// pathed => 1
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
