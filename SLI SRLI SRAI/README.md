## SLLI/SRLI/SRAI
slli/srli/srai rd, rs1, uimm5 常數部分為 unsigned 5-bit，範圍為 0~31，為 shift amount，將 rs1暫存器做 shift運算，結果寫入 rd暫存器，SLLI為 logical左移，會補 0到最低位元，SRLI為 logical右移，會補 0到最高位元，SRAI為 arithmetic右移，會將原本的 sign bit複製到最高位元。

* Code :
```
#include <iostream>

int main() {
    unsigned int rs1 = 0x3f; // 寄存器rs1的值（二進位表示為00111111）
    int shamt = 4;           // 移位量shamt的值
    int rd;                  // 目標暫存器rd的值
    // SLLI指令
    rd = rs1 << shamt; // 執行SLLI指令
    std::cout << "rs1 << shamt = 0x" << std::hex << rd << std::endl; // 輸出结果

    // SRLI指令
    rd = rs1 >> shamt; // 執行SRLI指令
    std::cout << "rs1 >> shamt = 0x" << std::hex << rd << std::endl; // 輸出结果

    // SRAI指令
    rd = (int)rs1 >> shamt; // 執行SRAI指令，需要將無符號數rs1強制轉換為有符號數int
    std::cout << "(int)rs1 >> shamt = 0x" << std::hex << rd << std::endl; // 輸出结果

    return 0;
}
```


* Result :
```
rs1 << shamt = 0x3f0
rs1 >> shamt = 0x3
(int)rs1 >> shamt = 0x3
```
