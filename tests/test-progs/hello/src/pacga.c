#include <stdio.h>
#include <stdint.h>
#include <string.h>
// Sign a message using PAC instructions
uint32_t sign(uint64_t msg, uint64_t mod) {
    uint64_t mac=0;

    asm volatile("pacga x2, x0, x1" : "=r"(mac) : "r"(msg),"r"(mod));
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");

    //printf("\n64-mac:%lu",mac);
    mac >>= 32;
    //printf("\n32-mac:%lu",mac);
    return (uint32_t)mac;
}
// Check a signed message using PAC instructions
uint32_t check(uint64_t msg, uint64_t mod, uint32_t ref) {
    uint64_t mac=0;
    asm volatile("pacga x2, x0, x1" : "=r"(mac) : "r"(msg),"r"(mod));
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    //printf("\n64-mac:%lu",mac);
    mac >>= 32;
    //printf("\n32-mac:%lu",mac);
    //printf("\n32-ref:%lu",ref);
    return ((uint32_t)mac==ref);
}
int main() {
    int count=10;
    uint32_t macs[count];
    uint64_t msg=18971230987321;
    uint64_t mod=65329148761223;
    for (int i=0;i<count;i++){
        macs[i]=sign(msg++,mod++);
    }
    double test1=1.5123;
    double test2=0;
    asm volatile("fsqrt  d1, d0");
    msg=18971230987321;
    mod=65329148761223;
    for (int i=0;i<count;i++){
        if (check(msg++,mod++,macs[i]))
            //printf("\nsignature is correct")#
            ;
        else
            //printf("\nsignature is incorrect")
        ;
    }
    return 0;
}
