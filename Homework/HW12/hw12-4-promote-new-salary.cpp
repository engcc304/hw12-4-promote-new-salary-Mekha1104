/*
    ผู้บริหารต้องการวิเคราะห์พัฒนาการของพนักงานในบริษัทและศักยภาพของพนักงานจากทักษะที่พัฒนาขึ้นของแต่ละคน ซึ่งแปลงค่าความสามารถของแต่ละคนออกมาเป็นค่า EXP โดยแบ่งอัตราการขึ้นเงินเดือนของแต่ละคนดังนี้
    EXP อยู่ในช่วง 0-1,000 		จะได้รับเงินเดือน x1
	EXP อยู่ในช่วง 1,000-2,000 	จะได้รับเงินเดือน x1.2
	EXP อยู่ในช่วง 2,000-3,000 	จะได้รับเงินเดือน x1.4
	EXP อยู่ในช่วง 3,000-4,000 	จะได้รับเงินเดือน x1.6
	EXP อยู่ในช่วง 4,000-5,000 	จะได้รับเงินเดือน x1.8
	EXP อยู่ในช่วง 5,000 ขึ้นไป	จะได้รับเงินเดือน x2
    โดยผู้บริหารมอบหมายให้ HR เป็นคนกรอกข้อมูลพนักงานในบริษัทและประเมินค่า EXP ของพนักงานแต่ละคน พร้อมสรุปจำนวนคนที่ได้รับเงินเดือนในแต่ละขั้น และระบุคนชื่อคนที่ได้เงินเดือนเยอะที่สุด และคนที่เงินเดือนน้อยที่สุด (หากกรอกเลข -1 ในช่อง Name จะถือเป็นการหยุดโปรแกรมและเตรียมแสดงผล)
    
    Test case:
        Employee 1 Name : 
            Atom
        EXP : 
            2500
        Employee 2 Name : 
            Aom
        EXP : 
            3230
        Employee 3 Name : 
            Aim
        EXP : 
            4560
        Employee 4 Name : 
            Jom
        EXP : 
            5505
        Employee 5 Name : 
            On
        EXP : 
            950
        Employee 6 Name : 
            Oom
        EXP : 
            3500
        Employee 7 Name : 
            Ky
        EXP : 
            2600
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 0
        x1.4 count 2
        x1.6 count 2
        x1.8 count 1
        x2.0 count 1
        The Employee get x2.0 is Jom
        The Employee get x1.0 is On

    Test case:
        Employee 1 Name : 
            Aey
        EXP : 
            9956
        Employee 2 Name : 
            J
        EXP : 
            4900
        Employee 3 Name : 
            A
        EXP : 
            4560
        Employee 4 Name : 
            Orio
        EXP : 
            200
        Employee 5 Name : 
            Vistra
        EXP : 
            1656
        Employee 6 Name : 
            Oh
        EXP : 
            2300
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 1
        x1.4 count 1
        x1.6 count 0
        x1.8 count 2
        x2.0 count 1
        The Employee get x2.0 is Aey
        The Employee get x1.0 is Orio
*/
#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[20];
    int EXP;
    float Salary;
};

int main() {
    struct Employee employees[100];
    int numEmployees = 0;
    int salaryCounts[6] = {0};
    float maxSalary = 0;
    float minSalary = 0;

    do {
        printf("Employee %d Name : ", numEmployees + 1);
        scanf("%s", employees[numEmployees].Name);

        if (strcmp(employees[numEmployees].Name, "-1") == 0) {
            break;
        }

        printf("EXP : ");
        scanf("%d", &employees[numEmployees].EXP);

        // คำนวณเงินเดือนตามขั้นที่กำหนด
        if (employees[numEmployees].EXP >= 0 && employees[numEmployees].EXP < 1000) {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 1.0;
            salaryCounts[0]++;
        } else if (employees[numEmployees].EXP < 2000) {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 1.2;
            salaryCounts[1]++;
        } else if (employees[numEmployees].EXP < 3000) {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 1.4;
            salaryCounts[2]++;
        } else if (employees[numEmployees].EXP < 4000) {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 1.6;
            salaryCounts[3]++;
        } else if (employees[numEmployees].EXP < 5000) {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 1.8;
            salaryCounts[4]++;
        } else {
            employees[numEmployees].Salary = employees[numEmployees].EXP * 2.0;
            salaryCounts[5]++;
        }

        // หาเงินเดือนเยอะที่สุดและเงินเดือนน้อยที่สุด
        if (employees[numEmployees].Salary > maxSalary || numEmployees == 0) {
            maxSalary = employees[numEmployees].Salary;
        }
        if (employees[numEmployees].Salary < minSalary || numEmployees == 0) {
            minSalary = employees[numEmployees].Salary;
        }

        numEmployees++;
    } while (numEmployees < 100);

    // แสดงผลลัพธ์
    printf("**** Salary Result ****\n");
    for (int i = 0; i < 6; i++) {
        printf("x%.1f count %d\n", 1.0 + i * 0.2, salaryCounts[i]);
    }
    printf("The Employee get x%.1f is ", maxSalary / employees[numEmployees - 1].EXP);
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].Salary == maxSalary) {
            printf("%s", employees[i].Name);
            break;
        }
    }
    printf("\nThe Employee get x%.1f is ", minSalary / employees[numEmployees - 1].EXP);
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].Salary == minSalary) {
            printf("%s", employees[i].Name);
            break;
        }
    }

    return 0;
}


