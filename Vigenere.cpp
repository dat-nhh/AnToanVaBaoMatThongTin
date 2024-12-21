//Nguyen Hoai Huy Dat | 63133655 | 63.CNTT-1

#include<stdio.h>
#include<string.h>
#include<cstdlib>

void giaiVige(){
	char a[1000];
	char s[1000];
	char k[1000];
	printf("Vui long viet in hoa cac ky tu cua ban ma va khoa\n");
	printf("Nhap ban ma: ");
	scanf("%s",&a);
	printf("Nhap khoa k: ");
	scanf("%s",&s);
	strcpy(k,s);
	while(strlen(k)<strlen(a)){
		strcat(k,s);
	}
	printf("Ket qua: ");
	for(int i=0;i<strlen(a);i++){
		printf("%c",'A'+ (((int) a[i]) - ((int) k[i]) + 26)%26);
	}
}

void maVige(){
	char a[1000];
	char s[1000];
	char k[1000];
	printf("Vui long viet in hoa cac ky tu cua ban ro va khoa\n");
	printf("Nhap ban ro: ");
	scanf("%s",&a);
	printf("Nhap khoa k: ");
	scanf("%s",&s);
	strcpy(k,s);
	while(strlen(k)<strlen(a)){
		strcat(k,s);
	}
	printf("Ket qua: ");
	for(int i=0;i<strlen(a);i++){
		printf("%c",'A'+(((int) a[i]) + ((int) k[i]))%26);
	}
}

void vigenere(){
	printf("		MA HOA VIGENERE\n");
	int c;
	printf("Chon chuc nang cho ma hoa Vigenere (Nhan cac so 1, 2)\n1. Ma hoa \n2. Giai ma\n");
	scanf("%d",&c);
	switch(c){
		case 1: maVige(); break;
		case 2: giaiVige(); break;
		default: {
			printf("Sai cu phap"); 
			vigenere();
		}
	}
}

int main(){
	vigenere();
	printf("\n");
 	system("pause");
	return 0;
}
//test
// WEAREDISCOVEREDSAVEYOURSELF
// DECEPTIVE
// ZICVTWQNGRZGVTWAVZHCQYGLMGJ
