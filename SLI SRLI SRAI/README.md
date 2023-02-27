## SLLI/SRLI/SRAI
slli/srli/srai rd, rs1, uimm5 常數部分為 unsigned 5-bit，範圍為 0~31，為 shift amount，將 rs1暫存器做 shift運算，結果寫入 rd暫存器，SLLI為 logical左移，會補 0到最低位元，SRLI為 logical右移，會補 0到最高位元，SRAI為 arithmetic右移，會將原本的 sign bit複製到最高位元。
