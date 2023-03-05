# SLL SRL SRA

sll/srl/sra rd, rs1,, rs2 將 rs1暫存器做 shift運算，結果寫入 rd暫存器，rs2暫存器的最低 5-bit為 shift amount。

* Code :
```
#include <iostream>

int main() {
    int rs1 = 0x1234; // rs1的值
    int shamt = 2; // 移位量
    unsigned int rd; // rd的值

    // SLL指令
    rd = rs1 << shamt; // 
    std::cout << "rs1 << shamt = 0x" << std::hex << rd << std::endl; // 輸出結果

    // SRL指令
    rd = (unsigned int) rs1 >> shamt; // 執行SRL指令，將rs1的值右移shamt位（邏輯右移），並將結果存到rd中
    std::cout << "rs1 >> shamt = 0x" << std::hex << rd << std::endl; // 輸出結果

    // SRA指令
    rd = rs1 >> shamt; // 執行SRA指令，將rs1的值右移shamt位（算術右移），並將結果存到rd中
    std::cout << "rs1 >> shamt (arithmetic) = 0x" << std::hex << rd << std::endl; // 輸出結果

    return 0;
}

```

假設rs1的值為0x1234，移位量shamt為2。我們使用rd變量來存SLL/SRL/SRA指令的結果，即將rs1的值進行移位操作後，將結果存到rd中。
在執行指令後，我們使用std::cout來輸出結果，並使用std::hex來指定輸出結果的格式為十六進制。
需要注意的是，在執行SRL指令時，我們需要將rs1的值先轉換為unsigned int類型，以避免算術右移時最高位被符號位填充。
此外，SLL/SRL/SRA指令的移位操作都是按位進行的，因此我們使用移位運算符（<<、>>）來實現這些指令。
最後，我們使用std::hex將輸出的結果格式化為十六進制。

* Result :

```
rs1 << shamt = 0x48d0
rs1 >> shamt = 0x48d
rs1 >> shamt (arithmetic) = 0x48d
```
