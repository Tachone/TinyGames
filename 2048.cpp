//2048  by Tach  
  
#include<iostream>  
#include<string>  
#include<ctime>  
#include<cstring>  
#include<conio.h>  
#include<iomanip>   
#include<algorithm>  
using namespace std;  
int g[4][4];  
int vis[4][4];  
int maxNum=0,score=0;  
void print()   //打印图案   
{  
    for(int i=0;i<4;i++)  
    {  
        for(int j=0;j<4;j++)  
        cout<<setw(5)<<g[i][j];  
        cout<<endl<<endl;  
    }   
    cout<<"Max:"<<maxNum<<"  "<<"Score:"<<score<<endl;  
}  
void init()  
{  
    for(int i=0;i<4;i++)  
    for(int j=0;j<4;j++)  
    g[i][j]=0;  
    memset(vis,0,sizeof(vis));  
    print();  
}  
bool GameOver()  //判断是是否还有空格   
{  
    bool flag=false;  
  
    for(int i=0;i<4;i++)  
    for(int j=0;j<4;j++)  
    {  
        if(vis[i][j]==0)  
        {  
          flag=true;  
          goto loop;  
        }  
    }  
    loop:  
    return flag;  
}  
  
bool GetResult() //判断是否出现2048   
{  
    for(int i=0;i<4;i++)  
    for(int j=0;j<4;j++)  
    {  
        if(g[i][j]==2048)  
        return true;  
    }  
}  
void RandNum(int f)  //随机生成2或者4，f代表需要生成的个数   
{  
    int num=0;  
    while(1)  
    {  
        int x=rand()%4;  
        int y=rand()%4;  
        if(vis[x][y]==0)  
        {  
            vis[x][y]=1;  
            int z=rand()%4+2;  
            if(z%2!=0)  
            z-=1;  
            g[x][y]=z;  
            num++;  
            if(num==f)  
            break;  
        }  
    }  
    system("cls");  
    print();  
}  
void work() //主函数，处理按键   
{  
    while(1)  
    {  
        int ch=getch();  
        if(ch==72)//上  
        {  
            for(int j=0;j<4;j++)  
            for(int i=0;i<4;i++)  
            {  
                if(vis[i][j]==1)  
                {  
                    for(int k=i-1;k>=0;k--)  
                    {  
                        if(vis[k][j]==1)  
                        {  
                            if(g[k][j]==g[k+1][j])  
                            {  
                                g[k][j]+=g[k][j];  
                                g[k+1][j]=0;  
                                vis[k+1][j]=0;  
                                maxNum=max(maxNum,g[k][j]);  
                                score+=g[k][j];  
                                break;  
                            }  
                            else  
                            break;  
                        }   
                        else  
                        {  
                             int temp=g[k][j];//类似冒泡  
                             g[k][j]=g[k+1][j];  
                             g[k+1][j]=temp;  
                             vis[k+1][j]=0;  
                             vis[k][j]=1;  
                        }  
                   }  
                }  
            }   
            RandNum(1);  
            system("cls");  
            print();  
            if(GameOver()==false)  
            {  
                cout<<"Game Over!!1"<<endl;  
                break;  
            }  
            if(GetResult()==true)  
            {  
                cout<<"You Win!!"<<endl;  
                break;  
            }  
       }  
         
        if(ch==80)//下   
        {  
            for(int j=0;j<4;j++)  
            for(int i=3;i>=0;i--)  
            {  
                if(vis[i][j]==1)  
                {  
                    for(int k=i+1;k<4;k++)  
                    {  
                        if(vis[k][j]==1)  
                        {  
                            if(g[k][j]==g[k-1][j])  
                            {  
                                g[k][j]+=g[k-1][j];  
                                g[k-1][j]=0;  
                                vis[k-1][j]=0;  
                                maxNum=max(maxNum,g[k][j]);  
                                score+=g[k][j];  
                                break;  
                            }  
                            else  
                            break;  
                        }   
                        else  
                        {  
                             int temp=g[k][j];  
                             g[k][j]=g[k-1][j];  
                             g[k-1][j]=temp;  
                             vis[k-1][j]=0;  
                             vis[k][j]=1;  
                        }  
                   }  
                }  
            }   
            RandNum(1);  
            system("cls");  
            print();  
            if(GameOver()==false)  
            {  
                cout<<"Game Over!!1"<<endl;  
                break;  
            }  
     
            if(GetResult()==true)  
            {  
                cout<<"You Win!!"<<endl;  
                break;  
            }  
       }  
         
             
        if(ch==75)//左   
        {  
            for(int i=0;i<4;i++)  
            for(int j=0;j<4;j++)  
            {  
                if(vis[i][j]==1)  
                {  
                    for(int k=j-1;k>=0;k--)  
                    {  
                        if(vis[i][k]==1)  
                        {  
                            if(g[i][k]==g[i][k+1])  
                            {  
                                g[i][k]+=g[i][k+1];  
                                g[i][k+1]=0;  
                                vis[i][k+1]=0;  
                                maxNum=max(maxNum,g[i][k]);  
                                score+=g[i][k];  
                                break;  
                            }  
                            else  
                            break;  
                        }   
                        else  
                        {  
                             int temp=g[i][k];  
                             g[i][k]=g[i][k+1];  
                             g[i][k+1]=temp;  
                             vis[i][k+1]=0;  
                             vis[i][k]=1;  
                        }  
                   }  
                }  
            }   
            RandNum(1);  
            system("cls");  
            print();  
            if(GameOver()==false)  
            {  
                cout<<"Game Over!!!"<<endl;  
                break;  
            }  
            if(GetResult()==true)  
            {  
                cout<<"You Win!!"<<endl;  
                break;  
            }  
       }  
         
         
         
        if(ch==77)//右   
        {  
            for(int i=0;i<4;i++)  
            for(int j=3;j>=0;j--)  
            {  
                if(vis[i][j]==1)  
                {  
                    for(int k=j+1;k<4;k++)  
                    {  
                        if(vis[i][k]==1)  
                        {  
                            if(g[i][k]==g[i][k-1])  
                            {  
                                g[i][k]+=g[i][k-1];  
                                g[i][k-1]=0;  
                                vis[i][k-1]=0;  
                                maxNum=max(maxNum,g[i][k]);  
                                score+=g[i][k];  
                                break;  
                            }  
                            else  
                            break;  
                        }   
                        else  
                        {  
                             int temp=g[i][k];  
                             g[i][k]=g[i][k-1];  
                             g[i][k-1]=temp;  
                             vis[i][k-1]=0;  
                             vis[i][k]=1;  
                        }  
                   }  
                }  
            }   
            RandNum(1);  
            system("cls");  
            print();  
            if(GameOver()==false)  
            {  
                cout<<"Game Over!!!"<<endl;  
                break;  
            }  
            if(GetResult()==true)  
            {  
                cout<<"You Win!!"<<endl;  
                break;  
            }  
       }  
   }  
}  
int main()  
{  
    init();  
    srand((unsigned)time(NULL));  
    RandNum(2);  
    work();  
    return 0;  
}   
