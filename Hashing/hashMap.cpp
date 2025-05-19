// hash map std::map is self-balancing binary search tree (typically Red-Black Tree)

// std::unordered_map is just hash table which use key value pairs and works with key hashing without any sorting

// baci sovorakan data typeric menq karox enq dnel vorpes key mer isk grac classnery orinak henc CityRecordy karox e linel key. Bayc sra hamar petq e veradzevakerpenq map i hash functiony

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct CityRecord
{
    string name;
    int population;
    double latitude, longitude;
    CityRecord() = default;
    CityRecord(string n, int pop, double lat, double lon)
        : name(n), population(pop), latitude(lat), longitude(lon) {}
};

int main()
{
    vector<CityRecord> cities;
    cities.emplace_back("Yerevan", 20000, 3.4, 5.6);
    cities.emplace_back("Tbilisi", 20000, 3.4, 5.6);
    cities.emplace_back("Moscow", 20000, 3.4, 5.6);
    cities.emplace_back("Berlin", 20000, 3.4, 5.6);

    for (const auto &city : cities)
    {
        cout << city.name << endl;
        cout << city.population << endl;
        cout << city.latitude << endl;
        cout << city.longitude << endl;
        cout << endl;
    }

    map<string, CityRecord> citiesMap;
    citiesMap["Yerevan"] = CityRecord{"Yerevan", 20000, 3.4, 5.6};
    citiesMap["Tbilisi"] = CityRecord{"Tbilisi", 20000, 3.4, 5.6};
    citiesMap["Moscow"] = CityRecord{"Moscow", 20000, 3.4, 5.6};
    citiesMap["Berlin"] = CityRecord{"Berlin", 20000, 3.4, 5.6};

    CityRecord &yerevan = citiesMap["Yerevan"];
    cout << "Yerevan: " << yerevan.population << " " << yerevan.latitude << " " << yerevan.longitude << endl;
}