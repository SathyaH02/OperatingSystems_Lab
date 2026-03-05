#include <stdio.h>
int main() {
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Position of element to be deleted: ");
    scanf("%d",&key);

    for (int i=key; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}
