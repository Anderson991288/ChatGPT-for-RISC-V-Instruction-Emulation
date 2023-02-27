## RISC-V C++ Emulator

## 整數運算指令 (Integer Computational Instructions)

整數暫存器與常數指令 (Integer Register-Immediate Instructions)
指令為暫存器與常數之間的運算

### [ADDI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/ADDI/README.md)

### [SLTI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLTI/README.md)


### [SLTIU](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLTIU/README.md)


### [ANDI/ORI/XORI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/ANDI%20ORI%20XORI/README.md)


### [SLLI/SRLI/SRAI](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/SLI%20SRLI%20SRAI/README.md)

### [LUI (Load upper immediate)](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/blob/main/LUI%20(Load%20upper%20immediate)/README.md)


### [AUIPC(add upper immediate to pc)](https://github.com/Anderson991288/RISC-V-Instruction-Emulation/tree/main/AUIPC(add%20upper%20immediate%20to%20pc))











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




















