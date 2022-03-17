#include <stdint.h>
#include <assert.h>

// Get Variable Length Unsigned Integer
static uint32_t GetVarLenUInteger(uint8_t* pBuff, size_t nLen, uint32_t& nStartBit) {
    uint32_t dwRet = 0;
    uint32_t leadingZeros = 0;
    while (1) {
        if (nStartBit + 1 > nLen * 8)
            return dwRet;

        if (pBuff[nStartBit / 8] & (0x80 >> (nStartBit % 8))) {
            nStartBit++;
            break;
        }
        nStartBit++;
        leadingZeros++;
    }

    if (leadingZeros >= 32) {
        dwRet = (1 << 32) - 1;
    }

    if (nStartBit + leadingZeros > nLen * 8)
        return dwRet;

    for (uint32_t i = 0; i < leadingZeros; i++) {
        dwRet <<= 1;
        if (pBuff[nStartBit / 8] & (0x80 >> (nStartBit % 8))) {
            dwRet += 1;
        }
        nStartBit++;
    }
    return dwRet;
}

int main () {
    uint8_t testBitstream[3] = {0b10100010, 0b00010100, 0b11000111};
    uint32_t startBit = 0;

    assert(0 == GetVarLenUInteger(testBitstream, 3, startBit));
    assert(1 == GetVarLenUInteger(testBitstream, 3, startBit));

    // for (uint32_t i = 0; i < 6; i++) {
    //     assert(i == GetVarLenUInteger(testBitstream, 3, startBit));
    // }
}