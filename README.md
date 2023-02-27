# ChatGPT-for-RISC-V-Instruction-Emulation

## ChatGPT-for-RISC-V C++ Emulator

### 使用C++模擬一個RISC-V CPU integer Register-Immediate Instructions : 

* code : 
```
#include <iostream>
#include <bitset>

using namespace std;

// 定義 RISC-V CPU 的整數寄存器數量
const int NUM_REGISTERS = 32;

// 定義 RISC-V CPU 的整數寄存器類別
class IntRegister {
public:
    // 初始化所有整數寄存器的值為 0
    IntRegister() {
        for (int i = 0; i < NUM_REGISTERS; i++) {
            values[i] = 0;
        }
    }
    // 通過寄存器編號獲取寄存器的值
    int get(int registerNumber) {
        return values[registerNumber];
    }
    // 將立即數值存入指定的寄存器中
    void setImmediate(int registerNumber, int immediateValue) {
        values[registerNumber] = immediateValue;
    }
    // 將兩個寄存器的值進行加法運算，並將結果存入第三個寄存器中
    void add(int destRegister, int sourceRegister1, int sourceRegister2) {
        values[destRegister] = values[sourceRegister1] + values[sourceRegister2];
    }
    // 將一個寄存器的值與立即數值進行加法運算，並將結果存入第二個寄存器中
    void addImmediate(int destRegister, int sourceRegister, int immediateValue) {
        values[destRegister] = values[sourceRegister] + immediateValue;
    }
    // 打印所有寄存器的值
    void printAllRegisters() {
        for (int i = 0; i < NUM_REGISTERS; i++) {
            cout << "x" << i << ": " << values[i] << endl;
        }
    }
private:
    // 整數寄存器的值
    int values[NUM_REGISTERS];
};

int main() {
    // 創建一個整數寄存器對象
    IntRegister reg;

    // 設置一個立即數值
    reg.setImmediate(1, 10);

    // 將兩個寄存器的值進行加法運算，並將結果存入第三個寄存器中
    reg.add(2, 1, 3);

    // 將一個寄存器的值與立即數值進行加法運算，並將結果存入第二個寄存器中
    reg.addImmediate(4, 5, -5);

    // 打印所有寄存器的值
    reg.printAllRegisters();

    return 0;
}
```
* Result :
```
x0: 0
x1: 10
x2: 10
x3: 0
x4: -5
x5: 0
x6: 0
x7: 0
x8: 0
x9: 0
x10: 0
x11: 0
x12: 0
x13: 0
x14: 0
x15: 0
x16: 0
x17: 0
x18: 0
x19: 0
x20: 0
x21: 0
x22: 0
x23: 0
x24: 0
x25: 0
x26: 0
x27: 0
x28: 0
x29: 0
x30: 0
x31: 0
```

### 使用C++模擬一個RISC-V CPU ALU 指令 :
* code(部分) :

![code2](https://user-images.githubusercontent.com/68816726/221521509-60d901b5-1c58-414c-b904-b2c560459fad.png)

* Result :
```
Result of add instruction: 30
Result of addi instruction: 60
Result of AND operation: 10100000
Result of OR operation: 11111010
Result of XOR operation: 01011010
Result of NOT operation: 01010101
Result of left shift operation: 10101000
Result of right shift operation: 00101010
Result of arithmetic right shift operation: 00101010
```




















