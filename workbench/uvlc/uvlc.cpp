#include <assert.h>
#include <stdint.h>

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
        dwRet = UINT32_MAX;
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
    return dwRet + (1 << leadingZeros) - 1;
}

int main() {
    uint8_t testBitstream[4] = {0b10100110, 0b01000010, 0b10011000, 0b11111111};
    uint32_t startBit = 0;

    for (uint32_t i = 0; i < 6; i++) {
        assert(i == GetVarLenUInteger(testBitstream, 4, startBit));
    }
}
