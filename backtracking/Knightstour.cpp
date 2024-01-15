#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define N 8

void displayBoard(int sol[N][N]){
    for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			cout << " " << sol[i][j] << " "; 
		cout << endl; 
	} 
}

bool isSafe(int x, int y, int sol[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1); 
}


int solve(int x, int y, int move ,int sol[N][N], int rmove[8], int cmove[8]){

    int next_x,next_y;
    int k;

    if(move == N*N){
        return 1;
    }

    for(k=0;k<8;k++){
        next_x = x + rmove[k];
        next_y = y + cmove[k];
        if(isSafe(next_x,next_y,sol)){
            sol[next_x][next_y]=move;
            if(solve(next_x,next_y,move+1,sol,rmove,cmove)==1){
                return 1;
            }
            else{
                sol[next_x][next_y]=-1; //backtrack
            }
        }

    }
    return 0;

}


int knightstour(){
    int sol[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sol[i][j]=-1;
        }
    }

    int rmove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
	int cmove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

	sol[0][0] = 0;      //Knight is initially at the first block 


    if(solve(0,0,1,sol,rmove,cmove)==0){
       cout<<"Solution doesnt exist."<<endl;
       return 0;
    }
    else{
        displayBoard(sol);
    }

    return 1;
}


int main(){
    knightstour();
    return 0;
}