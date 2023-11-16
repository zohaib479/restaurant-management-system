#include <stdio.h>
#include <math.h>
#include <string.h>
static int seats[5][10]; // seating availability
void getorder(){
	char confirmation;
	float gst,gtotal;
	int biryani_price = 200;
	int total=0;
	int quantity1,quantity2,quantity3,quantity4,quantity5;
	int userorder=0;
	int nihari_price = 200;
	int pulao_price = 200;
	int karahi_price = 300;
	int haleem_price = 400;
	printf("\n\n\n\tWelcome to FAST canteen.\n\n");
	printf("The following is our menu: \n");
	printf("\n----------------------------------------------\n");
	printf("\n\nDescription \t\t|\t Price\n\n");
	printf("\n----------------------------------------------\n");
	printf("\nBiryani \t\t|\t %d",biryani_price);
	printf("\n\nPulao \t\t\t|\t %d",pulao_price);
	printf("\n\nKarahi \t\t\t|\t %d",karahi_price);
	printf("\n\nNihari \t\t\t|\t %d",nihari_price);
	printf("\n\nHaleem \t\t\t|\t %d\n",haleem_price);
	printf("\n----------------------------------------------\n");
	/*printf("\nItem Total: \t\t|\t%d",total);
	printf("\n\n\nG.S.T \t\t\t|\t%.1f",gst);
	printf("\n\n----------------------------------------------\n");
	printf("\n\nGrand Total \t\t|\t%.1f",gtotal);	*/
	printf("\n\n");



while(userorder != 6){
	printf("\n\nEnter item number of the dish you want to order: ");	
	scanf("%d",&userorder);
	switch(userorder){
		case 1:
			printf("\n\nYou have chosen Biryani, please sepcify your quantity: ");
			scanf("%d",&quantity1);
			printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
			total += biryani_price * quantity1;
			break;
		case 2:
			printf("\n\nYou have chosen Pulao, please sepcify your quantity: ");
			scanf("%d",&quantity2);
			printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
			total += pulao_price * quantity2;
			break;
		case 3:
			printf("\n\nYou have chosen Karahi, please sepcify your quantity: ");
			scanf("%d",&quantity3);
			printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
			total += karahi_price * quantity3;
			break;
		case 4:
			printf("\n\nYou have chosen Nihari, please sepcify your quantity: ");
			scanf("%d",&quantity4);
			printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
			total += nihari_price * quantity4;
			break;
		case 5:
			printf("\n\nYou have chosen Haleem, please sepcify your quantity: ");
			scanf("%d",&quantity5);
			printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
			total += haleem_price * quantity5;
			break;
		case 6:
			printf("\n\nOrder finished. Do you want to confirm and proceed with order(y) or cancel and re-order(n): ");
			scanf(" %c",&confirmation);
			if (confirmation == 'y'){
				break;	
			}
			
			else{
				printf("\n\n");
				getorder();   //recursion
			}
			
		
	}
}
	gst = 0.16 * total;
	gtotal = gst + total;
	printf("\nItem Total: \t\t|\t%d",total);
	printf("\n\n\nG.S.T: \t\t\t|\t%.1f",gst);
	printf("\n\n----------------------------------------------\n");
	printf("\n\nGrand Total: \t\t|\t%.1f",gtotal);	

}

void seating(){
	static int seats[5][10]; // seating availability
	int n,row,col;
	int x=0,y=0;
	//initializing seats
	for (x=0;x<5;x++){
		for (y=0;y<10;y++){
			seats[x][y] = 1;
		}
	}
	
	printf("\n\nEnter the amount of seats you want(n): ");
	scanf("%d",&n);
	
	// printing availability of seats
	for (x=0;x<5;x++){
		for (y=0;y<10;y++){
			printf(" %d ",seats[x][y]);
		}
		printf("\n");
	}
	
	for (y=0;y<n;y++){
		printf("Enter the row and column number you want to reserve(x)(y): ");
		scanf("%d%d",&row,&col);
		seats[row-1][col-1] = 0;
	}
	for (x=0;x<5;x++){
		for (y=0;y<10;y++){
			printf(" %d ",seats[x][y]);
		}
		printf("\n");
	}
	
}

int main()
{
	
	getorder();
	seating();
	
}