#include<stdio.h>
#include<stdlib.h>

int findClosestRequest(int requests[], int n, int head, int processed[]) {
    int minDistance = 9999;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!processed[i]) {  
            int distance = abs(requests[i] - head);
            if (distance < minDistance) {
                minDistance = distance;
                index = i;
            }
        }
    }

    return index;
}


void SSTF(int requests[], int n, int head) {
    int processed[n];  
    for (int i = 0; i < n; i++) {
        processed[i] = 0;  
    }

    int totalSeekTime = 0;
    int seekSequence[n];
    int count = 0;

    printf("Seek Sequence: \n");
    for (int i = 0; i < n; i++) {
        int index = findClosestRequest(requests, n, head, processed);
        if (index == -1) {
            break;
        }

        processed[index] = 1;  
        totalSeekTime += abs(requests[index] - head); 
        head = requests[index];  
        seekSequence[count++] = head;
        
        printf("%d -> ", head);  
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
    printf("Average Seek Time: %.2f\n", (float)totalSeekTime / n);
}



int main() {
    int n, head;

   
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];
    
    
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
   
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    
    SSTF(requests, n, head);
    
    return 0;
}
