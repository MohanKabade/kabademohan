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

// Function to implement CSCAN Disk Scheduling Algorithm
void CSCAN(int requests[], int n, int head, int disk_size) {
    int totalSeekTime = 0;
    int seekSequence[n + 2]; // To store the seek sequence
    int count = 0;

    // Sort the requests
    sortRequests(requests, n);

    // Finding the head position in the sorted array
    int index = 0;
    while (index < n && requests[index] < head) {
        index++;
    }

    // Service the requests to the right of the head (including the end)
    for (int i = index; i < n; i++) {
        totalSeekTime += abs(requests[i] - head);
        head = requests[i];
        seekSequence[count++] = head;
    }

    // Jump to the end of the disk (disk_size - 1) if not already there
    if (head != disk_size - 1) {
        totalSeekTime += abs(disk_size - 1 - head);
        head = disk_size - 1;
        seekSequence[count++] = head;
    }

    // Jump from the end to the start of the disk (track 0)
    totalSeekTime += abs(disk_size - 1); // Moving from the last to 0
    head = 0;
    seekSequence[count++] = head;

    // Service the remaining requests from the start of the disk to the head
    for (int i = 0; i < index; i++) {
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
    int n, head, disk_size;

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
    
    // Perform CSCAN Disk Scheduling
    CSCAN(requests, n, head, disk_size);
    
    return 0;
}
