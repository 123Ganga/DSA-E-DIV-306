#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct players
{
    char player_name[20],team_name[10],odi_rank[10];
    int runs,centuries;
}P;

void read_players(P *plr,int n)
{
    int i;
    printf("Enter player name,team name,odi rank,runs,centuries\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%d%d",plr->player_name,plr->team_name,plr->odi_rank,&plr->runs,&plr->centuries);
        plr++;
    }
}
void display_players(P *plr,int n)
{
     int i;
     printf("BCR Team Details\n");
    printf("player name\tteam name\todi rank\truns\tcenturies\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%s\t%s\t%d\t%d\n",plr->player_name,plr->team_name,plr->odi_rank,plr->runs,plr->centuries);
        plr++;
    }

}
// sort in descending order
void sort_players(P *plr,int n)
{
    int i,min_index,j;
    P temp;
    for(i=0;i<n-1;i++)
    {
      min_index=i;
      for(j=i+1;j<n;j++)
      {
          if((plr+j)->runs>(plr+min_index)->runs)
          {
              min_index=j;
          }
      }
      temp=*(plr+i);
      *(plr+i)=*(plr+min_index);
      *(plr+min_index)=temp;

    }
    // To display the least run scorer player.
     printf("%s\t%s\t%s\t%d\t%d\n",(plr+n-1)->player_name,(plr+n-1)->team_name,(plr+n-1)->odi_rank,(plr+n-1)->runs,(plr+n-1)->centuries);


}
// To display top 3 players
void dis_sort(P *plr,int n)
{
    int i;

    for(i=0;i<3;i++)
    {
        printf("%s\t%s\t%s\t%d\t%d\n",plr->player_name,plr->team_name,plr->odi_rank,plr->runs,plr->centuries);
        plr++;
    }


}
// To search player Rajat
void search_player(P *plr,int n)
{
    int i,status=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(plr->player_name,"Rajat")==0)
        {
            status=1;
            break;
        }
        plr++;
    }
    if(status==1)
    {
        printf("%s\t%s\t%s\t%d\t%d\n",plr->player_name,plr->team_name,plr->odi_rank,plr->runs,plr->centuries);
    }
    else
        printf("Rajat not found in BCR team\n");

}
int main()
{
    P *plr;
    int n;
     printf("Enter num of players\n");
    scanf("%d",&n);
    plr=(P*)malloc(n*sizeof(P));
    read_players(plr,n);
    display_players(plr,n);
    printf("Selected Team Players are\n");
    sort_players(plr,n);
    dis_sort(plr,n);
    search_player(plr,n);
    free(plr);
    return 0;
}




