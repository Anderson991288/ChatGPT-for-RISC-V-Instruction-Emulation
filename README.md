## RISC-V C++ Emulator

## 整數運算指令 (Integer Computational Instructions)

整數暫存器與常數指令 (Integer Register-Immediate Instructions)
指令為暫存器與常數之間的運算

### [ADDI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/ADDI/README.md)
addi rd, rs1, simm12
常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器做加法運算，將結果寫入 rd暫存器，addi rd, rs1, 0 可被使用來當做 mov指令。

### [SLTI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLTI/README.md)
slti rd, rs1, simm12
常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器當做 signed number做比較，若 rs暫存器1小於常數，則將數值 1寫入 rd暫存器，反之則寫入數值 0。

### [SLTIU](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLTIU/README.md)
sltiu rd, rs1, simm12
常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器當作 unsigned number做比較·若 rs1暫存器小於常數，則將數值 1寫入 rd暫存器，反之則寫入數值 0。

### [ANDI/ORI/XORI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/ANDI%20ORI%20XORI/README.md)
andi/ori/xori rd, rs1, simm12
常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器做 AND/OR/XOR運算，將結果寫入 rd暫存器。

### [SLLI/SRLI/SRAI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLI%20SRLI%20SRAI/README.md)
slli/srli/srai rd, rs1, uimm5
常數部分為 unsigned 5-bit，範圍為 0~31，為 shift amount，將 rs1暫存器做 shift運算，結果寫入 rd暫存器，SLLI為 logical左移，會補 0到最低位元，SRLI為 logical右移，會補 0到最高位元，SRAI為 arithmetic右移，會將原本的 sign bit複製到最高位元。

###[ LUI (Load upper immediate)](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/LUI%20(Load%20upper%20immediate)/README.md)
lui rd, uimm20
將 unsigned 20-bit放到 rd暫存器的最高 20-bit，並將剩餘的 12-bit補 0，此指令可與 ADDI搭配，一起組合出完整 32-bit的數值。

### [AUIPC(add upper immediate to pc)]()
auipc rd, uimm20
unsigned 20-bit放到最高 20位元，剩餘 12位元補0，將此數值與 pc相加寫入 rd暫存器。











* code : 

![code1](https://user-images.githubusercontent.com/68816726/221522087-f1ef5f36-5363-4241-8084-285aaf9dc57d.png)

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




















