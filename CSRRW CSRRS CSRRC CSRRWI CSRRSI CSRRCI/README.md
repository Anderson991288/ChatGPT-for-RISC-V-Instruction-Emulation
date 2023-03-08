# CSRRW/CSRRS/CSRRC/CSRRWI/CSRRSI/CSRRCI
定義了一組 CSR指令，可用來讀取寫入 CSR。

* Code :
### CSRRW/CSRRS

```
#include <iostream>

// Define the CSR registers
int mstatus = 0x00001800;
int mepc = 0x00000000;
int mie = 0x00000000;

// Define the CSRRW instruction
void csrrw(int &rd, int rs1, int csr) {
    rd = csr;        // Write CSR value to rd
    csr = rs1;       // Write rs1 value to CSR
}

// Define the CSRRS instruction
void csrrs(int &rd, int rs1, int csr) {
    rd = csr;        // Write CSR value to rd
    csr |= rs1;      // OR rs1 value with CSR and write back to CSR
}

int main() {
    int rd, rs1, csr;

    // Example usage of CSRRW
    csr = mstatus;
    rs1 = 0x00001000;
    csrrw(rd, rs1, csr);
    std::cout << "CSR value after CSRRW: " << csr << std::endl;   // Should print 4096
    std::cout << "RD value after CSRRW: " << rd << std::endl;     // Should print 6144 (mstatus value)

    // Example usage of CSRRS
    csr = mie;
    rs1 = 0x00000001;
    csrrs(rd, rs1, csr);
    std::cout << "CSR value after CSRRS: " << csr << std::endl;   // Should print 1
    std::cout << "RD value after CSRRS: " << rd << std::endl;     // Should print 0 (initial mie value)

    return 0;
}
```
* Result :
```
CSR value after CSRRW: 6144
RD value after CSRRW: 6144
CSR value after CSRRS: 0
RD value after CSRRS: 0
```

### CSRRC/CSRRWI
CSRRC 指令：用於讀取 CSR 的值並清除該 CSR 中的特定的bit

格式：CSRRC rd, rs1, csr

功能：將 CSR 中的值與 rs1 寄存器的值進行按位取反，再與 CSR 中的值進行按位與操作，結果存放在 rd 寄存器中，同時更新 CSR 的值。

CSRRWI 指令：設置 CSR 中的值，並返回舊值

格式：CSRRWI rd, csr, zimm

功能：將 zimm 立即數存入 CSR 中，同時將 CSR 的原值存放在 rd 寄存器中。

* Code :
```
#include <iostream>
#include <bitset>

using namespace std;

// 定義 RISC-V CSR 寄存器
uint32_t csr = 0x12345678;

// CSRRC 指令的實現
void csrrc(uint32_t& rd, uint32_t rs1, uint32_t csr)
{
    uint32_t old_csr = csr;
    csr &= ~rs1;
    rd = old_csr & rs1;
}

// CSRRWI 指令的實現
void csrrwi(uint32_t& rd, uint32_t csr, uint32_t zimm)
{
    rd = csr;
    csr = zimm;
}

int main()
{
    uint32_t rd = 0;
    uint32_t rs1 = 0x000000FF;
    uint32_t csr = 0x12345678;
    uint32_t zimm = 0x87654321;

    cout << "csr: " << bitset<32>(csr) << endl;
    csrrc(rd, rs1, csr);
    cout << "CSRRC rd: " << bitset<32>(rd) << endl;
    cout << "csr after CSRRC: " << bitset<32>(csr) << endl;

    cout << "csr: " << bitset<32>(csr) << endl;
    csrrwi(rd, csr, zimm);
    cout << "CSRRWI rd: " << bitset<32>(rd) << endl;
    cout << "csr after CSRRWI: " << bitset<32>(csr) << endl;

    return 0;
}
```
* Result :
```
csr: 00010010001101000101011001111000
CSRRC rd: 00000000000000000000000001111000
csr after CSRRC: 00010010001101000101011001111000
csr: 00010010001101000101011001111000
CSRRWI rd: 00010010001101000101011001111000
csr after CSRRWI: 00010010001101000101011001111000
```
