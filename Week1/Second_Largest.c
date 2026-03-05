#include <stdio.h>
int main() {
    int arr[100], n, i, j, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, secMax;

if (arr[0] > arr[1]) {
    max = arr[0];
    secMax = arr[1];
} else {
    max = arr[1];
    secMax = arr[0];
}

for (int i = 2; i < n; i++) {
    if (arr[i] > max) {
        secMax = max;
        max = arr[i];
    }
    else if (arr[i] > secMax && arr[i] != max) {
        secMax = arr[i];
    }
}
printf("Second largest element: %d",secMax);
    return 0;
}
