#include <stddef.h>
#include <unistd.h>

int main()  {
        syscall(333, NULL);   // 333 is the supworld syscall index
        return 0;
}
