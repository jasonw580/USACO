/*
ID: jasonw52
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int date_in[50][50];
int date_tem[50][50];
int rcount=0;
int Max=0;
vector<int> allres;
//search & tag
int area=0;
void search_tag(int row, int column){
    if(date_tem[row][column] != 0)
        return ;
    date_tem[row][column] = 1+rcount;
    area++;
    //search West
    if(0 != (date_in[row][column]&1)){search_tag(row,column-1);}
    //search North
    if(0 != (date_in[row][column]&2)){search_tag(row-1,column);}
    //search East
    if(0 != (date_in[row][column]&4)){ search_tag(row,column+1);}
    //search South
    if(0 != (date_in[row][column]&8)){search_tag(row+1,column);}
}
//Search The WALL
int wall[1][1][1];
typedef struct{
    int a;
    int b;
    int areasum;
}connect;
void searchwall(int N,int M){
    connect n[];
    int acount=0;
    //find connection horizontally
    for(int h = 0;h < M;h++){
        for(int v = 0;v < N-1;v++){
            if(date_tem[h][v] != date_tem[h][v+1]){
                for(int p = 0;p < acount;p++){
                    if(){
                        //
                    }
                }
                acout++;
            }
        }
    }
    //find connection vertically
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    int N;//Length or Column
    int M;//Wide or Row
    fin >> N >> M;

    //read date
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            fin >> date_in[i][j];
            date_in[i][j] = 15 -date_in[i][j];
            date_tem[i][j] = 0;
        }
    }
    //ergod 遍历
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            if(date_tem[i][j]==0){
                search_tag(i,j);
                rcount++;
                Max=(Max>area)?Max:area;
                allres.push_back(area);
                area=0;
            }
        }
    }

    cout << rcount << endl;
    cout<< Max << endl;
    //test
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            cout << date_tem[i][j] << " ";
        }
        cout << endl;
    }
    for(unsigned int i = 0;i < allres.size();i++)
        cout << i+1 << ":" << allres[i]<<endl;
    //end test
    return 0;
}
