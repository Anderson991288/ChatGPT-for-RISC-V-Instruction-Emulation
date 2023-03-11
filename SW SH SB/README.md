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

// 定義記憶體大小為1MB
#define MEM_SIZE 1048576

// 定義RISC-V的register数量
#define REG_NUM 32

// 定義每個register的大小
#define REG_SIZE 4

// 定義記憶體指針和register數組
char* mem;
int reg[REG_NUM];

// 將整數轉換為字節數組
void intToBytes(int num, char* bytes) {
    bytes[0] = num & 0xff;
    bytes[1] = (num >> 8) & 0xff;
    bytes[2] = (num >> 16) & 0xff;
    bytes[3] = (num >> 24) & 0xff;
}

// 將字節數組轉換为整數
int bytesToInt(char* bytes) {
    int num = 0;
    num |= (bytes[0] & 0xff);
    num |= (bytes[1] & 0xff) << 8;
    num |= (bytes[2] & 0xff) << 16;
    num |= (bytes[3] & 0xff) << 24;
    return num;
}


void sw(int address, int data) {
    char bytes[4];
    intToBytes(data, bytes);
    memcpy(&mem[address], bytes, 4);
}


int lw(int address) {
    char bytes[4];
    memcpy(bytes, &mem[address], 4);
    return bytesToInt(bytes);
}

// 初始化記憶體和register
void init() {
    // 分配記憶體空间
    mem = new char[MEM_SIZE];

    // 清空記憶體
    memset(mem, 0, MEM_SIZE);

    // 清空register
    memset(reg, 0, sizeof(reg));
}

// 釋放記憶體空间
void cleanup() {
    delete[] mem;
}

int main() {
    // 初始化記憶體和register
    init();

    // 存储數據到記憶體中
    sw(0, 0x12345678);

    // 加載數據到register中
    reg[1] = lw(0);

    // 輸出register中的值
    cout << hex << reg[1] << endl;

    // 釋放記憶體空间
    cleanup();

    return 0;
}
```

### SH/SB

這兩個指令用於將數據存到記憶體中，其具體含義如下：

SH 指令（Store Halfword）：將半字（16 位data）存到memory中。它的語法如下：
```
sh rs2, offset(rs1)
```
其中 rs1 和 rs2 分別是源register和目標register，offset 是一個偏移量，用於計算存儲數據的address

SB 指令（Store Byte）：將字節（8 位數據）存儲到內存中。它的語法如下：
```
sb rs2, offset(rs1)
```

其中 rs1 和 rs2 分別是源register和目標register，offset 是一個偏移量，用於計算存儲數據的address

存儲數據的address必須是 4 的倍數，否則可能會導致address 未對齊異常。如果要存儲的數據不是 4 的倍數，需要使用 SH 或 SB 指令的組合來存儲

* Code :
```
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 定義記憶體大小为1MB
#define MEM_SIZE 1048576

// 定義RISC-V的register数量
#define REG_NUM 32

// 定義每个register的大小（单位：字节）
#define REG_SIZE 4

// 定義記憶體指针和register数组
char* mem;
int reg[REG_NUM];

// 將整数轉換為字節數組
void intToBytes(int num, char* bytes) {
    bytes[0] = num & 0xff;
    bytes[1] = (num >> 8) & 0xff;
    bytes[2] = (num >> 16) & 0xff;
    bytes[3] = (num >> 24) & 0xff;
}

// 将字节数组转换为整数
int bytesToInt(char* bytes) {
    int num = 0;
    num |= (bytes[0] & 0xff);
    num |= (bytes[1] & 0xff) << 8;
    num |= (bytes[2] & 0xff) << 16;
    num |= (bytes[3] & 0xff) << 24;
    return num;
}

// 存半字（2个字节）
void sh(int address, short data) {
    char bytes[2];
    bytes[0] = data & 0xff;
    bytes[1] = (data >> 8) & 0xff;
    memcpy(&mem[address], bytes, 2);
}

// 存字节（1个字节）
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

// 初始化記憶體和register
void init() {
    // 分配記憶體空间
    mem = new char[MEM_SIZE];

    // 清空記憶體
    memset(mem, 0, MEM_SIZE);

    // 清空register
    memset(reg, 0, sizeof(reg));
}

// 释放記憶體空间
void cleanup() {
    delete[] mem;
}

int main() {
    // 初始化記憶體和register
    init();

    // 存數據到記憶體中
    sh(0, 0x5678);
    sb(2, 0x34);

    // 加载數據到register中
    reg[1] = lh(0);
    reg[2] = lb(2);

    // 輸出register中的值
    cout << hex << reg[1] << endl;
    cout << hex << (int)reg[2] << endl;

    // 释放記憶體空间
    cleanup();

    return 0;
}
```
* Result :
```
5678
34
```
