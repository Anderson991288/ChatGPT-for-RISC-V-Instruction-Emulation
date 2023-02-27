## SLTIU
sltiu rd, rs1, simm12 常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器當作 unsigned number做比較·若 rs1暫存器小於常數，則將數值 1寫入 rd暫存器，反之則寫入數值 0。
