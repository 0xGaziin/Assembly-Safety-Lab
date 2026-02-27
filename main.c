#include <stdio.h>
#include <stdlib.h>

extern int check_if_vm();
void menu();

int main() {
    menu();

    if (check_if_vm() == 0) {
        printf("[!] CRITICAL ERROR: Physical Machine detected!\n");
        printf("[!] This PoC must ONLY be run inside a VM.\n");
        printf("[!] Exiting for your own safety...\n");
        exit(1);
    }

    printf("[+] Environment: Virtual Machine detected. Safe to proceed.\n\n");

    char choice;
    printf("WARNING: This code simulates malicious behavior.\n");
    printf("Do you want to see the demonstration? (y/n): ");
    scanf(" %c", &choice);

    if (choice != 'y' && choice != 'Y') {
        printf("Operation cancelled.\n");
        return 0;
    }

    printf("\n[RUNNING] Simulating Boot Record manipulation...\n");
    printf("[DONE] This was just a simulation. No data was harmed.\n");

    return 0;
}

void menu() {
    printf("================================================\n");
    printf("   MALWARE DEMONSTRATION - EDUCATIONAL ONLY     \n");
    printf("================================================\n");    
}
