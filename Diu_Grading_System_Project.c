#include <stdio.h>
#include <string.h>

float calculateGradePoint(int mark) {
    if (mark >= 80 && mark <= 100) return 4.0;
    else if (mark >= 75 && mark <= 79) return 3.75;
    else if (mark >= 70 && mark <= 74) return 3.5;
    else if (mark >= 65 && mark <= 69) return 3.25;
    else if (mark >= 60 && mark <= 64) return 3.0;
    else if (mark >= 55 && mark <= 59) return 2.75;
    else if (mark >= 50 && mark <= 54) return 2.5;
    else if (mark >= 45 && mark <= 49) return 2.25;
    else if (mark >= 40 && mark <= 44) return 2.0;
    else return 0.0; // F grade
}


void gradingSystem() {
    char name[50], id[20], semester[20];
    int marks[8], mark, subjectCount = 0;
    float totalCG = 0.0, averageCG;
    int hasFailingMark = 0;
    char continueInput[4];


    fflush(stdin);

    printf("Enter Student's Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    printf("Enter Student's ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;


    printf("Enter Semester: ");
    fgets(semester, sizeof(semester), stdin);
    semester[strcspn(semester, "\n")] = 0;


    printf("Enter subject marks (max 8 subjects). Enter -1 to terminate mark input.\n");
    while (subjectCount < 8) {
        printf("Enter mark for subject %d: ", subjectCount + 1);
        scanf("%d", &mark);

        if (mark == -1) {
            printf("Terminating mark input process.\n");
            break;
        } else if (mark < 0 || mark > 100) {
            printf("Invalid mark entered. Please enter a mark between 0 and 100.\n");
            continue;
        }

        if (mark >= 0 && mark <= 39) {
            hasFailingMark = 1;

        }

        marks[subjectCount] = mark;
        totalCG += calculateGradePoint(mark);
        subjectCount++;

        if (subjectCount == 8) {
            printf("You have entered marks for 8 subjects.\n");
        }
    }



    averageCG = hasFailingMark ? 0.0 : totalCG / subjectCount;



    printf("\n--- Student Information ---\n");
    printf("Name: %s\n", name);
    printf("ID: %s\n", id);
    printf("Semester: %s\n", semester);
    printf("Average CG: %.2f\n", averageCG);



    if (hasFailingMark) {
        printf("Grade: Fail\n");
    } else {
        if (averageCG >= 4.0) printf("Grade: A+\n");
        else if (averageCG >= 3.75) printf("Grade: A\n");
        else if (averageCG >= 3.5) printf("Grade: A-\n");
        else if (averageCG >= 3.25) printf("Grade: B+\n");
        else if (averageCG >= 3.0) printf("Grade: B\n");
        else if (averageCG >= 2.75) printf("Grade: B-\n");
        else if (averageCG >= 2.5) printf("Grade: C+\n");
        else if (averageCG >= 2.25) printf("Grade: C-\n");
        else if (averageCG >= 2.0) printf("Grade: D\n");
        else printf("Grade: F\n");
    }



    while (getchar() != '\n');
    printf("\nDo you want to input another student's marks? (Yes/No): ");
    fgets(continueInput, sizeof(continueInput), stdin);
    continueInput[strcspn(continueInput, "\n")] = 0;

    if (strcasecmp(continueInput, "Yes") == 0) {
        gradingSystem();
    } else {
        printf("Terminating the program.\n");
    }
}

int main() {
    gradingSystem();
    return 0;
}
