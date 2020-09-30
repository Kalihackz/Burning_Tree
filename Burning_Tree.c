#include <stdio.h>
#include <math.h>
int main(void)//the program starts from here
{
    int matrix[20][20],size,i,j,row,column;
    printf("**************************WELCOME TO 'The Burning Of Trees'**************************\n");
    printf("ENTER THE SIZE : ");
    scanf("%d",&size);//inputs the size of the 2D matrix
    assign(matrix,size);//fills up the matrix with random living cells and dead cells
        display(matrix,size);//displays the current generation matrix
        /**
         * Loop for the calculation of next generation
         * Updates the copy of the current generation matrix
         **/
        printf("ENTER THE CELL TO BE BURNED : \n");
        printf("ENTER THE ROW    : ");
        scanf("%d",&row);
        printf("ENTER THE COLUMN : ");
        scanf("%d",&column);
        burn(matrix,size,row,column);
        display(matrix,size);
    return 0;//program terminates successfully
}
void display(int matrix[][20],int size)//displays the generation matrix
{
    int i,j,x;char c=' ';
    printf("\n  ");
     for(j=0;j<size;j++)//loop for designing
     {
     printf("----");
     }
     printf("\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
        x=matrix[i][j];//takes the value of the current cell that is one for alive and zero for dead
        c=x==1?'T':' ';//if one then changes with 0 symbol and dead then changes with blank
        printf(" | %c",c);//prints the character 0 or blank
        }
        printf(" | \n");
        printf("  ");
        for(j=0;j<size;j++)
        {
        printf("----");
        }
        printf("\n");
    }
}
void assign(int matrix[][20],int size)//fills the generation matrix with random living or dead cells
{
    int i,j,r;
    srand(time(NULL));//sets the seed of the random number generator algorithm with different sequence.
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            r=rand()%2;//creates 0s and 1s randomly
            matrix[i][j]=r;//fills the current matrix cell with the random 0 or 1
        }
    }
}
void burn(int matrix[][20],int size,int curRow,int curCol)//counts the number of adjacent living cells
{
    int i,j,c=0;
    if(matrix[curRow][curCol]==0)
    {
        printf("NO TREE [T] IS PRESENT AT THIS CELL\n\n");
        return;
    }
    matrix[curRow][curCol]=2;
    for(i=curRow-1;i<=curRow+1;i++)
    {
        if(i<0||i==size)//skips the imaginary adjacent cells
        {
            continue;
        }
    for(j=curCol-1;j<=curCol+1;j++)
    {
        if(j<0||j==size)//skips the imaginary adjacent cells
        {
            continue;
        }
        if(matrix[i][j]==1)//if adjacent cell is alive counts the cell as living cell
        {
            burn(matrix,size,i,j);//counts the adjacent living cells
        }
    }
    }
}
