//Nguyen Hoai Huy Dat | 63133655 | 63.CNTT-1

#include<stdio.h>
#include<string.h>
#include<cstdlib>

void dichCeasar(char a[],int k){
	printf("Truoc: ");
	for(int i=0;i<strlen(a);i++){
		if (a[i]-k<65)
			printf("%c",a[i]-k+26);
		else
			printf("%c",a[i]-k);
	}
	printf("\nSau:   ");
	for(int i=0;i<strlen(a);i++){
		if (a[i]+k>90)
			printf("%c",a[i]+k-26);
		else
			printf("%c",a[i]+k);
	}
}

void phaCeasar(){
	char c[1000];
	printf("Vui long viet in hoa cac ky tu cua ban ma\n");
	printf("Nhap ban ma: ");
	scanf("%s",&c);
	for(int i=1;i<=13;i++){
		printf("\n k = %d\n",i);
		dichCeasar(c,i);
	}
}

void maCeasar(){
	char p[1000];
	int k;
	printf("Vui long viet in hoa cac ky tu cua ban ro hoac ban ma\n");
	printf("Nhap ban ro hoac ban ma: ");
	scanf("%s",&p);
	printf("Nhap khoa k: ");
	scanf("%d",&k);
	dichCeasar(p,k);	
}

void ceasar(){
	printf("		MA HOA CEASAR\n");
	int c;
	printf("Chon chuc nang cho ma hoa Ceasar (Nhan cac so 1, 2)\n1. Ma hoa va giai ma\n2. Pha ma\n");
	scanf("%d",&c);
	switch(c){
		case 1: maCeasar(); break;
		case 2: phaCeasar(); break;
		default: {
			printf("Sai cu phap"); 
			ceasar();
		}
	}
}

int main(){
	ceasar();
	printf("\n");
 	system("pause");
	return 0;
}
//test 
// FOURSCOREANDYEARSAGO
// 3
// IRXUVFRUHDQGBHDUVDJR
