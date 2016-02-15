#include<stdio.h>

int N,K,P;

int g[100][100];
int g2[100][100];
int g3[100][100];


int sum(int r, int c){
    int s = 0;
    for(int i = 0;i < N;i++){
        s+= g[r][i]*g2[i][c];
    }
    return s;
}
int m(){
    P = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            g3[i][j] = sum(i,j);
            P+=g3[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            g2[i][j] = g3[i][j];
        }
    }

}

int main(){
    freopen("input.txt","r",stdin);
    scanf("%d%d",&N,&K);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            scanf("%d",&g[i][j]);
            g3[i][j] = g2[i][j] = g[i][j];
            P+=g3[i][j];
        }
    }
    while(--K)m();
    printf("%d\n",P);
    //fclose(stdin);
}
