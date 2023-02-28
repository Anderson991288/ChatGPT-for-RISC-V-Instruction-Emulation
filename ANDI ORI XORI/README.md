## ANDI/ORI/XORI
andi/ori/xori rd, rs1, simm12 常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器做 AND/OR/XOR運算，將結果寫入 rd暫存器。

* Code :
```
#include <iostream>

int main() {
    unsigned int rs1 = 0x3f; // register rs1的值（二進位表示為00111111）
    unsigned int imm = 0x0f; // imm的值（二進為表示為00001111）
    int rd;                 // register rd的值

    // ANDI指令
    rd = rs1 & imm; // 执行ANDI指令
    std::cout << "rs1 & imm = 0x" << std::hex << rd << std::endl; // 輸出结果

    // ORI指令
    rd = rs1 | imm; // 执行ORI指令
    std::cout << "rs1 | imm = 0x" << std::hex << rd << std::endl; // 輸出结果

    // XORI指令
    rd = rs1 ^ imm; // 执行XORI指令
    std::cout << "rs1 ^ imm = 0x" << std::hex << rd << std::endl; // 輸出结果

    return 0;
}
```
假設register rs1的值為0x3f（二進位表示為00111111），imm的值為0x0f（二進位表示為00001111）。
我們分別使用rd變量來存ANDI、ORI和XORI指令的結果，即rs1 & imm、rs1 | imm和rs1 ^ imm的值。
在執行每個指令後，我們使用std::cout來輸出結果，並使用std::hex來指定輸出結果的格式為十六進制。

* Result :
```
rs1 & imm = 0xf
rs1 | imm = 0x3f
rs1 ^ imm = 0x30
```
