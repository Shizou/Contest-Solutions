#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

vector< pair< int,int > > yodellers;
vector< pair< int,int > > scores;
int rank;

int main(){
    //freopen("input.txt","r",stdin);
    int n,r; cin >> n >> r;

    for(int i = 0;i < n;i++){
        yodellers.push_back(make_pair (0,0));
        scores.push_back(make_pair (0,i+1));
    }
    int s = 0;
    for(int i = 0;i < r;i++ ){
        for(int j = 0;j < n;j++){
            cin >> s;
            yodellers.at(j).first += s;
        }
        for(int a = 0;a < n;a++){
            rank = 1;
            for(int j = a+1;j < n;j++){
                if(yodellers.at(j).first >  yodellers.at(a).first){
                    rank++;
                }
            }
            for(int j = a-1;j >= 0;j--){
                if(yodellers.at(j).first > yodellers.at(a).first){
                    rank++;
                }
            }

           scores.at(a).first = rank;
        }
        for(int j = 0;j < n;j++){
                if(scores.at(j).first >  yodellers.at(j).second){
                    yodellers.at(j).second = scores.at(j).first;
                }
        }
    }
    sort(yodellers.begin(),yodellers.end());
    sort(scores.begin(),scores.end());
    n--;
    printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",scores.at(0).second, yodellers.at(n).first, yodellers.at(n).second);

    for(int j = 1;j <= n;j++){
        if(scores.at(j).first == scores.at(0).first){
            printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",scores.at(j).second, yodellers.at(n-j).first, yodellers.at(n-j).second);
        }
        else
            break;
    }
    //fclose(stdin);
    return 0;
}

