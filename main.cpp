#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include"payload.h"
using namespace std;

#define MAX_I		27
#define MAX_J		96
#define SLEEP_US	50000
const int FRAMES=694;
const char* SEG_TABLE="#RMNHQODBWGPZ*@$C&98?32I1>!:-;. ";
void out_mat(int fr){
	for(int i=0;i<MAX_I;i++){
		for(int j=0;j<MAX_J;j++){
			char data=payload[fr][i][j];
			char content=SEG_TABLE[data];
			cout<<content;
		}
		cout<<endl;
	}
}

void disp(){
	int i=0;
	for(int i=0;i<FRAMES;i++){
		//cursor move
		cout<<"\33[0;0H";
		//output
		out_mat(i);
		fflush(stdout);
		usleep(SLEEP_US);
	}
}

int main(){
	cout<<"\033[2J";
	disp();
	return 0;
}
