#define SET_BIT(reg, bit_no) (reg) |= (1 << bit_no)
#define CLR_BIT(reg, bit_no) (reg) &=~ (1 << bit_no)
#define TOG_BIT(reg, bit_no) (reg) ^= (1 << bit_no)
#define GET_BIT(reg, bit_no) (((reg) >> (bit_no)) & 0x01)
