#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char gender[10];
    char illness[100];
};

struct Doctor {
    int id;
    char name[50];
    char specialization[100];
};

struct Appointment {
    int patient_id;
    int doctor_id;
    char date[20];
};

struct Patient patients[100];
struct Doctor doctors[100];
struct Appointment appointments[100];

int patient_count = 0;
int doctor_count = 0;
int appointment_count = 0;

void registerPatient() {
    struct Patient p;
    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf("%s", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf("%s", p.gender);
    printf("Enter Illness: ");
    scanf("%s", p.illness);
    patients[patient_count++] = p;
    printf("Patient Registered Successfully!\n");
}

void registerDoctor() {
    struct Doctor d;
    printf("\nEnter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Name: ");
    scanf("%s", d.name);
    printf("Enter Specialization: ");
    scanf("%s", d.specialization);
    doctors[doctor_count++] = d;
    printf("Doctor Registered Successfully!\n");
}

void bookAppointment() {
    struct Appointment a;
    printf("\nEnter Patient ID: ");
    scanf("%d", &a.patient_id);
    printf("Enter Doctor ID: ");
    scanf("%d", &a.doctor_id);
    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%s", a.date);
    appointments[appointment_count++] = a;
    printf("Appointment Booked Successfully!\n");
}


void showStatistics() {
    printf("\n--- PATIENTS ---\n");
    for (int i = 0; i < patient_count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Gender: %s | Illness: %s\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].illness);
    }

    printf("\n--- DOCTORS ---\n");
    for (int i = 0; i < doctor_count; i++) {
        printf("ID: %d | Name: %s | Specialization: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialization);
    }

    printf("\n--- APPOINTMENTS ---\n");
    for (int i = 0; i < appointment_count; i++) {
        printf("Patient ID: %d | Doctor ID: %d | Date: %s\n",
               appointments[i].patient_id, appointments[i].doctor_id, appointments[i].date);
    }
}

void searchPatient() {
    int id, found = 0;
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            printf("Found: ID: %d | Name: %s | Age: %d | Gender: %s | Illness: %s\n",
                   patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].illness);
            found = 1;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}

void searchDoctor() {
    int id, found = 0;
    printf("\nEnter Doctor ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i].id == id) {
            printf("Found: ID: %d | Name: %s | Specialization: %s\n",
                   doctors[i].id, doctors[i].name, doctors[i].specialization);
            found = 1;
        }
    }
    if (!found) {
        printf("Doctor not found.\n");
    }
}

void deletePatient() {
    int id, found = 0;
    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            for (int j = i; j < patient_count - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patient_count--;
            printf("Patient Deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}

void deleteDoctor() {
    int id, found = 0;
    printf("\nEnter Doctor ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < doctor_count; i++) {
        if (doctors[i].id == id) {
            for (int j = i; j < doctor_count - 1; j++) {
                doctors[j] = doctors[j + 1];
            }
            doctor_count--;
            printf("Doctor Deleted.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Doctor not found.\n");
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\n=== HEALTHCARE MANAGEMENT SYSTEM ===\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Book Appointment\n");
        printf("4. Show All Statistics\n");
        printf("5. Search Patient by ID\n");
        printf("6. Search Doctor by ID\n");
        printf("7. Delete Patient\n");
        printf("8. Delete Doctor\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                bookAppointment();
                break;
            case 4:
                showStatistics();
                break;
            case 5:
                searchPatient();
                break;
            case 6:
                searchDoctor();
                break;
            case 7:
                deletePatient();
                break;
            case 8:
                deleteDoctor();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}