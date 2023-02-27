## ADDI

addi rd, rs1, simm12 常數部分為 sign-extended 12-bit，會將 12-bit做 sign-extension成 32-bit後，再與 rs1暫存器做加法運算，將結果寫入 rd暫存器，addi rd, rs1, 0 可被使用來當做 mov指令。
