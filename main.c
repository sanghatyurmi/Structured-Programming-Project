//Name: Sanghaty Paul
//ID: 0182420012101427
//Batch: 64-D
//Department: Computer Science and Engineering
#include <stdio.h>
// Function prototypes
void insert(int arr[], int *size, int value, int position);
void update(int arr[], int size, int position, int newValue);
void delete(int arr[], int *size, int position);
void sort(int arr[], int size);
int search(int arr[], int size, int value);
void display(int arr[], int size);

int main() {
    int arr[100], size = 0, choice, value, position;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Insert\n2. Update\n3. Delete\n4. Sort\n5. Search\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &position);
                insert(arr, &size, value, position);
                break;
            case 2:
                printf("Enter position and new value: ");
                scanf("%d%d", &position, &value);
                update(arr, size, position, value);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(arr, &size, position);
                break;
            case 4:
                sort(arr, size);
                printf("Array sorted.\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                position = search(arr, size, value);
                if (position != -1)
                    printf("Value found at position: %d\n", position);
                else
                    printf("Value not found.\n");
                break;
            case 6:
                display(arr, size);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

// Insert element at a given position
void insert(int arr[], int *size, int value, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *size; i > position; i--)
        arr[i] = arr[i - 1];
    arr[position] = value;
    (*size)++;
}

// Update an element at a given position
void update(int arr[], int size, int position, int newValue) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return;
    }
    arr[position] = newValue;
}

// Delete an element from a given position
void delete(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];
    (*size)--;
}

// Sort the array using Bubble Sort
void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Search for an element in the array
int search(int arr[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (arr[i] == value)
            return i;
    return -1;
}

// Display the array elements
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
