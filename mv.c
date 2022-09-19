#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char ** argv){
    if (argc != 3){
        printf(1, "Usage: %s <old-filename> <new-filename>\n", argv[0]);
        exit();
    }
    if (link(argv[1], argv[2])==-1){
        printf(1, "Error: %s could not be linked to %s\n", argv[1], argv[2]);
        exit();
    }
    if (unlink(argv[1])==-1){
        printf(1, "Error: %s could not be unlinked\n", argv[1]);
        exit();
    }
    exit();
}