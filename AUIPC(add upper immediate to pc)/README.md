## AUIPC(add upper immediate to pc)
auipc rd, uimm20
unsigned 20-bit放到最高 20位元，剩餘 12位元補0，將此數值與 pc相加寫入 rd暫存器。
