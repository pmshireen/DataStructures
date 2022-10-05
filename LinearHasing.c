#include<stdio.h>
#include<stdlib.h>
# define Table_size 10
int head[Table_size] = {NULL};
void insert()
{
    int index,i,key,hkey,flag = 0;
    printf("Enter the key\n");
    scanf("%d",&key);
    hkey = (key%Table_size);
    for(i=0;i<Table_size;i++)
    {
        index = (hkey+i)%Table_size;
        if(head[index] == NULL)
        {
            head[index] = key;
            break;
        }
    }
    if(i == Table_size)
    printf("element caanot be inserted\n");
}
void search()
{
    int index,i,key,hkey,flag = 0;
    printf("Enter the key\n");
    scanf("%d",&key);
    hkey = (key%Table_size);
    for(i=0;i<Table_size;i++)
    {
        index = (hkey+i)%Table_size;
        if(head[index] == key)
        {
            printf("Element found at %d\n",index);
            break;
        }
    }
    if(i == Table_size)
    printf("element caanot be inserted\n");
}
void delete()
{
    int index,i,key,hkey,flag = 0;
    printf("Enter the key\n");
    scanf("%d",&key);
    hkey = (key%Table_size);
    for(i=0;i<Table_size;i++)
    {
        index = (hkey+i)%Table_size;
        if(head[index]== key)
        {
            head[index] = NULL;
            break;
        }
    }
    if(i == Table_size)
    printf("element caanot be inserted\n");
}
void display()
{
    int i;
   printf("\nelements in the hash table are \n");
  for(i=0;i<Table_size; i++)
    printf("\nat index %d \t value =  %d",i,head[i]);
}
void main()
{
    int ch,check =1;
    do
    {
        printf("1.Insert\n2.Search\n3.delete\n4.display\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:search();break;
            case 3:delete();break;
            case 4:display();break;
            case 5:check = 0;
                   printf("Exiting!......\n");
                   break;
            default:printf("Enter the valid choice\n");
        }
    }while(check == 1);
}
