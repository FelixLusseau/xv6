#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

int
drvmemread(struct inode *ip, char *dst, uint off, int n){
    if (ip->major == 2) {
        switch (ip->minor){
            case 0:
                return 0;
            case 1:
                memset(dst, 0, n);
                return n;
            case 2:
                if (off < EXTMEM || off + n > PHYSTOP)
                    return -1;
            default:
                return -1;
        }
    }
    return -1;
}

int
drvmemwrite(struct inode *ip, char *buf, uint off, int n)
{
    if (ip->major == 2) {
        switch (ip->minor){
            case 0:
                return n;
            case 1:
                return n;
            //case 2:
                
            default:
                return -1;
        }
    }
    return -1;
}

void
drvmeminit(void){
  devsw[DEV].write = drvmemwrite;
  devsw[DEV].read = drvmemread;

  ioapicenable(IRQ_KBD, 0);  
}