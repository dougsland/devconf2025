#include <stdio.h>
#include <string.h>
#include <unistd.h>   // for sleep()

int main(void) {
    char input[128];
    volatile char password[] = "REDHAT";

    while (1) {
        char buffer[256];  // staging buffer

        printf("Enter password: ");
        fflush(stdout);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            sleep(1);   // avoid busy loop
            continue;
        }

        // parse from buffer safely into input
        if (sscanf(buffer, "%127s", input) != 1) {
            sleep(1);
            continue;
        }

        if (strncmp(input, (const char *)password, sizeof(password)) == 0) {
            printf("Access granted!\n");
            break;
        } else {
            printf("Wrong password, try again.\n");
            sleep(1);   // slow brute-force
        }
    }

    memset((void *)password, 0, sizeof(password));
    (void)getchar();
    return 0;
}
