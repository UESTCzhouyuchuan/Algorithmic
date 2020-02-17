#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

const unsigned long mod = 1000000007;

template<typename T, typename STREAM>
T get(STREAM& is) {
	T t;
	is >> t;
	return t;
}

struct print_printable { };

template<typename T, typename STREAM>
auto operator<<(STREAM& os, const T& t) -> decltype(static_cast<const print_printable*>(&t),os) {
	t.print(os);
	return os;
}

using ytype = unsigned long long int;
using xtype = unsigned short;
using cow_type = std::pair<ytype,xtype>;

namespace std {
	template<>
	struct hash<cow_type> {
		size_t operator()(const cow_type& cow) const {
			return std::hash<xtype>()(cow.first) ^ std::hash<ytype>()(cow.second);
		}
	};
}

class CowLocations {
public:
private:
	std::unordered_set<cow_type> cows;
public:
	CowLocations() : cows() { }

	void addCow(xtype x, ytype y) {
		cows.emplace(x,y);
	}

	bool hasCowAt(xtype x, ytype y) {
		return cows.find(cow_type(x,y)) != cows.end();
	}
};

int main() {

	auto road_length = get<ytype>(std::cin);
	auto num_cows = get<uint>(std::cin);

	CowLocations cows;
	for (uint i = 0; i < num_cows; ++i) {
		auto x = get<xtype>(std::cin);
		auto y = get<ytype>(std::cin);
		cows.addCow(x,y);
	}

	// usage:
	// cows.hasCowAt(x,y);

	std::vector<unsigned long> prev = {0, 1, 0, 0, 0, 0};
	std::vector<unsigned long> cur = {0, 0, 0, 0, 0, 0};

	unsigned long long i, j;
	for (i=2; i<road_length+1; ++i) {
		for (j=1; j<5; ++j) {
			if (cows.hasCowAt(j,i)) {
				cur[j] = 0;
			} else {
				cur[j] = ((prev[j-1] + prev[j])%mod + prev[j+1])%mod;
			}
		}
        if (cur[1] ==0 && cur[2]==0 && cur[3]==0 && cur[4]==0){
	       std::cout << 0 << std::endl;
            return 0;
        }
		prev = cur;
	}
	std::cout << cur[1] << std::endl;

    return 0;
}
