## LUI (Load upper immediate)
lui rd, uimm20
將 unsigned 20-bit放到 rd暫存器的最高 20-bit，並將剩餘的 12-bit補 0，此指令可與 ADDI搭配，一起組合出完整 32-bit的數值。

假設imm的值為0x1234。我們使用rd變量來存LUI指令的結果，即將imm左移12位後存到rd register 中。
在執行指令後，我們使用std::cout來輸出結果，並使用std::hex來指定輸出結果的格式為十六進制。
需要注意的是，LUI指令不需要讀取register的值，因此沒有使用rs1 register。
* Code :
```
#include <iostream>

int main() {
    unsigned int imm = 0x1234; // imm的值
    unsigned int rd;           // 目標register rd的值

    // LUI指令
    rd = imm << 12; // 执行LUI指令，将imm左移12位後存到rd register中
    std::cout << "imm << 12 = 0x" << std::hex << rd << std::endl;

    return 0;
}
```


* Result :
```
imm << 12 = 0x1234000
```
