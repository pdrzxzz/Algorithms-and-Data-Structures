#include <stdio.h>
#include <stdlib.h>
#define int long long int

void Swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int HoarePartition(int *A, int l, int r){
    int p = A[l];
    int i = l;
    int j = r+1;
    do{
    do {
        i++;
    } while((A[i]>p));
    do {
        j--;
    } while((A[j]<p));
    Swap(&A[i], &A[j]);
    } while(!(i >= j));
    Swap(&A[i], &A[j]);
    Swap(&A[l], &A[j]);
    return j;

}

void Quicksort(int *A, int l, int r){
    if(l<r){
        int s = HoarePartition(A,l,r);
        Quicksort(A, l, s-1);
        Quicksort(A, s+1, r);
    }
}


int main(){
    int num_of_chocolates, num_of_coupons, total=0;
    scanf("%lli", &num_of_chocolates);
    int chocolate_prices[num_of_chocolates];
    for(int i=0; i<num_of_chocolates; i++){
        scanf("%lli", &chocolate_prices[i]);
        total += chocolate_prices[i];
    }

    Quicksort(chocolate_prices, 0, num_of_chocolates-1); //Sorts

    scanf("%lli", &num_of_coupons);
    int coupom;
    for(int i=0; i<num_of_coupons; i++){
        scanf("%lli", &coupom);
        printf("%lli\n", total - chocolate_prices[coupom-1]);
    }

    return 0;
}
