#include <iostream>
#include <string>

class City{
	public:
		City(std::string name_p) : name(name_p) {}
		std::string name;
		
		bool operator==(const City& other) const {
        	return name == other.name;
    	}
    	
    	friend std::ostream& operator<<(std::ostream& os, const City& city);
};

std::ostream& operator<<(std::ostream& os, const City& city)
{
    os << city.name;
    return os;
}

namespace std {
    template <>
    struct hash<City> {
        std::size_t operator()(const City& city) const noexcept {
            return std::hash<std::string>{}(city.name);
        }
    };
}
