#include <stdio.h>

int main() {
  int n, tq, i, j, t, remain, flag;
  float wt = 0, tat = 0;
  int at[10], bt[10], rt[10];

  // Initialize variables
  printf("Enter total number of processes: ");
  scanf("%d", &n);
  remain = n;
  printf("Enter arrival time and burst time for each process:\n");
  for (i = 0; i < n; i++) {
    printf("Process %d:\n", i + 1);
    printf("Arrival Time: ");
    scanf("%d", &at[i]);
    printf("Burst Time: ");
    scanf("%d", &bt[i]);
    rt[i] = bt[i];
  }
  printf("Enter time quantum: ");
  scanf("%d", &tq);

  // Loop through all processes
  t = 0;
  while (remain > 0) {  
    flag = 0;
    for (i = 0; i < n; i++) {
      // Check if process has arrived and is not completed
      if (at[i] <= t && rt[i] > 0) {
        flag = 1;
        if (rt[i] > tq) {
          // Execute for quantum time
          t += tq;
          rt[i] -= tq;
        } else {
          // Complete the process
          t += rt[i];
          rt[i] = 0;
          remain--;

          // Calculate waiting and turnaround time
          tat += t - at[i];
          wt += tat- bt[i];
        }
      }
    }

    // If no process can be executed, increment time
    if (flag == 0) {
      t++;
    }
  }

  // Calculate average waiting and turnaround time
  wt /= n;
  tat /= n;

  // Print results
  printf("\nAverage Waiting Time: %.2f\n", wt);
  printf("Average Turnaround Time: %.2f\n", tat);
  return 0;
}