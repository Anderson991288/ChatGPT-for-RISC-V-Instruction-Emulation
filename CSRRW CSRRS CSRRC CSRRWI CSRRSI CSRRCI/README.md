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
