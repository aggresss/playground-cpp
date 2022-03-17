#include <assert.h>
#include <stdint.h>

// Get LEB128 Unsigned Integer
static uint32_t GetLEB128UInteger(uint8_t* pBuff, size_t nLen, uint32_t& nStartBit) {
    uint32_t dwRet = 0;

    for (uint32_t i = 0; i < 8; i++) {
        uint32_t leb128Byte = 0;
        if (nStartBit + 8 > nLen * 8)
            return dwRet;

        for (uint32_t j = 0; j < 8; j++) {
            leb128Byte <<= 1;
            if (pBuff[nStartBit / 8] & (0x80 >> (nStartBit % 8))) {
                leb128Byte += 1;
            }
            nStartBit++;
        }

        dwRet |= ((leb128Byte & 0x7f) << (i * 7));
        if (!(leb128Byte & 0x80)) {
            break;
        }
    }

    return dwRet;
}

int main() {
    uint8_t testBitstream[4] = {0b10000001, 0b10000011, 0b10000111, 0b00001111};
    uint32_t startBit = 0;

    assert(0x01E1C181 == GetLEB128UInteger(testBitstream, 4, startBit));
}
