//Nguyen Hoai Huy Dat | 63133655 | 63.CNTT-1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int p, q, n, e, d;

int randomPrimeLessThan50() {
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int size = sizeof(primes) / sizeof(primes[0]);
    int random = rand() % size;
    return primes[random]; 
}

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}


long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void bezout(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1; 
        *y = 0; 
        return;
    }
    int x1, y1;
    bezout(b, a % b, &x1, &y1);
    *x = y1; 
    *y = x1 - (a / b) * y1;
}

int modInverse(int e, int m) {
    int x, y;
    int gcdValue = gcd(e, m);
    
    if (gcdValue != 1) {
        printf("Khong tim thay nghich dao \n");
        return -1; 
    } else {
        bezout(e, m, &x, &y);
        return (x % m + m) % m;
    }
}

void edGen(int m){
	e=randomPrimeLessThan50();
    if(gcd(e, m) != 1)
    	edGen(m);
    d = modInverse(e, m);
    if(d == e || d % e != 1)
    	edGen(m);
}

void rsa(){
	n = p * q; 
    int m = (p - 1) * (q - 1);
    edGen(m);
}

int main() {
    printf("		MA HOA RSA\n");
    
    long long message, result;
    
    do{
    	printf("Nhap so nguyen to p: ");
    	scanf("%d", &p);
    	printf("Nhap so nguyen to q : ");
    	scanf("%d", &q);
	}
    while(is_prime(p) !=1 || is_prime(q) !=1);
	
    rsa();
    printf("RSA voi p = %d, q = %d, e = %d, d = %d\n", p, q, e, d);
    printf("Nhap thong diep can ma hoa (So nguyen): ");
    scanf("%lld", &message);
    result = power_mod(message, e, n);
    printf("Ket qua ma hoa: %lld\n",result);
    
    system("pause");
    return 0;
}

