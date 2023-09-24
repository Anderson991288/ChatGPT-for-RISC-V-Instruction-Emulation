# BEQ BNE BLT BLTU BGE BGUE
常數部分為 sign-extended 13-bit，要注意的是此常數必須為 2的倍數，即最低位元為 0，因為此道指令編碼的常數位元數只有 12位元，所以只會將 signed 13-bit的最高 12位元放入指令編碼中，跳躍範圍為 -+4Kib，BEQ/BNE將 rs1暫存器與 rs2暫存器做相同與不同的比較，若成立則跳躍，BLT/BLTU將 rs1暫存器與 rs2暫存器分別做 signed/unsigned小於比較，若成立則跳躍，BGE/BGEU將 rs1暫存器與 rs2暫存器分別做 signed/unsigned大於等於比較，若成立則跳躍，跳躍的位址則為 pc加上 sign-extended 13-bit。

* Code :
```
#include <iostream>

int main() {
    int rs1 = 0x100; // rs1的值
    int rs2 = 0x200; // rs2的值
    int imm = 0x100; // 立即數，即跳轉目標位址相對於目前指令位址的偏移量
    int pc = 0x100; // 目前指令的地址（假設為0x100）
    bool branch = false; // 是否進行分支跳轉

    // BEQ指令
    if (rs1 == rs2) {
        pc += imm; // 將pc加上imm，進行跳轉
        branch = true;
        std::cout << "BEQ: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // BNE指令
    if (rs1 != rs2) {
        pc += imm; // pc加上imm，進行跳轉
        branch = true;
        std::cout << "BNE: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // BLT指令
    if (rs1 < rs2) {
        pc += imm; // pc加上imm，進行跳轉
        branch = true;
        std::cout << "BLT: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // BLTU指令
    if ((unsigned int)rs1 < (unsigned int)rs2) {
        pc += imm; // pc加上imm，進行跳轉
        branch = true;
        std::cout << "BLTU: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // BGE指令
    if (rs1 >= rs2) {
        pc += imm; // pc加上imm，進行跳轉
        branch = true;
        std::cout << "BGE: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // BGEU指令
    if ((unsigned int)rs1 >= (unsigned int)rs2) {
        pc += imm; // pc加上imm，進行跳轉
        branch = true;
        std::cout << "BGEU: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    // 如果沒有進行分支跳轉，則輸出目前指令的位址
    if (!branch) {
        std::cout << "No branch: pc = 0x" << std::hex << pc << std::endl; // 輸出結果
    }

    return 0;
}
```

* Result :
```
BNE: pc = 0x200
BLT: pc = 0x300
BLTU: pc = 0x400
```

