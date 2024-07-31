#include <stdio.h>
#include <stdlib.h>

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

int abs(n){
    unsigned int n2 = n;
    return n2;
}

void BinarySearch(int *A, int i, int l, int r, int k, int *counter){
    if(l<=r){//5  4  3  2  1
           //[0][1][2][3][4]
            int m = (l+r)/2;
            unsigned int n = abs(A[i] - A[m]);
            if(n == k) {
                (*counter)++;
            }
            else if(n > k) {
                    BinarySearch(A, i, l, m-1, k, counter);
                    }
            else {
                    BinarySearch(A, i, m+1, r, k, counter);
            }
        }
}

int main()
{
    int n, k, counter=0;
    scanf("%i %i", &n, &k);
    int nums[n];
    for(int i=0; i<n; i++){
        scanf("%i", &nums[i]);
    }
    Quicksort(nums, 0, n-1);
    for(int i=0; i<n-1; i++){
        BinarySearch(nums, i, i+1, n-1, k, &counter);
    }
    printf("%i", counter);
    system("pause");
    return 0;
}
