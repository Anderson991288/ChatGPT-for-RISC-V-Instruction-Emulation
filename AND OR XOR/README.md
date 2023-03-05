# AND/OR/XOR

* Code :
```
#include <iostream>

int main() {
    int rs1 = 0x1234; // 源寄存器rs1的值
    int rs2 = 0x5678; // 源寄存器rs2的值
    unsigned int rd; // 目标寄存器rd的值

    // AND指令
    rd = rs1 & rs2; // 执行AND指令，将rs1和rs2的值进行按位与操作，并将结果存储到rd寄存器中
    std::cout << "rs1 & rs2 = 0x" << std::hex << rd << std::endl; // 输出结果

    // OR指令
    rd = rs1 | rs2; // 执行OR指令，将rs1和rs2的值进行按位或操作，并将结果存储到rd寄存器中
    std::cout << "rs1 | rs2 = 0x" << std::hex << rd << std::endl; // 输出结果

    // XOR指令
    rd = rs1 ^ rs2; // 执行XOR指令，将rs1和rs2的值进行按位异或操作，并将结果存储到rd寄存器中
    std::cout << "rs1 ^ rs2 = 0x" << std::hex << rd << std::endl; // 输出结果

    return 0;
}

```
我們假設rs1的值為0x1234，rs2的值為0x5678。我們使用rd變量來存AND/OR/XOR指令的結果，即將rs1和rs2的值進行按位AND/OR/XOR操作後，將結果存到rd寄存器中。
在執行指令後，我們使用std::cout來輸出結果，並使用std::hex來指定輸出結果的格式為十六進制。
AND/OR/XOR指令需要讀取rs1和rs2的值，因此我們分別給它們賦予了初始值。
此外，AND/OR/XOR指令的操作都是按位進行的，因此我們使用位運算符（&、|、^）來實現這些指令。
最後，我們使用std::hex將輸出的結果格式化為十六進制。

* Result : 
```
rs1 & rs2 = 0x1230
rs1 | rs2 = 0x567c
rs1 ^ rs2 = 0x444c
```