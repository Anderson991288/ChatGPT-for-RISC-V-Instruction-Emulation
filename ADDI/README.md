## ADDI

addi rd, rs1, simm12 常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器做加法運算，將結果寫入 rd暫存器，addi rd, rs1, 0 可被使用來當做 mov指令。

* Code :
```
#include <iostream>

int main() {
    int rs1 = 5;  // register rs1的值
    int imm = 10; // imm的值
    int rd;       // 目標registerrd的值

    rd = rs1 + imm; // 執行ADDI指令

    std::cout << "rs1 + imm = " << rd << std::endl; // 輸出结果

    return 0;
}
```

* Result :
```
rs1 + imm = 15
```
