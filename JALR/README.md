# JALR
jalr rd, rs1, simm12 常數部分為 sign-extended 12-bit，跳躍的位址為 rs暫存器加上 sign-extended 12-bit，並把下一道指令的位址 pc+4寫入 rd暫存器中。

* Code :

```
#include <iostream>

int main() {
    int pc = 0x100; 
    int imm = 0x200; 
    int rs1 = 0x200; 
    int rd; 

   
    rd = pc + 4; 
    pc = (rs1 + imm) & ~0x1; 
    std::cout << "JALR: pc = 0x" << std::hex << pc << ", rd = 0x" << rd << std::endl; 

    return 0;
}
```

* Result :
```
JALR: pc = 0x400, rd = 0x104
```
