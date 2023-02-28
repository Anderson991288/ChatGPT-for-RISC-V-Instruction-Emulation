## SLTIU
sltiu rd, rs1, simm12 常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器當作 unsigned number做比較·若 rs1暫存器小於常數，則將數值 1寫入 rd暫存器，反之則寫入數值 0。

* Code :

![SLTIU](https://user-images.githubusercontent.com/68816726/221735963-d860ae7b-6582-4f5c-ab6d-395e34e44082.png)

假設register rs1的值為5，imm的值為10。由於SLTIU指令進行的是無符號比較，因此將rs1和imm都聲明為無符號整數類型unsigned int。
我們使用rd變量來存SLTIU指令的結果，即如果rs1 < imm，則rd的值為1，否則為0。在執行SLTIU指令後，我們使用std::cout來輸出結果，即rs1 < imm的值。

* Result :

```
rs1 < imm = 1
```
