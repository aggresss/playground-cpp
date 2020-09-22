#include <iostream>
#include <memory>
#include <cstring> // std::memcpy

int main(int argc, char* argv[])
{
    size_t len = 8;
    uint8_t data[8] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
    std::unique_ptr<uint8_t> spsData(new uint8_t[len]);
	std::memcpy(spsData.get(), data, len);
    std::cout << std::to_string(*spsData) << std::endl;

    auto tmp_ptr = spsData.get();
    std::cout << std::to_string(*(tmp_ptr + 1)) << std::endl;
    std::cout << std::to_string(tmp_ptr[2]) << std::endl;

    return 0;
}