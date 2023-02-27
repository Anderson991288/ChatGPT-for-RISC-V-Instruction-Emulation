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

// 定義 RISC-V CPU 的 ALU
class ALU {
public:
    // 將兩個數值進行 AND 運算，並返回結果
    int andOp(int operand1, int operand2) {
        return operand1 & operand2;
    }
    // 將兩個數值進行 OR 運算，並返回結果
    int orOp(int operand1, int operand2) {
        return operand1 | operand2;
    }
    // 將兩個數值進行 XOR 運算，並返回結果
    int xorOp(int operand1, int operand2) {
        return operand1 ^ operand2;
    }
    // 將一個數值進行 NOT 運算，並返回結果
    int notOp(int operand) {
        return ~operand;
    }
    // 將一個數值進行左移運算，並返回結果
    int shiftLeft(int operand, int shiftAmount) {
        return operand << shiftAmount;
    }
    // 將一個數值進行右移運算，並返回結果
    int shiftRight(int operand, int shiftAmount) {
        return operand >> shiftAmount;
    }
    // 將一個數值進行算術右移運算，並返回結果
    int arithmeticShiftRight(int operand, int shiftAmount) {
        return static_cast<int>(static_cast<unsigned>(operand) >> shiftAmount);
    }
};
int main() {
// 創建一個整數寄存器
IntRegister reg;
// 創建一個 ALU
ALU alu;

// 設置寄存器的值
reg.setImmediate(1, 10);
reg.setImmediate(2, 20);

// 執行加法指令
reg.add(3, 1, 2);

// 打印結果
cout << "Result of add instruction: " << reg.get(3) << endl;

// 執行加法立即數指令
reg.addImmediate(4, 3, 30);

// 打印結果
cout << "Result of addi instruction: " << reg.get(4) << endl;

// 執行 AND 指令
int result = alu.andOp(0b10101010, 0b11110000);

// 打印結果
cout << "Result of AND operation: " << bitset<8>(result) << endl;

// 執行 OR 指令
result = alu.orOp(0b10101010, 0b11110000);

// 打印結果
cout << "Result of OR operation: " << bitset<8>(result) << endl;

// 執行 XOR 指令
result = alu.xorOp(0b10101010, 0b11110000);

// 打印結果
cout << "Result of XOR operation: " << bitset<8>(result) << endl;

// 執行 NOT 指令
result = alu.notOp(0b10101010);

// 打印結果
cout << "Result of NOT operation: " << bitset<8>(result) << endl;

// 執行左移指令
result = alu.shiftLeft(0b10101010, 2);

// 打印結果
cout << "Result of left shift operation: " << bitset<8>(result) << endl;

// 執行右移指令
result = alu.shiftRight(0b10101010, 2);

// 打印結果
cout << "Result of right shift operation: " << bitset<8>(result) << endl;

// 執行算術右移指令
result = alu.arithmeticShiftRight(0b10101010, 2);

// 打印結果
cout << "Result of arithmetic right shift operation: " << bitset<8>(result) << endl;

return 0;
}

