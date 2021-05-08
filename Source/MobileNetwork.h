#ifndef MOBILENETWORK_H
#define MOBILENETWORK_H

#include <string>
#include <iostream>
#include <vector>

class MobileNetwork {
private:
    std::string _name;
    std::vector<std::string> _prefixes;

public:
    /* Default onstructor */
    MobileNetwork() {}
    MobileNetwork(std::string name, std::vector<std::string> prefixes) {
        _name = name;
        _prefixes.resize(0);

        for (register int i = 0; i < (int)prefixes.size(); ++i) {
            _prefixes.push_back(prefixes[i]);
        };
    }
    /* Copy constructor */
    MobileNetwork(const MobileNetwork& mb) {
        _name = mb._name;
        _prefixes.resize(0);

        for (register int i = 0; i < (int)mb._prefixes.size(); ++i) {
            _prefixes.push_back(mb._prefixes[i]);
        };
    }

    /* Overloading = */
    const MobileNetwork& operator=(const MobileNetwork& mb) {
        _name = mb._name;

        for (register int i = 0; i < (int)mb._prefixes.size(); ++i) {
            _prefixes.push_back(mb._prefixes[i]);
        };

        return *this;
    }

    /* Destructor */
    ~MobileNetwork() {}

    /**
     * @brief setName
     * @param value
     */
    void setName(std::string value) {
        _name = value;
    }
    std::string name() {
        return _name;
    }

    /**
     * @brief setPrefixes
     * @param value
     */
    void setPrefixes(std::vector<std::string> value) {
        _prefixes = value;
    }
    std::vector<std::string> prefixes() {
        return _prefixes;
    }
};
#endif // MOBILENETWORK_H
