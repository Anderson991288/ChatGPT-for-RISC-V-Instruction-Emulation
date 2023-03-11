
# ADD SUB

add/sub rd, rs1, rs2 將 rs1暫存器與 rs2暫存器做加法/減法運算，將結果寫入 rd暫存器。

* Code :
```
#include <iostream>

int main() {
    unsigned int rs1 = 0x1234; // 源寄存器rs1的值
    unsigned int rs2 = 0x5678; // 源寄存器rs2的值
    unsigned int rd; // 目标寄存器rd的值

    // ADD指令
    rd = rs1 + rs2; // 执行ADD指令，将rs1和rs2的值相加后存储到rd寄存器中
    std::cout << "rs1 + rs2 = 0x" << std::hex << rd << std::endl; // 輸出結果

    // SUB指令
    rd = rs1 - rs2; // 执行SUB指令，将rs1和rs2的值相减后存储到rd寄存器中
    std::cout << "rs1 - rs2 = 0x" << std::hex << rd << std::endl; // 輸出結果

    return 0;
}
```
* Result :
```
rs1 + rs2 = 0x68ac
rs1 - rs2 = 0xffffbbbc
```
