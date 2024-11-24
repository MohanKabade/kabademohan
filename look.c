#include <stdio.h>
#include <stdlib.h>

// Function to sort the disk requests
void sortRequests(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to implement CLOOK Disk Scheduling Algorithm
void CLOOK(int requests[], int n, int head) {
    int totalSeekTime = 0;
    int seekSequence[n];
    int count = 0;

    // Sort the requests
    sortRequests(requests, n);

    // Find the position of head in sorted array
    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    // Move to the right (higher track numbers)
    for (int i = index; i < n; i++) {
        totalSeekTime += abs(requests[i] - head);
        head = requests[i];
        seekSequence[count++] = head;
    }

    // Jump to the lowest request
    totalSeekTime += abs(requests[0] - head);
    head = requests[0];
    seekSequence[count++] = head;

    // Move to the right again (from lowest to head position)
    for (int i = 1; i < index; i++) {
        totalSeekTime += abs(requests[i] - head);
        head = requests[i];
        seekSequence[count++] = head;
    }

    // Output the seek sequence
    printf("Seek Sequence: \n");
    for (int i = 0; i < count; i++) {
        printf("%d -> ", seekSequence[i]);
    }
    printf("\nTotal Seek Time: %d\n", totalSeekTime);
    printf("Average Seek Time: %.2f\n", (float)totalSeekTime / n);
}

int main() {
    int n, head;

    // Get the number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    // Get the requests from the user
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    // Get the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    // Perform CLOOK Disk Scheduling
    CLOOK(requests, n, head);
    
    return 0;
}
