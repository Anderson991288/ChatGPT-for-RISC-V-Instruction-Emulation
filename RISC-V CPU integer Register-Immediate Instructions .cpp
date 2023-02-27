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

