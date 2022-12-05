#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
void FillMatrix(int ** matrix,int rows, int columns,int num)
{
    int h;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(num==1)
            {
                printf("A[%d][%d]:",i+1,j+1);
            }
            else
            {
                printf("B[%d][%d]:",i+1,j+1);
            }
            scanf(("%d"),&h);
            matrix[i][j]=h;
        }
    }
    printf("\n");
}
void PrintMatrix(int ** matrix,int rows, int columns)
{
    printf("\n----------\n");
    for(int i=0;i<rows;i++)
    {
        printf("|");
        for(int j=0;j<columns;j++)
        {
            printf("%d|",matrix[i][j]);
        }
        printf("\n----------\n");
    }
}
void MaxAndMinElemA(int ** matrix,int rows)
{
    int MaxElem,MinElem,times=1;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<rows;j++)
        {
            if(i<j)
            {
                if(times==1)
                {
                    MaxElem=matrix[i][j];
                    MinElem=matrix[i][j];
                    times=0;
                }
                else if(matrix[i][j]>MaxElem)
                {
                    MaxElem=matrix[i][j];
                }
                else if(matrix[i][j]<MinElem)
                {
                    MinElem=matrix[i][j];
                }
            }
        }
    }
    printf("MaxElem:%d\n",MaxElem);
    printf("MinElem:%d\n",MinElem);
    system("pause");
}
void TransB(int ** matrix,int rows,int columns)
{
    int Vrows=columns;
    int Vcolumns=rows;
    int** var=calloc(columns, sizeof(int*));
    for(int i=0;i<columns;i++)
    {
        var[i]=(int*)calloc(rows, sizeof(int));
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            var[j][i]=matrix[i][j];
        }
    }
    printf("Transported matrix:");
    PrintMatrix(var,Vrows,Vcolumns);
    system("pause");
}
void MultAxB(int** A,int Arows,int** B,int Brows,int Bcolumns)
{
    if(Arows==Brows)
    {
        int** var=calloc(Arows, sizeof(int*));
        for(int i=0;i<Arows;i++)
        {
            var[i]=(int*)calloc(Bcolumns, sizeof(int));
        }
        for(int i=0;i<Arows;i++)
        {
            for(int j=0;j<Bcolumns;j++)
            {
                for(int k=0;k<Arows;k++)
                {
                    var[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        printf("multiplied matrix:");
        PrintMatrix(var,Arows,Bcolumns);
    }
    else
    {
        printf("These matrixes cant be multiplied\n");
    }
    system("pause");
}
void SortA(int** A,int Arows)
{
    int var=0;
    int* NewA;
    int** SortedA;
    int size=Arows*Arows;

    NewA=(int*)calloc(size, sizeof(int));

    SortedA=(int**)calloc(Arows, sizeof(int*));
    for(int i=0;i<Arows;i++)
    {
        SortedA[i]=(int*)calloc(Arows, sizeof(int));
    }
    for(int i=0;i<Arows;i++)
    {
        for(int j=0;j<Arows;j++,var++)
        {
            NewA[var]=A[i][j];
        }
    }
    int variant=0;
    while(variant<1||variant>2)
    {
        printf("1 - sort matrix A\n2 - sort row of matrix A\n Choose:");
        scanf("%d",&variant);
    }
    if(variant==1)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(NewA[j]>NewA[i])
                {
                    var=NewA[i];
                    NewA[i]=NewA[j];
                    NewA[j]=var;
                }
            }
        }
    }
    else
    {
        variant=0;
        while(variant<1||variant>Arows)
        {
            printf("Choose the row:");
            scanf("%d",&variant);
        }
        variant--;
        variant=variant*Arows;
        for(int i=variant;i<variant+Arows;i++)
        {
            for(int j=variant;j<variant+Arows;j++)
            {
                if(NewA[j]>NewA[i])
                {
                    var=NewA[i];
                    NewA[i]=NewA[j];
                    NewA[j]=var;
                }
            }
        }
    }
    var=0;
    for(int i=0;i<Arows;i++)
    {
        for(int j=0;j<Arows;j++,var++)
        {
            SortedA[i][j]=NewA[var];
        }
    }
    system("CLS");
    printf("sorted matrix:");
    PrintMatrix(SortedA,Arows,Arows);
    system("pause");
}
void SumAandB(int** A,int Arows,int** B,int Brows,int Bcolumns)
{
    printf("Sum of rows of A:");
    for(int i=0;i<Arows;i++)
    {
        int var=0;
        for(int j=0;j<Arows;j++)
        {
            var+=A[i][j];
        }
        printf("\n%d",var);
    }
    printf("\n\nSum of rows of B:\n");
    for(int i=0;i<Bcolumns;i++)
    {
        int var=0;
        for(int j=0;j<Brows;j++)
        {
            var+=B[j][i];
        }
        printf("%d\n",var);
    }
    system("pause");
}
int main()
{
    int** A;
    int** B;
    int Arows=0, Brows=0;
    int Bcolumns=0;
    //--------------------------------------------------------------------------------------
    printf("The number of rows and columns of the matrix A");
    while(Arows<1)
    {
        printf("\nEnter number:");
        scanf("%d",&Arows);
    }

    A=(int**)calloc(Arows, sizeof(int*));
    if(A==NULL)
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i=0;i<Arows;i++)
    {
        A[i]=(int*)calloc(Arows, sizeof(int));
        if(A[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    //--------------------------------------------------------------------------------------
    printf("The number of rows of the matrix B");
    while(Brows<1)
    {
        printf("\nEnter number:");
        scanf("%d",&Brows);
    }
    printf("The number of columns of the matrix B");
    while(Bcolumns<1)
    {
        printf("\nEnter number:");
        scanf("%d",&Bcolumns);
    }
    B=(int**)calloc(Bcolumns, sizeof(int*));
    if(B==NULL)
    {
        printf("Memory has not been allocated");
        exit(0);
    }
    for(int i=0;i<Bcolumns;i++)
    {
        B[i]=(int*)calloc(Brows, sizeof(int));
        if(B[i]==NULL)
        {
            printf("Memory has not been allocated");
            exit(0);
        }
    }
    //--------------------------------------------------------------------------------------


    printf("Fill matrix A:\n");
    printf("A[row][column]\n");
    FillMatrix(A,Arows,Arows,1);
    printf("Fill matrix B:\n");
    printf("B[row][column]\n");
    FillMatrix(B,Brows,Bcolumns,2);

    //--------------------------------------------------------------------------------------
    while(1)
    {
    int WhatToDo=0;
    while(WhatToDo<1||WhatToDo>6)
    {
        system("CLS");
        printf("Matrix A:\n");
        PrintMatrix(A,Arows,Arows);
        printf("\nMatrix B:\n");
        PrintMatrix(B,Brows,Bcolumns);
        printf("\nChoose variant:\n 1 - Find the maximum and minimum element of matrix A above the main diagonal");
        printf("\n 2 - Transporting matrix B");
        printf("\n 3 - Multiplication of matrices A*B");
        printf("\n 4 - Arrange all the elements of the matrix A in ascending order");
        printf("\n 5 - Displaying the sum of the elements of the rows of the matrix A and the columns of the matrix B");
        printf("\n 6 - Exit\n");
        printf("\nChoose:");
        scanf("%d", &WhatToDo);
        system("CLS");
    }
    if(WhatToDo==6)
    {
        break;
    }
    switch(WhatToDo)
    {
        case 1:
            MaxAndMinElemA(A,Arows);
            break;
        case 2:
            TransB(B,Brows,Bcolumns);
            break;
        case 3:
            MultAxB(A,Arows,B,Brows,Bcolumns);
            break;
        case 4:
            SortA(A,Arows);
            break;
        case 5:
            SumAandB(A,Arows,B,Brows,Bcolumns);
            break;
        }
    }
    for (int i = 0; i < Arows; i++)
    {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < Bcolumns; i++)
    {
        free(B[i]);
    }
    free(B);
    return 0;
}
