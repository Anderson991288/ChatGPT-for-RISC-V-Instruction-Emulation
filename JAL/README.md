# JAL 
jal rd, simm21 常數部分為 sign-extended 21-bit，要注意的是此常數必須為 2的倍數，即最低位元為 0，因為此道指令編碼的常數位元數只有 20位元，所以只會將 signed 21-bit的最高 20位元放入指令編碼中，跳躍範圍為 -+1MiB，同時也會將下一道指令的位址 pc+4寫入 rd暫存器中，在標準的 calling convention中，rd暫存器會使用 x1。如果只是單純的 jump，並非是呼叫函示需要儲存其返回位址 pc+4，可用 jal x0, simm21 取代。

* Code :
```
#include <iostream>

int main() {
    int pc = 0x100; 
    int imm = 0x200; 
    int rd; // 目标寄存器rd的值

    // JAL指令
    rd = pc + 4; 
    pc = pc + imm; 
    std::cout << "JAL: pc = 0x" << std::hex << pc << ", rd = 0x" << rd << std::endl; 

    return 0;
}
```

* Result :
```
JAL: pc = 0x300, rd = 0x104
```

