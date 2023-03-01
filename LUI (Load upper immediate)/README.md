## LUI (Load upper immediate)
lui rd, uimm20
將 unsigned 20-bit放到 rd暫存器的最高 20-bit，並將剩餘的 12-bit補 0，此指令可與 ADDI搭配，一起組合出完整 32-bit的數值。
* Code :
```
#include <iostream>

int main() {
    unsigned int imm = 0x1234; // 立即数imm的值
    unsigned int rd;           // 目标寄存器rd的值

    // LUI指令
    rd = imm << 12; // 执行LUI指令，将imm左移12位后存储到rd寄存器中
    std::cout << "imm << 12 = 0x" << std::hex << rd << std::endl; // 输出结果

    return 0;
}
```


* Result :
```
imm << 12 = 0x1234000
```
