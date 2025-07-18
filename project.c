#include <stdio.h>
#define MAX_CUSTOMERS 100
#define MONTHS 12
struct Customer {
    char name[50];
    char address[100];
    char phone[15];
    int consumption[12]; 
    int serial; 
};
struct Customer customers[MAX_CUSTOMERS];
int customer_count = 0;

float calculateBill(int units) {
    float bill;
    if (units <= 75) {
        bill = units * 5.26;
    } else if (units <= 200) {
        bill = (75 * 5.26) + ((units - 75) * 7.20);
    } else if (units <= 300) {
        bill = (75 * 5.26) + (125 * 7.20) + ((units - 200) * 7.59);
    } else if (units <= 400) {
        bill = (75 * 5.26) + (125 * 7.20) + (100 * 7.59) + ((units - 300) * 8.02);
    } else if (units <= 600) {
        bill = (75 * 5.26) + (125 * 7.20) + (100 * 7.59) + (100 * 8.02) + ((units - 400) * 12.67);
    } else {
        bill = (75 * 5.26) + (125 * 7.20) + (100 * 7.59) + (100 * 8.02) + (200 * 12.67) + ((units - 600) * 14.61);
    }

    return bill;
}
void addcustomer(){
    printf("\nAdd new customer\n===================\n");
    struct Customer c;
    printf("Name     : ");
    scanf(" %[^\n]", c.name);
    printf("Address  : ");
    scanf(" %[^\n]", c.address);
    printf("Phone    : ");
    scanf(" %[^\n]", c.phone);
    for (int i = 0; i < 12; i++) {
        c.consumption[i] = 0; 
    }
    c.serial = customer_count + 1;
    printf("\nCustomer added successfully.\n");
   customers[customer_count++] = c;
   printf("Customer serial no. is %d.\n", customer_count);
    
}
void saveUsage() {
    int serial=0, month, unit;
    char monthNames[12][20] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    printf("\nSave monthly usage for customer\n===============================\n");

    for (int i = 0; i < customer_count; i++) {
        printf("%d. %s (Mobile no: %s)\n", customers[i].serial, customers[i].name, customers[i].phone);
    }

    printf("\nEnter customer serial no: ");
    scanf("%d", &serial);
    if (serial < 1 || serial > customer_count) {
        printf("Invalid serial number!\n");
        return;
    }

    printf("\nEnter month:\n");
    printf("1.January      2. February\n");
    printf("3.March        4. April\n");
    printf("5.May          6. June\n");
    printf("7.July         8.August\n");
    printf("9.September    10.October\n");
    printf("11.November    12.December\n");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return;
    }

    printf("\nEnter units consumed: ");
    scanf("%d", &unit);
    if (unit < 0) {
        printf("Invalid usage value!\n");
        return;
    }

    customers[serial - 1].consumption[month - 1] = unit;
    printf("\nCustomer's usage in %s recorded.\n", monthNames[month - 1]);
}
void generateBill() {
    int serial, month;
    printf("\nGenerate bill receipt\n======================\n");

    for (int i = 0; i < customer_count; i++) {
        printf("%d. %s (Mobile no: %s)\n", customers[i].serial, customers[i].name, customers[i].phone);
    }

    printf("\nEnter customer serial no: ");
    scanf("%d", &serial);
    if (serial < 1 || serial > customer_count) {
        printf("Invalid serial number!\n");
        return;
    }

    printf("\nEnter month number (1-12): ");
    printf("1.January      2. February\n");
    printf("3.March        4. April\n");
    printf("5.May          6. June\n");
    printf("7.July         8. August\n");
    printf("9.September    10. October\n");
    printf("11.November    12. December\n");
    scanf("%d", &month);
    if (month < 1 || month > 12) {
        printf("Invalid month!\n");
        return;
    }

    int usage = customers[serial - 1].consumption[month - 1];
    if (usage == 0) {
        printf("No usage data recorded for this month.\n");
        return;
    }

    float bill = calculateBill(usage);

    printf("\n====== Bill Receipt ======\n");
    printf("Customer : %s\n", customers[serial - 1].name);
    printf("Address  : %s\n", customers[serial - 1].address);
    printf("Phone    : %s\n", customers[serial - 1].phone);
    printf("Month    : %s\n", (char*[]){"January","February","March","April","May","June","July","August","September","October","November","December"}[month - 1]);
    printf("Usage    : %d units\n", usage);
    printf("vat 5%: Tk. %.2f\n", bill * 0.05);
    printf("===========================\n");
    printf("Total Bill: Tk. %.2f\n", bill + (bill * 0.05));
    
}


int main() {  
    int choice;
    while (1) {
        printf("\n*******************************\n");
        printf("WELCOME TO DESCO BILLING SYSTEM\n");
        printf("*******************************\n");
        printf("1. Add new customer\n");
        printf("2. Save monthly usage for customer\n");
        printf("3. Generate bill receipt\n");
        printf("0. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Exiting the program.\n");
            break;
        } else if (choice == 1) {
            addcustomer();  
    }
        else if (choice == 2) {
            saveUsage();
        } else if (choice == 3) {
            generateBill();
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;  
    }