#ifndef TELEPHONEMOCK_H
#define TELEPHONEMOCK_H

#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include "Telephone.h"

class TelephoneMock {
private:
    std::vector<MobileNetwork> _supportedNetwork;

public:
    /**
     * Default constructor
     *
     * @brief TelephoneMock
     */
    TelephoneMock() {
        _supportedNetwork.push_back(MobileNetwork("Viettel", { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" }));
        _supportedNetwork.push_back(MobileNetwork("Mobiphone", { "089", "090", "093", "070", "079", "077", "076", "078" }));
        _supportedNetwork.push_back(MobileNetwork("Vietnamobile", { "092", "056", "058" }));
        _supportedNetwork.push_back(MobileNetwork("GMobile", { "099", "059" }));
        _supportedNetwork.push_back(MobileNetwork("Itelecom", { "087" }));
        _supportedNetwork.push_back(MobileNetwork("Vinaphone", { "088", "091", "094", "083", "084", "085", "081", "082" }));
    }

    /**
     * Generating random telephone
     *
     * @brief next
     * @return
     */
    Telephone next() {
        int index = rand() % _supportedNetwork.size();
        MobileNetwork network = _supportedNetwork[index];

        std::vector<std::string> prefixes = network.prefixes();
        index = rand() % prefixes.size();
        std::string prefix = prefixes[index];

        std::stringstream writer;
        for (register int i = 0; i < 7; ++i) {
            writer << rand() % 10;
        };

        std::string numbers = writer.str();
        Telephone result(network, prefix, numbers);

        return result;
    }
};
#endif // TELEPHONEMOCK_H
