#include <iostream>
#include <iomanip>
#include "../deps/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

int main()
{
    // create a JSON value
    json j = R"({"compact": true, "schema": 0})"_json;

    j["bin"] = json::binary({65, 66, 67});

    // serialize it to BSON
    std::vector<uint8_t> v = json::to_bson(j);

    // print the vector content
    for (auto& byte : v)
    {
        std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)byte << " ";
    }
    std::cout << std::endl;

    json x = json::from_bson(v);
    auto xIt = x.find("bin");
    if (xIt != x.end() && xIt->is_binary()) {
        auto& dump = xIt->get_binary();
        std::cout << "length: " << dump.size() << std::endl;
        for (auto& byte: dump) {
            std::cout << byte << std::endl;
        }
    }

}