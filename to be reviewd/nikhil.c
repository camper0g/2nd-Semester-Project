#include <stdio.h>
#include <stdbool.h>
#define max_booking 7

bool Slot_Taken(int, int);

struct Booking {
    int id;
    char name[100];
    long long int phoneNumber[15];
    int Days;
    int time;
    int seat;
    bool isReserved;
};

struct Booking booking_haru[max_booking];
int number_of_Booking_haru= 0;
int nextTicketId = 1;



void addBooking() {
    if (number_of_Booking_haru>= max_booking) {
        printf("Maximum number of booking_haru reached. Please try again tomorrow. Thank you.\n");
        return;
    }

    struct Booking newBooking;
    newBooking.id = nextTicketId++;

    printf("Enter customer name: ");
    scanf("%[^\n]s", newBooking.name);

    printf("Enter phone number: ");
    scanf("%lld", newBooking.phoneNumber);

    printf("Enter day of the week (1-6, Sunday to Friday): ");
    scanf("%d", &newBooking.Days);

    if (newBooking.Days < 1 || newBooking.Days > 6) {
        printf("Invalid day of the week. Please enter a value between 1 (Sunday) and 6 (Friday).\n");
        return;
    }

    printf("Enter time (10AM-5PM): ");
    scanf("%d", &newBooking.time);

    if (newBooking.time == 10) {
        newBooking.seat = 1;
    } else if (newBooking.time == 11) {
        newBooking.seat = 2;
    } else if (newBooking.time == 12) {
        newBooking.seat = 3;
    } else if (newBooking.time == 1) {
        newBooking.seat = 4;
    } else if (newBooking.time == 2) {
        newBooking.seat = 5;
    } else if (newBooking.time == 3) {
        newBooking.seat = 6;
    } else if (newBooking.time == 4) {
        newBooking.seat = 7;
    } else {
        printf("Invalid time slot. Please choose a time between 10AM and 5PM.\n");
        return;
    }

    newBooking.isReserved = true;

    booking_haru[number_of_Booking_haru] = newBooking;
    number_of_Booking_haru++;

    printf("Booking created successfully. Ticket ID: %d\n", newBooking.id);
}

void displayBooking_haru() {
    printf("Ticket ID\tName\t\tPhone Number\tDay of the Week\tTime\tSeat\n");
    printf("---------------------------------------------------------------\n");

    char* Days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    for (int i = 0; i < number_of_Booking_haru; i++) {
        int time = booking_haru[i].time;

        printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t%d\n", booking_haru[i].id, booking_haru[i].name, booking_haru[i].phoneNumber,
               Days[booking_haru[i].Days - 1], time, booking_haru[i].seat);
    }
}

void displayAvailableSeats() {//calculates the seat available//
    bool isSeatTaken[7] = {false};
    char* seatOwners[7] = {""};

    for (int i = 0; i < number_of_Booking_haru; i++) {
        isSeatTaken[booking_haru[i].seat - 1] = true;
        seatOwners[booking_haru[i].seat - 1] = booking_haru[i].name;
    }

    printf("Available Seats:\n");
    printf("---------------\n");

    for (int i = 0; i < 7; i++) {
        if (!isSeatTaken[i]) {
            printf("Seat %d: Available\n", i + 1);
        } else {
            printf("Seat %d: Booked by %s\n", i + 1, seatOwners[i]);
        }
    }
}

bool Slot_Taken(int Days, int time)
{//yo chai function ho jasle chai pailai days ani time leko xa ki xaina vanera check garxa//
    for (int i = 0; i < number_of_Booking_haru; i++) {
        if (booking_haru[i].Days == Days && booking_haru[i].time == time) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;//yo function ma chai saab optioon haru xa //

    do {
        printf("\n----- Spa Appointment System -----\n");
        printf("1. Add Booking\n");
        printf("2. Display Bookings\n");
        printf("3. View Available Seats\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBooking();
                break;
            case 2:
                displayBooking_haru();
                break;
            case 3:
                displayAvailableSeats();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}