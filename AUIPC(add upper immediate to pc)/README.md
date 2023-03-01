## AUIPC(add upper immediate to pc)
auipc rd, uimm20
unsigned 20-bit放到最高 20位元，剩餘 12位元補0，將此數值與 pc相加寫入 rd暫存器。
假設PC的值為0x1000，imm的值為0x1234。我們使用rd變量來存儲AUIPC指令的結果，即將PC加上imm左移12位後的值存到rd register中。在執行指令後，我們使用std::cout來輸出結果，並使用std::hex來指定輸出結果的格式為十六進制。
AUIPC指令不需要讀取register的值，因此沒有使用rs1 register。


* Code :
```
#include <iostream>

int main() {
    unsigned int pc = 0x1000; // PC的值
    unsigned int imm = 0x1234; // imm的值
    unsigned int rd; // 目標register rd的值

    // AUIPC指令
    rd = pc + (imm << 12); // 執行AUIPC指令，將PC加上imm左移12位後的值存到rd中
    std::cout << "pc + (imm << 12) = 0x" << std::hex << rd << std::endl; 

    return 0;
}
```

* Result :
```
pc + (imm << 12) = 0x1235000
```
