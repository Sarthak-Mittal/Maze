#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include "random.c"

# define MAX 9
 
void print_maze();
void making_maze();
void move_fwd(int x, int y);
//int random_array();

struct node{
char img;
int pre_x;
int pre_y;
int status; // status = 1 is occupied and 0 is empty.
}arr[MAX][MAX];

/*
int random_array()
{
srand(time(NULL));
int a,b,c,d;
int i,j,temp;
int arr[4];
for(i=0 ; i<4 ; i++)
arr[i]=i+1;

a = rand()%2+1;
b = rand()%2+2;
c = rand()%2+1;
d = rand()%2+2;
printf("%d%d%d%d",a,b,c,d);
for(i=a ; i<=b ; i++)
 {
  for(j=c ; j<=d ; j++)
   {
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
   }
 }

for(i=0 ; i<4 ; i++)
printf("%d",arr[i]);
printf("\n");
}
*/

int main()
{

int i,j;

making_maze();
arr[2][2].img = '.';
arr[2][2].status = 1;
move_fwd(2,2);
print_maze();
}
void print_maze()
{
int i,j;

	for(i = 1 ; i<MAX-1 ; i++)
	{
		for(j = 1 ; j<MAX-1 ; j++)
			printf("%c ",arr[i][j].img);
		printf("\n");
	}
printf("\n..................................................\n");
	

	for(i = 1 ; i<MAX-1 ; i++)
	{
		for(j = 1 ; j<MAX-1 ; j++)
			printf("%d ",arr[i][j].status);
		printf("\n");
	}

}


void making_maze()
{
int i,j;

//filling blocks which will always be walls : '#'
for(i = 0 ; i<MAX ; i++)
{	for(j = 0 ; j<MAX ; j++)
		arr[i][j].img = '#';
}

//following lines will mark status as occupied for boundary walls
	i = 0;
	for(j = 0 ; j<MAX ; j++)
	{	
		arr[i][j].status = 1;
	}

	i = MAX - 1;
	for(j = 0 ; j<MAX ; j++)
	{	
		arr[i][j].status = 1;
	}

	j = 0;
	for(i = 0 ; i<MAX ; i++)
	{	
		arr[i][j].status = 1;
	}

	j = MAX - 1;
	for(i = 0 ; i<MAX ; i++)
	{	
 		arr[i][j].status = 1;
  	}
///////////////////////////////
i = 1;
	for(j = 1 ; j<MAX-1 ; j++)
	{	
		arr[i][j].status = 1;
	}

	i = MAX - 2;
	for(j = 1 ; j<MAX-1 ; j++)
	{	
		arr[i][j].status = 1;
	}

	j = 1;
	for(i = 1 ; i<MAX-1 ; i++)
	{	
		arr[i][j].status = 1;
	}

	j = MAX - 2;
	for(i = 1 ; i<MAX-1 ; i++)
	{	
 		arr[i][j].status = 1;
  	}

}

void move_fwd(int x, int y)
{
// here random array function will be called
// obtained array will be used in loop.
int i,*p;
int ranArr[4];

sleep(1.2);
  p = rand_arr();
	
   for ( i = 0; i < 4; i++ ) 
   {
      ranArr[i] = *(p + i);  
	printf("%d",*(p+i));
   }

// this array gives the direction to our current location.
		/*
		* 1 = top
		* 2 = right
		* 3 = bottom
		* 4 = left
		*/


//for(i=0 ; i<4 ; i++)
//rand_arr[i] = i+1;

for(i=0 ; i<4 ; i++)
{
switch(ranArr[i])
{

case 1:

	if(arr[x+2][y].status == 0)
	{
	arr[x+2][y].pre_x = x;
	arr[x+2][y].pre_y = y;
	arr[x+1][y].img = '.';
	arr[x+2][y].img = '.';
	arr[x+2][y].status = 1;
	arr[x+1][y].status = 1;
print_maze();

	move_fwd(x+2,y);
	}
	else if(arr[x+2][y].status == 1)
	{
print_maze();

	move_fwd(arr[x][y].pre_x,arr[x][y].pre_y);
	}
	break;
case 2:
	if(arr[x-2][y].status == 0)
	{
	arr[x-2][y].pre_x = x;
	arr[x-2][y].pre_y = y;
	arr[x-1][y].img = '.';
	arr[x-2][y].img = '.';
	arr[x-2][y].status = 1;
	arr[x-1][y].status = 1;
print_maze();

	move_fwd(x-2,y);
	}
	else if(arr[x-2][y].status == 1)
	{
print_maze();

	move_fwd(arr[x][y].pre_x,arr[x][y].pre_y);
	}
	break;
case 3:
	if(arr[x][y+2].status == 0)
	{
	arr[x][y+2].pre_x = x;
	arr[x][y+2].pre_y = y;
	arr[x][y+1].img = '.';
	arr[x][y+2].img = '.';
	arr[x][y+2].status = 1;
	arr[x][y+1].status = 1;
print_maze();

	move_fwd(x,y+2);
	}
	else if(arr[x][y+2].status == 1)
	{
print_maze();

	move_fwd(arr[x][y].pre_x,arr[x][y].pre_y);
	}
	break;
case 4:
	if(arr[x][y-2].status == 0)
	{
	arr[x][y-2].pre_x = x;
	arr[x][y-2].pre_y = y;
	arr[x][y-1].img = '.';
	arr[x][y-2].img = '.';
	arr[x][y-2].status = 1;
	arr[x][y-1].status = 1;
print_maze();

	move_fwd(x,y-2);
	}
	else if(arr[x][y-2].status == 1)
	{
print_maze();

	move_fwd(arr[x][y].pre_x,arr[x][y].pre_y);
	}
	break;

}
}
}

