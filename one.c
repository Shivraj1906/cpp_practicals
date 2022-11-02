#include<stdio.h>
#define MAX 100

void input_data(int a[], int length) {
    for(int i = 0; i < length; i++) {
        scanf("%d", &a[i]);
    }
}

void print(int a[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
}

//Passing address of length because we need to update the length after insertion
void insert(int a[], int *length, int index, int value) {
    //shift down all elements until we reach the index
    for(int i = *length - 1; i >= index; i--) {
        a[i + 1] = a[i];
    }

    a[index] = value;

    (*length)++;
}

void delete(int a[], int* length, int index) {
    //shift up all elements upto given index, Thus overriding element at given index
    for(int i = index + 1; i < *length; i++) {
        a[i - 1] = a[i];
    }

    (*length)--;
}

// return the index of max element
int find_max(int a[], int length) {
    int max = 0;

    for(int i = 1; i < length; i++) {
        if(a[i] > a[max])
            max = i;
    }

    return max;
}

int main() {
    int a[MAX];
    int length;

    printf("Enter the length: ");
    scanf("%d", &length);

    input_data(a, length);

    insert(a, &length, 1, 1);
    delete(a, &length, 1);
    print(a, length);

    printf("max element a[%d]: %d\n", find_max(a, length), a[find_max(a, length)]);

    return 0;
}