/*
Sem-6 LP-II AI
Practical-2 : Implement A* Algorithm for any game search problem.
*/

#include<stdio.h>

void create(int[3][3]);
void display(int[3][3]);
int huristic(int[3][3]);
int moveUp(int[3][3],int*);
int moveDown(int[3][3],int*);
int moveLeft(int[3][3],int*);
int moveRight(int[3][3],int*);

void main()
{
    int i,j,h1,h2,h3,h4,min,index,old1,old2,old3,old4,depth,arr[3][3],try1[3][3],try2[3][3],try3[3][3],try4[3][3],H[5];

    printf("************** A* Algorithm *****************\n");
    printf("************ 8 PUZZLE PROBLEM *****************\n");
    create(arr);
    display(arr);

    old1 = old2 = old3 = old4 = -1;
    depth = 0;
    while(1)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                try1[i][j] = try2[i][j] = try3[i][j] = try4[i][j] = arr[i][j];
            }
        }

        h1 = moveUp(try1,&old1);
        h2 = moveDown(try2,&old2);
        h3 = moveLeft(try3,&old3);
        h4 = moveRight(try4,&old4);
        
        H[1] = min = h1;
        H[2] = h2;
        H[3] = h3;
        H[4] = h4;
        index = 1;
        
        for(i=1;i<5;i++)
        {    
            if(min > H[i])
            {    
                min = H[i];
                index = i;
            }
        }
        
        switch(index)
        {
            case 1: for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            arr[i][j] = try1[i][j];
                        }
                    } 
                    old2 = old1;
                    old1 = old3 = old4 = -1;
                    printf("\t* Move UP ( ^ )\n");
                    break;

            case 2: for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            arr[i][j] = try2[i][j];
                        }
                    }
                    old1 = old2;
                    old2 = old3 = old4 = -1;
                    printf("\t* Move DOWN\n");
                    break;

            case 3: for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            arr[i][j] = try3[i][j];
                        }
                    }
                    old4 = old3;
                    old1 = old2 = old3 = -1;
                    printf("\t* Move LEFT ( <- )\n");
                    break;

            case 4: for(i=0;i<3;i++)
                    {
                        for(j=0;j<3;j++)
                        {
                            arr[i][j] = try4[i][j];
                        }
                    }
                    old3 = old4;
                    old1 = old2 = old4 = -1;
                    printf("\t* Move RIGHT ( -> )\n");
                    break;

        }
        depth++;
        display(arr);

        if(huristic(arr) == 0)
        {    
            printf("We Got Solution .....");
            printf("\nDepth = %d",depth);
            break;
        }
        getchar();
    }
   
}

void create(int arr[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter number at position [%d][%d] : ",i,j);
            scanf("%d",&(arr[i][j]));
        }
    }
    printf("///////////////////////////////////////////////////////\n");
}

void display(int arr[3][3])
{
    int i,j;
    printf("8 Puzzle Matrix :\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("---------------------------------\n");
}

int huristic(int arr[3][3])
{
    int i,j,real,count;
    real = 1;
    count = 0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j] != real)
            {
                count++;
            }
            real++;
        }
    }
    if(count == 1)
        return 0;
    else
        return count;
}

int moveUp(int arr[3][3],int* old)
{
    int i,j,flag = 0;
    if(arr[0][0]!=0 && arr[0][1]!=0 && arr[0][2]!=0)
    {
        for(i=1;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(*old != arr[i-1][j])
        {
            arr[i][j] = *old = arr[i-1][j];
            arr[i-1][j] = 0;
            return huristic(arr);
        }
        else
            return 10;
    }
    else
        return 10;
}

int moveDown(int arr[3][3],int* old)
{
    int i,j,flag = 0;
    if(arr[2][0]!=0 && arr[2][1]!=0 && arr[2][2]!=0)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(*old != arr[i+1][j])
        {
            arr[i][j] = *old = arr[i+1][j];
            arr[i+1][j] = 0;
            return huristic(arr);
        }
        else
            return 10; 
    }
    else
        return 10;
}

int moveLeft(int arr[3][3],int* old)
{
    int i,j,flag = 0;
    if(arr[0][0]!=0 && arr[1][0]!=0 && arr[2][0]!=0)
    {
        for(i=0;i<3;i++)
        {
            for(j=1;j<3;j++)
            {
                if(arr[i][j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(*old != arr[i][j-1])
        {
            arr[i][j] = *old = arr[i][j-1];
            arr[i][j-1] = 0;
            return huristic(arr);
        }
        else
            return 10;
    }
    else
        return 10;
}

int moveRight(int arr[3][3],int* old)
{
    int i,j,flag = 0;
    if(arr[0][2]!=0 && arr[1][2]!=0 && arr[2][2]!=0)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<2;j++)
            {
                if(arr[i][j] == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)
                break;
        }
        if(*old != arr[i][j+1])
        {
            arr[i][j] = *old = arr[i][j+1];
            arr[i][j+1] = 0;
            return huristic(arr);
        }
        else
            return 10;
    }
    else
        return 10;
}