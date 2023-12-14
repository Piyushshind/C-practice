// Write a program to create a database .Database contains different fields of
//students like roll no,name and percentage.Search a particular student
//according to roll no using binary search.


#include <stdio.h>
#include <stdlib.h>
// Structure to represent
a student struct Student
{
    int rollNo;
    char
        name[50];
    float
        percen
            tage;
};
// Function to perform binary search on the student database 
int binarySearch(struct Student students[],
                          int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // Check if the key is present at the middle 
        if (students[mid].rollNo == key) return mid;
        // If key is greater,ignore the left half 
        if (students[mid].rollNo <
                                 key) low = mid + 1;
        // If key is smaller, ignore the right half
        else high = mid - 1;
    }
    // If the key is not present 
    return -1;
}
int main()
{
    int n,
        rollNoToSearch;
    // Input the number of students 
    printf("Enter the number of students: ");
scanf("%d", &n);
// Allocate memory for the student database
 struct Student
*students = (struct Student *)malloc(n * sizeof(struct Student));
// Input student data
for (int i = 0; i < n; i++) {
printf("\nEnter details for student %d:\n", i + 1);
printf("Roll No: "); scanf("%d",
&students[i].rollNo);
printf("Name: "); scanf("%s",
students[i].name);
printf("Percentage: ");
scanf("%f",
&students[i].percentage);
}
// Sort the student database based on roll number for binary search
// (Assuming the database is initially unsorted)
for (int i = 0; i <
n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].rollNo > students[j + 1].rollNo)
            { // Swap if the
                element found is greater struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
}
// Input the roll number to search
printf("\nEnter the Roll No to
search: "); scanf("%d",
&rollNoToSearch);
// Perform binary search int result =
binarySearch(students, 0, n - 1,
rollNoToSearch);
// Display the result
if (result != -1) {
        printf("\nStudent found!\n");
        printf("Roll No: %d\nName: %s\nPercentage: %.2f\n", students[result].rollNo,
               students[result].name, students[result].percentage);
} else {
        printf("\nStudent not found.\n");
}
// Free allocated memory
free(students);
return 0;
}
