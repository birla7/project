#include<stdio.h>
#include<conio.h>
void creat_chart(char *) ;
void move_fun(char,char,char *);
void evil_move_fun(char *);
void move_computer();
int cheaking_winner(char *);
void smart_computer();
void Evil_computer();
void play_with_palayer(char *);
void exit();
char arr []={'0','1','2','3','4','5','6','7','8','9'};
// Main Function
int main()
{
	
 play_again: 
    
	{
	int choice;
	char c,again;      // Menu Given
	printf("Enter your choice\n");
	printf("1.want to play with Smart computer\n");
	printf("2.want to play with Evil computer\n");
	printf("3.want to play with Player\n");
	printf("4.Exite\n");
	scanf("%d", &choice);

	switch (choice)
	{

	case 1: //for smart computer
        system("cls");		
        smart_computer(arr);
		break;
	case 2:  //For Evil computer
		system("cls");
		Evil_computer();
		break;

	case 3: //For play with friend 
		system("cls");
     	play_with_palayer(arr);
		break;

	case 4:  //For Exite the Game
           exit();
		break ;

	default:
		printf("Invalide key");
	}	
	printf("\n\nYou want to play again\n Enter 'y'or 'Y'");
	fflush(stdin);
	scanf("%c",&again);
	if(again=='y'||again=='Y')
	{
	goto play_again;// for playing again
    }
}
void exite(){
}
return 0;
}
// For creat the matrix
void creat_chart(char *arr)
{
	int i,j,n=1;
	for(i=0;i<3;i++)
	{
		for (j = 0; j < 3; j++)
			{
			  printf("   |");
			}
			printf("\n");
			for (j = 0; j < 3; j++)
			{
				printf(" %c |", *(arr + n));
				n++;
			}
			printf("\n");
			printf("___|___|___|\n");
		}
		printf("\n\n");
		printf("************************************************************\n");
	
}
void smart_computer()
{
	int i,move=0,result=0;
	int  key;
	char mark;
	char name[20];
	printf("enter your name\n");
	fflush(stdin);
	fgets(name, 20, stdin);
	printf("\n");
	for (i = 0; 1; i++)
	{
		if (!name[i])
		{
			printf("%c", name[i]);
			name[i - 1] = 0;
			break;
		}
    }
    printf("\n");
    while(1)
{
	
       system("cls"); // To clear screen
		printf("\n*********************** Tic Tac Toe *********************** \n");
		printf("First player %s  0\n", name);
		printf("Second player computer  X\n\n");
	creat_chart(arr);
	if(move%2==0) //For player 1
	{
		printf("%s",name);
		printf("enter marking place");
		fflush(stdin);
		scanf("%d",&key);
		if(key<0||key>9)
		printf("INVALID KEY");
		mark='0';
		printf("%c  %c",key,mark);
		move_fun(mark,key,arr);
		move++;
	}
	else  //For automatic player
	{
	  move_computer();
		move++;
		result=cheaking_winner( arr);//chack the result
		if(result==1)
		{
	    	system("cls");
			printf("\n\n");
			printf("%d",result);
			printf(" You Are lose");
			break;
		}
		if(result==5)
		{
			system("cls");
			printf("\n\n");
			printf(" Match Draw");
			break;
		
     	}
    }
  }
}
//For moving the value
void move_fun(char mark,char key,char *arr)
{
	*(arr+key)=mark;
}

void play_with_palayer(char *arr)
{
	char player_1[20],player_2[20];
	int move=1;
	int i, key,result=0;
	char mark;
	printf("Enter player 1 name   ");
	fflush(stdin);
	fgets(player_1,20,stdin);
	for (i = 0; 1; i++)
	{
		if (!player_1[i])
		{
			printf("%c", player_1[i]);
			player_1[i - 1] = 0;
			break;
		}
    }
	printf("Enter player 2 name  "); 
    fgets(player_2,20,stdin);
     for (i = 0; 1; i++)
	{
		if (!player_2[i])
		{
			printf("%c", player_2[i]);
			player_2[i - 1] = 0;
			break;
		}
    }
    while(1)
{
	
    system("cls"); // To clear screen
		printf("\n*********************** Tic Tac Toe *********************** \n");
		printf("First player %s  0 \n", player_1);
		printf("Second player %s  X\n\n\n",player_2);
		 
    
	creat_chart(arr);
	if(move%2)
	{
		printf("%s",player_1);
		printf("  Enter marking place");
		scanf("%d",&key);
		if(key<0||key>9)
		printf("INVALID KEY");
		mark='0';
		move_fun(mark,key,arr);
		move++;
		result=cheaking_winner( arr);
		if(result==1)
		{
			system("cls");
			printf("\n\n");
			printf("%s You Are Winner",player_1);
			break;
		}
		  
	}
	else
	{
		printf("%s",player_2);
		printf("  Enter marking place");
		scanf("%d",&key);
		if(key<0||key>9)
		printf("INVALID KEY");
		mark='X';
		move_fun(mark,key,arr);
		move++;
		result=cheaking_winner( arr);
		if(result==1)
		{
			system("cls");
			printf("\n\n");
			printf("%s You Are Winner",player_2);
			break;
		}
	}
	if(result==5)
	{
		system("cls");
		printf("You Lose Game");
		break;
	}
}
	
}
// chack the winner
int cheaking_winner(char *arr)
{
	    if((*(arr+1)==*(arr+2))&&(*(arr+2)==*(arr+3)))
	{
		return 1;
	}
		if((*(arr+4)==*(arr+5))&&(*(arr+5)==*(arr+6)))
	{
		return 1;
	}	if((*(arr+7)==*(arr+8))&&(*(arr+8)==*(arr+9)))
	{
		return 1;
	}	if((*(arr+1)==*(arr+4))&&(*(arr+4)==*(arr+7)))
	{
		return 1;
	}	if((*(arr+2)==*(arr+8))&&(*(arr+8)==*(arr+5)))
	{
		return 1;
	}	if((*(arr+3)==*(arr+6))&&(*(arr+6)==*(arr+9)))
	{
		return 1;
	}	if((*(arr+1)==*(arr+5))&&(*(arr+5)==*(arr+9)))
	{
		return 1;
	}	if((*(arr+3)==*(arr+5))&&(*(arr+5)==*(arr+7)))
	{
		return 1;
	}
	int count=0,i;
	for(i=1;i<=9;i++)
    {
    	if(*(arr+i)=='0'||*(arr+i)=='X')
    	{
    		count++;
		}
	}
	if(count==9)
	{
		return 5;
 	}
	
}
//for evil computer
void Evil_computer()
{
 int i,move=1;
	int key,result=0;
	int mark;
	char name[20];
	printf("enter your name\n");
	fflush(stdin);
	fgets(name, 20, stdin);
	printf("\n");
	for (i = 0; 1; i++)
	{
		if (!name[i])
		{
			printf("%c", name[i]);
			name[i - 1] = 0;
			break;
		}
    }
    printf("\n");
    while(1)
{
	
    system("cls"); // To clear screen
		printf("\n*********************** Tic Tac Toe *********************** \n");
		printf("First player %s  0\n", name);
		printf("Second player Evil  X\n\n");
	creat_chart(arr);
	if(move%2)
	{
		printf("%s",name);
		printf("  enter marking place");
		scanf("%d",&key);
		if(key<0||key>9)
		printf("INVALID KEY");
		mark='0';
		move_fun(mark,key,arr);
		move++;
		result=cheaking_winner( arr);
		if(result==1)
		{
			system("cls");
			printf("\n\n");
			printf("%s You Are Winner",name);
			break;
		}
	}
	else
	{
		evil_move_fun(arr);
		move++;
		result=cheaking_winner( arr);
		if(result==1)
		{
	    	system("cls");
			printf("\n\n");
			printf("%d",result);
			printf(" You Are lose");
			break;
		}
		if(result==5)
		{
			system("cls");
			printf("\n\n");
			printf(" Match Draw");
			break;
		
     	printf("Evil computer ");
		mark='X';
	}
    }
}
}
// for moving the value of ewil computer
void evil_move_fun(char *arr)
{	
int count=0;
  if(*(arr+4)== *(arr+7)||*(arr+5)== *(arr+9)||*(arr+2)== *(arr+3))
  {	
  if(*(arr+1)=='1')
  *(arr+1)='X';
  count++;
  }
  if(*(arr+7)==*(arr+8)||*(arr+1)==*(arr+5)||*(arr+3)==*(arr+6))
  {	
  if(*(arr+9)=='9')
  *(arr+9)='X';
  count++;
  }
  if(*(arr+1)==*(arr+3)||*(arr+5)==*(arr+8))
  {	
  if(*(arr+2)=='2')
  *(arr+2)='X';
  count++;
  }
  if(*(arr+5)==*(arr+6)||*(arr+1)==*(arr+7))
  {	
  if(*(arr+4)=='4')
  *(arr+4)='X';
  count++;
  }
  if(*(arr+3)==*(arr+7)||*(arr+1)==*(arr+9))
  {	
  if(*(arr+5)=='5')
  *(arr+5)='X';
  count++;
  }
  if(*(arr+4)==*(arr+5)||*(arr+3)==*(arr+9))
  {	
  if(*(arr+6)=='6')
  *(arr+6)='X';
  count++;
  }
  if(*(arr+1)==*(arr+4)||*(arr+8)==*(arr+9)||*(arr+5)==*(arr+3))
  {	
  if(*(arr+7)=='7')
  *(arr+7)='X';
  count++;
  }
  if(*(arr+7)==*(arr+9)||*(arr+2)==*(arr+5))
  {	
  if(*(arr+8)=='8')
  *(arr+8)='X';
  count++;
  }if(*(arr+1)==*(arr+2)||*(arr+7)==*(arr+5)||*(arr+6)==*(arr+9))
  {	
  if(*(arr+3)=='3')
  *(arr+3)='X';
  count++;
  }
  if(count==0)
  move_computer();
}
// for moving the  atuomatic computer
  void move_computer()
{
  
  {
  	if(*(arr+1)=='0'||*(arr+3)=='0'){
  	if(*(arr+2)=='2')
  	  *(arr+2)='X';
  	  else if(*(arr+5)=='5')
  	  *(arr+5)='X';
	  }
  	else if(*(arr+4)=='0'||*(arr+6)=='0')
  	{
  	if(*(arr+5)=='5')
  	  *(arr+5)='X';
  	  else if(*(arr+7)=='7')
  	  *(arr+7)='X';
  	  else if(*(arr+2)==0)
  	  *(arr+2)=='X';
	  }
  	else if(*(arr+7)=='0'||*(arr+9)=='0'){
  	if(*(arr+8)=='8')
  	  *(arr+8)='X';
  	  else if(*(arr+5)=='5')
  	  *(arr+5)='X';
	  }
  	else if(*(arr+1)=='0'||*(arr+7)=='0'){
  	if(*(arr+4)=='4')
  	  *(arr+4)='X';
  	  else if(*(arr+5)=='5')
  	  *(arr+5)='X';
	  }
  	else if(*(arr+2)=='0'||*(arr+8)=='0'){
  	if(*(arr+5)=='5')
  	  *(arr+5)='X';
  	  else if(*(arr+4)=='4')
  	  *(arr+4)='X';
  	  else if(*(arr+3)=='3')
  	  *(arr+3)='X';
  	  else if(*(arr+9)=='9')
  	  *(arr+9)='X';
	  }
  	else if(*(arr+3)=='0'||*(arr+9)=='0'){
  	if(*(arr+6)=='6')
  	  *(arr+6)='X';
  	  else if(*(arr+5)=='5')
  	  *(arr+5)='X';
	  }
  	else if(*(arr+5)=='0'||*(arr+4)=='0'){
   if(*(arr+3)=='3')
  	*(arr+3)='X';
  	else if(*(arr+9)=='9')
  	*(arr+9)='X';
  	else if(*(arr+6)=='6')
  	*(arr+6)='X';
  }
}
}
