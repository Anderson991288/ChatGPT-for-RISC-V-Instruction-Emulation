# LW LH LHU LB LBU:


* Code :
```

#include <iostream>

// 定義記憶體大小
const int MEM_SIZE = 1024;

// 定義記憶體
unsigned char memory[MEM_SIZE];

// 將數值寫入記憶體
void write_mem(unsigned int addr, unsigned int value, int size) {
    for (int i = 0; i < size; i++) {
        memory[addr + i] = (value >> (i * 8)) & 0xFF;
    }
}

// 從記憶體讀取數值
unsigned int read_mem(unsigned int addr, int size) {
    unsigned int value = 0;
    for (int i = 0; i < size; i++) {
        value |= (memory[addr + i] << (i * 8));
    }
    return value;
}

int main() {
    // 測試LW指令
    unsigned int lw_addr = 0x100;
    unsigned int lw_value = 0x12345678;
    write_mem(lw_addr, lw_value, 4);
    unsigned int lw_result = read_mem(lw_addr, 4);
    std::cout << "LW Result: " << std::hex << lw_result << std::endl;

    // 測試LH指令
    unsigned int lh_addr = 0x200;
    unsigned int lh_value = 0x5678;
    write_mem(lh_addr, lh_value, 2);
    unsigned int lh_result = read_mem(lh_addr, 2);
    std::cout << "LH Result: " << std::hex << lh_result << std::endl;

    // 測試LHU指令
    unsigned int lhu_addr = 0x300;
    unsigned int lhu_value = 0x9ABC;
    write_mem(lhu_addr, lhu_value, 2);
    unsigned int lhu_result = read_mem(lhu_addr, 2);
    std::cout << "LHU Result: " << std::hex << lhu_result << std::endl;

    // 測試LB指令
    unsigned int lb_addr = 0x400;
    unsigned int lb_value = 0xFE;
    write_mem(lb_addr, lb_value, 1);
    unsigned int lb_result = read_mem(lb_addr, 1);
    std::cout << "LB Result: " << std::hex << lb_result << std::endl;

    // 測試LBU指令
    unsigned int lbu_addr = 0x500;
    unsigned int lbu_value = 0xCD;
    write_mem(lbu_addr, lbu_value, 1);
    unsigned int lbu_result = read_mem(lbu_addr, 1);
    std::cout << "LBU Result: " << std::hex << lbu_result << std::endl;

    return 0;
}
```

* Result :
```
LW Result: 12345678
LH Result: 5678
LHU Result: 9abc
LB Result: fe
LBU Result: cd
```
