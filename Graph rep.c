#include<stdio.h>
#include<stdlib.h>
void directed();
void un_directed();
int read_graph(int adj_mat[50][50],int n);
void main()
{
    int ch;
    int check = 1;
    do
    {
        printf("Graph representations\n");
        printf("1.undirected graph\n");
        printf("2.directed graph\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            un_directed();
            break;
            case 2:
            directed();
            break;
            case 3:
            check = 0;
            printf("Exiting!......\n");
            break;
            default:
            printf("Enter the valid choice\n");
        }
    }while(check == 1);

}
void directed()
{
    int indeg,outdeg;
    int adj_mat[50][50],n,i,j;
    printf("ENter the number of vertices\n");
    scanf("%d",&n);
    read_graph(adj_mat,n);
    printf("\nVertex\t\tindeg\t\toutdeg\t\ttotaldeg\n");
    for(i=1;i<=n;i++)
    {
    	indeg = outdeg = 0;
        for(j=1;j<=n;j++)
        {
            if(adj_mat[j][i] == 1)
            {
                indeg ++;
            }
        }
         for(j=1;j<=n;j++)
        {
            if(adj_mat[i][j] == 1)
            {
                outdeg ++;
            }
        }
       	printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n",i,indeg,outdeg,indeg+outdeg);
    }
    return ;
}
void un_directed()
{
    
	int adj_mat[50][50];
	int deg, i, j, n;
	printf("\n How Many Vertices ? : ");
	scanf("%d", &n);
	read_graph(adj_mat, n);
	printf("\n Vertex \t Degree ");
	for ( i = 1 ; i <= n ; i++ ) 
	{
		deg = 0;
		for ( j = 1 ; j <= n ; j++ )
			if ( adj_mat[i][j] == 1)
				deg++;
		printf("\n\n %5d \t\t %d\n\n", i, deg);
	}
	return;
}
int read_graph(int adj_mat[50][50],int n)
{
	char reply;
	int i,j;
	for ( i = 1 ; i <= n ; i++ ) 
	{
		for ( j = 1 ; j <= n ; j++ ) 
		{
			if ( i == j )
			{
				adj_mat[i][j] = 0;
				continue;
			}
			printf("\n Vertices %d & %d are Adjacent ? (Y/N) :",i,j);
			scanf("%c", &reply);
			if ( reply == 'y' || reply == 'Y' )
				adj_mat[i][j] = 1;
			else
				adj_mat[i][j] = 0;
		}
	}
	return ;
}













