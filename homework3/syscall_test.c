#include <stdlib.h>

int supworld() {
        int ret;
        __asm__("movl $350,%eax");
        __asm__("int $0x80");
        __asm__("movl %eax, -4(%ebp)");
        return ret;
}

int main()  {
        int ret;
        printf("invoking system call supworld...\n");
        ret = supworld();
        if(ret<0) {
                printf("not working");
                exit(1);
        }
        printf("system call executed.\n");
        return 0;
}
