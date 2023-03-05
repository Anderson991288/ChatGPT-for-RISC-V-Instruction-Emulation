# slt/sltu

slt/sltu rd, rs1, rs2 將 rs1暫存器與 rs2暫存器當做 singed/unsigned number做比較，若 rs1暫存器小於 rs2暫存器，則將數值 1寫入 rd暫存器，反之則寫入數值 0。

* Code :

```
#include <iostream>

int main() {
    int rs1 = 0x1234; 
    int rs2 = 0x5678; 
    unsigned int rd; 

    // SLT指令
    rd = (rs1 < rs2) ? 1 : 0; 
    std::cout << "rs1 < rs2 = 0x" << std::hex << rd << std::endl; 

    // SLTU指令
    rd = (static_cast<unsigned int>(rs1) < static_cast<unsigned int>(rs2)) ? 1 : 0; 
    std::cout << "rs1 <u rs2 = 0x" << std::hex << rd << std::endl;

    return 0;
}
```

* Result :
```
rs1 < rs2 = 0x1
rs1 <u rs2 = 0x1
```
