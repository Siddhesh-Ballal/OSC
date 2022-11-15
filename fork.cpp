// TYITA6 Siddhesh Ballal
// Assignment 2

#include <bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void AscendingSort(int nums[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

void DescendingSort(int nums[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) 
        for (j = 0; j < n - i - 1; j++)
            if (nums[j] < nums[j + 1])
                swap(nums[j], nums[j + 1]);
}

int main()
{
    int n;
    cout << "Enter number of int you want to sort: " << endl;
    cin >> n;
    int nums[n];
    cout << endl << "Enter the array of integers: " << endl;
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    int p = fork();
    
    if(p>0){
        AscendingSort(nums,n);
        for(int i=0; i<n; i++){
            cout << nums[i] << " printed by Parent: pid = " << getpid() << " and ppid = " << getppid() << endl;
            sleep(1);
        }
//        wait(NULL);
        sleep(100);
        cout << "Parent process terminates" << endl;
    }
    
    if(p==0){
        DescendingSort(nums,n);
        for(int i=0; i<n; i++){
            cout << "\t\t" << nums[i] << " printed by Child: pid = " << getpid() << " and ppid = " << getppid() << endl;
            sleep(2);
        }
        cout << "Child process terminates" << endl;
    }
    
    return 0;
}
