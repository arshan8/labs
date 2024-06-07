#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
struct student {
    int regno;
    char name[20];
};

int main() {
    // Declare an array of student structures
    struct student stud[20], temp;
    int i, n;

    // Prompt the user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Loop to input student information
    for (i = 0; i < n; i++) {
        printf("For student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", stud[i].name);
        printf("Register no: ");
        scanf("%d", &stud[i].regno);
    }

    // Open a file for appending (adding) student records
    FILE *fout = fopen("student.txt", "a");

    // Check if the file opened successfully
    if (fout == NULL) {
        printf("Error, could not open the file for writing....\n");
        return 1;
    }

    // Write the array of student structures to the file
    for (i = 0; i < n; i++) {
        fprintf(fout, "%d %s\n", stud[i].regno, stud[i].name);
    }

    // Close the output file
    fclose(fout);

    // Open the file for reading student records
    FILE *fin = fopen("student.txt", "r");

    // Check if the file opened successfully
    if (fin == NULL) {
        printf("Error, could not open the file for reading....\n");
        return 1;
    }

    printf("\nData read from the file is as follows:\n");

    // Read and display each student record
    while (fscanf(fin, "%d %s", &temp.regno, temp.name) != EOF) {
        printf("Name: %s\n", temp.name);
        printf("Reg No: %d\n\n", temp.regno);
    }

    // Close the input file
    fclose(fin);

    return 0;
}
