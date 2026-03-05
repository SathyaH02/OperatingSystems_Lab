#include <stdio.h>
int main()
{
    int n, arr[100];
    printf("Enter no.of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int min=arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
        }
    }
    printf("Minimum element in the array: %d",min);
    return 0;
}
