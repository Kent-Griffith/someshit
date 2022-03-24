#include<iostream>
using namespace std;
int m;int n;
int a[100][100];
int max_len[100][100];
int dir[4][2]={
-1,0,//上方
0,1,//右方
1,0,//下方
0,-1//左方
};

int dfs(int x,int y){
int max=1;

for(int i=0;i<4;i++){
    int new_x=x+dir[i][0];
    int new_y=y+dir[i][1];
    if(new_x>=0&&new_x<m&&new_y>=0&&new_y<n&&a[x][y]>a[new_x][new_y]){
        int max_new=dfs(new_x,new_y)+1;
        if(max_new>max){
            max=max_new;
        }
    }

}
return max;
}


int main(){

while(cin>>m>>n){

int max_last=0;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
}
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        max_len[i][j]=dfs(i,j);
        if(max_len[i][j]>max_last){
            max_last=max_len[i][j];
        }
    }
}
cout<<max_last<<endl;


}
}

