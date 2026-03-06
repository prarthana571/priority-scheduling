#include <stdio.h>
#include <string.h>
struct process
{
    char pid[10];
    int at, bt, pr;
    int rt;
    int ct, wt, tat;
};
int main()
{
    int n, time = 0, completed = 0;
    struct process p[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        p[i].rt = p[i].bt;
    }
    while(completed < n)
    {
        int highest = -1;
        int min_pr = 999;
        for(int i = 0; i < n; i++)
        {
            if(p[i].at <= time && p[i].rt > 0)
            {
                if(p[i].pr < min_pr)
                {
                    min_pr = p[i].pr;
                    highest = i;
                }
            }
        }
        if(highest == -1)
        {
            time++;
        }
        else
        {
            p[highest].rt--;
            time++;
            if(p[highest].rt == 0)
            {
                completed++;
                p[highest].ct = time;
                p[highest].tat = p[highest].ct - p[highest].at;
                p[highest].wt = p[highest].tat - p[highest].bt;
            }
        }
    }
    float total_wt = 0, total_tat = 0;
    printf("\nWaiting Time:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", p[i].pid, p[i].wt);
        total_wt += p[i].wt;
    
    printf("\nTurnaround Time:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s %d\n", p[i].pid, p[i].tat);
        total_tat += p[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt/n);
    printf("Average Turnaround Time: %.2f\n", total_tat/n);

    return 0;
}
