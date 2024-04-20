#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
void position(int a[]){ //i take random numbers in range [1,16] which means inside of borders.
	a[0]=(rand()%16)+1;
	a[1]=(rand()%16)+1;
	a[2]=(rand()%16)+1;
	a[3]=(rand()%16)+1;
	
}

int main(){
	int x=1; //the checker for play again
	while (x==1){
	
		srand(time(NULL));//i fixed the seed of function rand().. to avoid memorising the rotations and varify them.
		const int e1=7; //the escape point has  constant index values.
		const int e2=1;
		int a[4]={1,2,3,4}; //an array to call position function
		int m1,m2,t1,t2;//the position of monster(m) and thief(t), 1 refers horizontal(column) 2 refers vertical(line) position.
		
		
		
		
		
		char port[18][18]=//this is the game port that i can arrange the position of walls. it is a two-dimentional array.
	
					  {{'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'},
					   {'-','0','0','0','0','0','0','0','0','|','0','0','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','0','0','|','0','0','0','0','0','0','0','-'},
					   {'-','0','0','|','0','0','0','0','|','|','|','0','0','0','|','0','0','-'},
					   {'-','0','0','|','0','0','0','0','0','0','0','0','0','0','|','0','0','-'},
					   {'-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','|','|','|','0','0','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','|','0','0','0','0','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-'},    //i wanted to put zeroes in order to make 
					   {'-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-'},	// the port look better. 
					   {'-','0','0','0','|','|','|','0','0','0','0','|','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','|','0','0','0','0','|','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','0','0','0','0','|','0','0','0','0','0','-'},
					   {'-','0','0','|','0','0','0','0','0','0','0','|','|','0','0','0','0','-'},
					   {'-','0','0','|','0','0','0','0','0','0','0','0','0','0','0','0','0','-'},
					   {'-','0','0','|','|','|','0','0','0','0','0','0','0','0','0','0','0','-'},
					   {'-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','-'},
					   {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}};
		
		while(true){//here i placed W and T on zeroes. the conditions are unnecessaryly long but i wanted to work on operators.
			position(a);
			if (fabs(a[0]-a[2])+fabs(a[1]-a[3])>=16){  // i used the fabs() <math.h> function to get absolute values in order to calculate the distance
				m1=a[0];
				m2=a[1];
				t1=a[2];
				t2=a[3];
				if(port[t1][t2]!='-'&&port[t1][t2]!='|'&&port[t1][t2]!='E'&&port[m1][m2]!='|'&&port[m1][m2]!='-'&&port[m1][m2]!='E'){
				
				
					break;
				}
			}
		}
		void print(){ //function to print the port.
		//these 2 for loops are printing the port in the correct order.
		for (int i=0;i<18;i++){
			for(int j=0;j<18;j++){
				printf("%c ", port[i][j]);
			}
		    
			printf("\n");
			
		}
	    }
	    port[e1][e2]='E'; //demonstrating the important points at the port.
	    port[m1][m2]='W';
	    port[t1][t2]='T';
	    
		
		char p;// an input value  that player will chose to rotate 'T'
		int ece[2]={0,0}; //this is an array to be able to call a rotating function of monster. the values are random and do not mean anything.
		int monsterE(int ece[],int m,int n){ //monsterE is a function for easy mode and decides the next position of 'W'
			int a=rand()%2; //i make the monster  decide whether it will move horizontally or vertically. 0 stands for vertical,1 stands for horizontal.
			int a_value=rand()%2;//than i randomly chose 0 or 1 again. it is about the displacement. 0 means-1 and 1 means 1.. 
			if (a_value==0){ // i stablise the values. For example if a_value is 1 and a is 0, than it will go one line below which means a 'down' command.
				a_value=-1; 
			}
			if(a==0){
				m+=a_value;
				ece[0]=m;       //i keep the position values in an array to be able to use them 
				
			}else{
				n+=a_value;
				ece[1]=n;
				
			}
			return 0;
		}
		
		//scenario begins
		
		print();
		printf("Welcome to the game! you are represented as T on the port. Try to reach 'E' point before monster (W) catches you\n To move up, press u\n To move down, press d\n To move left, press l\n To move right press r :)\n ");
							
		//THE MAÝN LOOP IS DOWN BELOW
		
		while (true){
		
			port[t1][t2]='0'; //DELETING THE PREVIOUS POSITIONS 
			port[m1][m2]='0';
			while (true){//JUST TO GET THE GAMER'S CHOICE
				printf("make your move \n");
				scanf(" %c",&p);
				if (p=='u'){
						t1-=1;
						if (port[t1][t2]=='-'||port[t1][t2]=='|'){ //to warn the failing  moves.
							printf("You cant move on walls(|) and boundaries(-) chose again please.\n");
							t1++; //to fix the previous operation.
						}else
							break;
					}else if (p=='d'){
						t1+=1;
						if (port[t1][t2]=='-'||port[t1][t2]=='|'){
							printf("You cant move on walls(|) and boundaries(-) chose again please.\n");
							t1--;
						}else
							break;
					}else if (p=='r'){
						t2+=1;
						if (port[t1][t2]=='-'||port[t1][t2]=='|'){
							printf("You cant move on walls(|) and boundaries(-) chose again please.\n");
							t2--;
						}else
							break;
					}else if (p=='l'){
						t2-=1;
						if (port[t1][t2]=='-'||port[t1][t2]=='|'){
							printf("You cant move on walls(|) and boundaries(-) chose again please.\n");
							t2++;
						}else
							break;
					}else if(p!='u'&&p!='d'&&p!='r'&&p!='l'){
						printf("please make sure that you  chose one of the options as : u,d,r,l\n");
					}
				}
			
			
			port[t1][t2]='T'; //placing the thief.
			int a=m1,b=m2;
			do{
				
				m1=a;
				m2=b;
				monsterE(ece,m1,m2);//positioning the monster
				m1=ece[0];															//forcing monster to stay in boarders and avoid walls.
				m2=ece[1];
				
				
			}while(port[m1][m2]=='-'||port[m1][m2]=='|'||port[m1][m2]=='E')	;
			
			//i take the outputs of monsterE function and assign them to monster's location values.
			port[m1][m2]='W';
			if(t1==e1&&t2==e2){
				printf("YOU WON!!!\n");
				
				printf("Do you want to play again? press 1 to say yes, press anything other to say no\n");
				scanf("%d",&x);
				system("CLS");
				break;
				
			}else if(m1==t1&&m2==t2){
				printf("YOU LOST!!\n");
				printf("Do you want to play again? press 1 to say yes, press anything other to say no \n");
				scanf("%d",&x);
				system("CLS");
				break;
				
			}else{
				system("CLS");//to clear console while refreshing.
				print();
			}
		}
	}
				
		
		
		
		
			  
	
		return 0;
	} 
