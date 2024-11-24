#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to implement SCAN Disk Scheduling Algorithm
void SCAN(int requests[], int n, int head, int disk_size, char direction[]) {
    int totalSeekTime = 0;
    int seekSequence[n + 1]; // To store the seek sequence
    int count = 0;

    // Sort the requests
    sortRequests(requests, n);

    // Finding the head position in the sorted array
    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    // Move toward the specified direction
    if (direction[0] == 'r' || direction[0] == 'R') { // Moving towards right (higher values)
        // Service the requests to the right of the head
        for (int i = index; i < n; i++) {
            totalSeekTime += abs(requests[i] - head);
            head = requests[i];
            seekSequence[count++] = head;
        }
        // If head reaches the end of the disk, go to the maximum track
        if (head < disk_size - 1) {
            totalSeekTime += abs(disk_size - 1 - head);  // Move to the end of the disk
            head = disk_size - 1;
            seekSequence[count++] = head;
        }
        // Now, service the requests on the left side (reverse direction)
        for (int i = index - 1; i >= 0; i--) {
            totalSeekTime += abs(requests[i] - head);
            head = requests[i];
            seekSequence[count++] = head;
        }
    } else { // Moving towards left (lower values)
        // Service the requests to the left of the head
        for (int i = index - 1; i >= 0; i--) {
            totalSeekTime += abs(requests[i] - head);
            head = requests[i];
            seekSequence[count++] = head;
        }
        // If head reaches the start of the disk, go to track 0
        if (head > 0) {
            totalSeekTime += abs(0 - head);  // Move to the start of the disk
            head = 0;
            seekSequence[count++] = head;
        }
        // Now, service the requests on the right side (reverse direction)
        for (int i = index; i < n; i++) {
            totalSeekTime += abs(requests[i] - head);
            head = requests[i];
            seekSequence[count++] = head;
        }
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
    int n, head, disk_size;
    char direction[10];

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
    
    // Get the disk size
    printf("Enter the disk size (maximum track number): ");
    scanf("%d", &disk_size);
    
    // Get the direction
    printf("Enter the direction (left or right): ");
    scanf("%s", direction);
    
    // Perform SCAN Disk Scheduling
    SCAN(requests, n, head, disk_size, direction);
    
    return 0;
}
