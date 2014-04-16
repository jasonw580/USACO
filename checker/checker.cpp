/*
ID: jasonw52
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int N;//读入的棋盘的大小
int C[15]={0};//表示第i行皇后的位置

ofstream fout ("checker.out");
ifstream fin ("checker.in");

//save the number of total answer
int rsum=0;
bool vis[3][255]={{false}};
void searchC(int cur){
    int i;
    if(N==cur){
        rsum++;
        if(rsum<=3){
            for(i=0;i<N-1;i++)
                fout<<C[i]<<" ";
            fout<<C[N-1]<<endl;
        }
    }
    else{
        for(i=0;i<N;i++){
        /*
            int ok=1;
            C[cur]=i;
            for(j=0;j<cur;j++){
                if(C[cur]==C[j] || cur-C[cur]==j-C[j] || cur+C[cur]==j+C[j]){
                    ok=0;
                    break;
                }
            }
            if(ok)
                searchC(cur+1);
        }
        */
            if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+N]){
                    C[cur]=i+1;
                    vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=1;
                    searchC(cur+1);
                    vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=0;
            }
        }
    }

}
int main() {
    fin >> N;
    searchC(0);
    fout << rsum << endl;
    return 0;
}
