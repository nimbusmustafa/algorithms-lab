#include<stdio.h>
#include<stdlib.h>


void heapify(int *arr, int n, int i){
    int k=i;
    int v=arr[k];
    int heap=0;

    while(!heap && 2*k<=n){
        int j=2*k;
        if(j<n && arr[j]<arr[j+1]){
            j=j+1;
        }
        if(v>=arr[j])
        heap=1;
        else{
            arr[k]=arr[j];
k=j     ;   }
    }

arr[k]=v;
}
void build_heap(int *arr, int n){
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
}

void print_heap(int *arr, int n){
    for(int i=1;i<=n;i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

void heapify_td(int *arr, int i){
    int parent=i/2;
    while(parent>0 && arr[i]>arr[parent]){
        int temp =arr[i];
        arr[i]=arr[parent];
        arr[parent]=temp;
        i=parent;
        parent=i/2;
    }

}

void heapsort(int *arr, int n){
    build_heap(arr,n);
printf("Original heap ");
    print_heap(arr,n);

        for (int i = n; i >= 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapify(arr, i - 1, 1);
    }

}
int main(){
    int n;
    printf("\nEnter no of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n+1 * sizeof(int));
    for(int i=1;i<=n;i++){
        printf("\nEnter element %d: ", i);
        scanf("%d", &arr[i]);
        // heapify_td(arr, i);  

    }
    // build_heap(arr,n);
    heapsort(arr, n);
    print_heap(arr,n);
    return 0;
}