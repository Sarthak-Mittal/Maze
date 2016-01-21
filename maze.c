#include<stdio.h>
# define MAX 9

 
void wall_off();
void print_maze();
void making_maze();


char arr[MAX][MAX];

int main()
{
making_maze();
wall_off();
print_maze();
}



void print_maze()
{
int i,j;

	for(i = 0 ; i<MAX ; i++)
	{
		for(j = 0 ; j<MAX ; j++)
			printf("%c ",arr[i][j]);
		printf("\n");
	}

}

void wall_off()
{
int i,j;

	i = 0;
	for(j = 0 ; j<MAX ; j++)
		arr[i][j] = '#';

	i = MAX - 1;
	for(j = 0 ; j<MAX ; j++)
		arr[i][j] = '#';

	j = 0;
	for(i = 0 ; i<MAX ; i++)
		arr[i][j] = '#';

	j = MAX - 1;
	for(i = 0 ; i<MAX ; i++)
		arr[i][j] = '#';

}


void making_maze()
{
int i,j;

//filling everything | '*' will represent undecided 
for(i = 0 ; i<MAX ; i++)
{	for(j = 0 ; j<MAX ; j++)
		arr[i][j] = '*';
}

//filling blocks which will always be walls : '#'
for(i = 0 ; i<MAX ; i=i+2)
{	for(j = 0 ; j<MAX ; j=j+2)
		arr[i][j] = '#';
}

//filling blocks which will always be path : '.'
for(i = 1 ; i<MAX ; i=i+2)
{	for(j = 1 ; j<MAX ; j=j+2)
		arr[i][j] = '.';
}

}

