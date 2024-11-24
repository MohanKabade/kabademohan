#include<stdio.h>
#include<stdlib.h>

void FCFS(int requests[], int n, int head) {
    int totalSeekTime = 0;
    
    printf("Seek Sequence: \n");
    printf("%d ->",head);
    for (int i = 0; i < n; i++) {
        printf("%d -> ", requests[i]);
       
        totalSeekTime += abs(requests[i] - head);
        head = requests[i];
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
    
    
    FCFS(requests, n, head);
    
    return 0;
}
