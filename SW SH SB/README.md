# SW/SH/SB

sw/sh/sb rs2, rs1, simm12

常數部分為 sign-extended 12-bit，儲存位址則為 rs1暫存器加上 sign-extended 12-bit，SW為將 rs2暫存器完整 32-bit資料寫入記憶體，SH為將 rs2暫存器最低 16-bit資料寫入記憶體，SB為將 rs2暫存器最低 8-bit資料寫入記憶體。



* Code :
### SW:

```
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 定义内存大小为1MB
#define MEM_SIZE 1048576

// 定义RISC-V的寄存器数量
#define REG_NUM 32

// 定义每个寄存器的大小（单位：字节）
#define REG_SIZE 4

// 定义内存指针和寄存器数组
char* mem;
int reg[REG_NUM];

// 将整数转换为字节数组（小端序）
void intToBytes(int num, char* bytes) {
    bytes[0] = num & 0xff;
    bytes[1] = (num >> 8) & 0xff;
    bytes[2] = (num >> 16) & 0xff;
    bytes[3] = (num >> 24) & 0xff;
}

// 将字节数组转换为整数（小端序）
int bytesToInt(char* bytes) {
    int num = 0;
    num |= (bytes[0] & 0xff);
    num |= (bytes[1] & 0xff) << 8;
    num |= (bytes[2] & 0xff) << 16;
    num |= (bytes[3] & 0xff) << 24;
    return num;
}

// 存储字（4个字节）
void sw(int address, int data) {
    char bytes[4];
    intToBytes(data, bytes);
    memcpy(&mem[address], bytes, 4);
}

// 加载字（4个字节）
int lw(int address) {
    char bytes[4];
    memcpy(bytes, &mem[address], 4);
    return bytesToInt(bytes);
}

// 初始化内存和寄存器
void init() {
    // 分配内存空间
    mem = new char[MEM_SIZE];

    // 清空内存
    memset(mem, 0, MEM_SIZE);

    // 清空寄存器
    memset(reg, 0, sizeof(reg));
}

// 释放内存空间
void cleanup() {
    delete[] mem;
}

int main() {
    // 初始化内存和寄存器
    init();

    // 存储数据到内存中
    sw(0, 0x12345678);

    // 加载数据到寄存器中
    reg[1] = lw(0);

    // 输出寄存器中的值
    cout << hex << reg[1] << endl;

    // 释放内存空间
    cleanup();

    return 0;
}
```

### SH/SB

這兩個指令用於將數據存到記憶體中，其具體含義如下：

SH 指令（Store Halfword）：將半字（16 位data）存到memory中。它的語法如下：

sh rs2, offset(rs1)

其中 rs1 和 rs2 分別是源寄存器和目標寄存器，offset 是一個偏移量，用於計算存儲數據的address

SB 指令（Store Byte）：將字節（8 位數據）存儲到內存中。它的語法如下：

sb rs2, offset(rs1)

其中 rs1 和 rs2 分別是源寄存器和目標寄存器，offset 是一個偏移量，用於計算存儲數據的address

存儲數據的address必須是 4 的倍數，否則可能會導致address 未對齊異常。如果要存儲的數據不是 4 的倍數，需要使用 SH 或 SB 指令的組合來存儲

* Code :
```
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 定义内存大小为1MB
#define MEM_SIZE 1048576

// 定义RISC-V的寄存器数量
#define REG_NUM 32

// 定义每个寄存器的大小（单位：字节）
#define REG_SIZE 4

// 定义内存指针和寄存器数组
char* mem;
int reg[REG_NUM];

// 将整数转换为字节数组（小端序）
void intToBytes(int num, char* bytes) {
    bytes[0] = num & 0xff;
    bytes[1] = (num >> 8) & 0xff;
    bytes[2] = (num >> 16) & 0xff;
    bytes[3] = (num >> 24) & 0xff;
}

// 将字节数组转换为整数（小端序）
int bytesToInt(char* bytes) {
    int num = 0;
    num |= (bytes[0] & 0xff);
    num |= (bytes[1] & 0xff) << 8;
    num |= (bytes[2] & 0xff) << 16;
    num |= (bytes[3] & 0xff) << 24;
    return num;
}

// 存储半字（2个字节）
void sh(int address, short data) {
    char bytes[2];
    bytes[0] = data & 0xff;
    bytes[1] = (data >> 8) & 0xff;
    memcpy(&mem[address], bytes, 2);
}

// 存储字节（1个字节）
void sb(int address, char data) {
    mem[address] = data;
}

// 加载半字（2个字节）
short lh(int address) {
    char bytes[2];
    memcpy(bytes, &mem[address], 2);
    return bytes[0] | (bytes[1] << 8);
}

// 加载有符号字节（1个字节）
char lb(int address) {
    return mem[address];
}

// 初始化内存和寄存器
void init() {
    // 分配内存空间
    mem = new char[MEM_SIZE];

    // 清空内存
    memset(mem, 0, MEM_SIZE);

    // 清空寄存器
    memset(reg, 0, sizeof(reg));
}

// 释放内存空间
void cleanup() {
    delete[] mem;
}

int main() {
    // 初始化内存和寄存器
    init();

    // 存储数据到内存中
    sh(0, 0x5678);
    sb(2, 0x34);

    // 加载数据到寄存器中
    reg[1] = lh(0);
    reg[2] = lb(2);

    // 输出寄存器中的值
    cout << hex << reg[1] << endl;
    cout << hex << (int)reg[2] << endl;

    // 释放内存空间
    cleanup();

    return 0;
}
```
* Result :
```
5678
34
```
