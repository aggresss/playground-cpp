#include <iostream>
#include <iomanip>
#include <vector>
#include "json/json.h"

using json = nlohmann::json;

int main()
{
    // create byte vector
    uint8_t arr[] = {0x1b, 0x00, 0x00, 0x00, 0x08, 0x63, 0x6f, 0x6d,
                              0x70, 0x61, 0x63, 0x74, 0x00, 0x01, 0x10, 0x73,
                              0x63, 0x68, 0x65, 0x6d, 0x61, 0x00, 0x00, 0x00,
                              0x00, 0x00, 0x00
                             };
    std::vector<uint8_t> v(arr, arr + 27);

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << i << ":" << v[i] << std::endl;
    }

    // deserialize it with BSON
    json j = json::from_bson(std::addressof(v[0]), std::addressof(v[0]) + v.size(), false, false);

    // print the deserialized JSON value
    std::cout << std::setw(2) << j << std::endl;
}