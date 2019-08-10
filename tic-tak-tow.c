#include<stdio.h>
#include<conio.h>
int result(char a[6][6])
{
    int r,i,j=1;
    for(r=1;r<=3;r++)
    {
        i = (r+(r-1));
        if((a[i][j] =='X'&& a[i][j+2] =='X'&& a[i][j+4] == 'X') ||(a[i][j] =='0'&& a[i][j+2] =='0'&& a[i][j+4] == '0') )
        {
            return 9;
        }

        if((a[j][i] =='X'&& a[j+2][i] == 'X'&& a[j+4][i] == 'X') ||(a[j][i] =='0'&& a[j+2][i] == '0'&& a[j+4][i] == '0'))
        {
            return 9;
        }
    }
    if(((a[1][1] =='X'&&a[5][5] =='X'&&a[3][3] =='X')||(a[1][5] =='X'&&a[3][3] =='X'&&a[5][1] == 'X'))
       ||((a[1][1] =='0'&&a[5][5] == '0'&&a[3][3]=='0')||(a[1][5] =='0'&&a[3][3] =='0'&&a[5][1] == '0')))
    {
        return 9;
    }
}
int main()
{
    int i,j,x=0,y,b,c,winner = 0,ch;
    char a[6][6];
    printf("Player 1 = X\n");
    printf("Player 2 = 0\n");
    for(i=1;i<6;i++)
    {
        for(j=1;j<6;j++)
        {
            if(i%2 != 0&&j%2 == 0)
            {
                a[i][j] = '|';
            }
            else if(i%2 == 0&&j%2 != 0)
            {
                a[i][j] = '-';
            }
            else if(i%2 == 0&&j%2 == 0)
            {
                a[i][j] = '+';
            }
            else
            {
                a[i][j] = NULL;
            }
        }
    }
    printf("\n");
    for(i = 1;i<6;i++)
    {
        printf("\t");
        for(j = 1;j<6;j++)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
        printf("\n");
    while(x < 9)
    {
        for(y=1;y<3;y++)
        {
            if(ch == 1 && y == 1)
            {
                y = 2;
                ch = 0;
            }
            printf("Player %d's turn\n",y);
            printf("Enter the row:\n");
            scanf("%d",&b);
            printf("Enter the column:\n");
            scanf("%d",&c);
            if((b>3||c>3))
            {
                printf("Invalid input\n");
                ch = 1;
                break;
            }
            if(a[(b+(b-1))][(c+(c-1))] == 'X' ||a[(b+(b-1))][(c+(c-1))] == '0')
            {
                printf("Place already consumed\n");
                ch = 1;
                break;
            }
            if(y == 1)
            {
                a[(b+(b-1))][(c+(c-1))] = 'X';
            }
            if(y == 2)
            {
                a[(b+(b-1))][(c+(c-1))] = '0';

            }
            printf("\n");
            for(i = 1;i<6;i++)
            {
                printf("\t");
                for(j = 1;j<6;j++)
                {
                    printf("%c",a[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            if((result(a)) == 9)
            {
                printf("Winner is player %d\n",y);
                winner = 1;
                break;
            }
            x++;
            if(x>=9)
            {
                break;
            }
        }

        if(winner == 1)
        {
            break;
        }
    }
    if (winner == 0)
    {
        printf("drew\n");
    }
    getch();
    return 0;
}
