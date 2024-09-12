#include <stdio.h>
#include <syslog.h>
#include <string.h>


int main(int argc, char **argv) {
    openlog(NULL,0,LOG_USER);
    
    if (argc != 3) {
        syslog (LOG_ERR, "Invalid number of arguments\n");
        return 1;
    }

    char *writefile=argv[1];
    char *writestr=argv[2];
    syslog (LOG_DEBUG,"Writting %s to %s",writestr, writefile);

    FILE *fptr;
    fptr = fopen(writefile, "w");
    if (fptr == NULL){
        syslog (LOG_ERR, "Error to open the file\n");
        return 1;
    }

    fprintf(fptr, "%s\n", writestr);

    
    if (fclose(fptr) != 0) {
        syslog (LOG_ERR, "Error to close the file\n");
    }

    return 0;
}