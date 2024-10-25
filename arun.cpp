#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "json.hpp" 
#include "json/json.hpp"


using namespace std;
using json = nlohmann::json;


json readJson(const string &file_path) {
    ifstream file(file_path);
    json data;
    file >> data; 
    return data;
}


long long decodeValue(const string &value, int base) {
    return std::stoll(value, nullptr, base);
}


int main() {
    string file_path = "testcase2.json"; 
    json data = readJson(file_path);
    
    int n = data["keys"]["n"];
    int k = data["keys"]["k"];
    
    vector<int> x_values;
    vector<long long> y_values;

    for (auto& el : data.items()) {
        if (el.key() != "keys") {
            int x = stoi(el.key()); 
            int base = stoi(el.value()["base"].get<string>()); 
            string value = el.value()["value"].get<string>(); 
            long long y = decodeValue(value, base); 
            
            x_values.push_back(x);
            y_values.push_back(y);
        }
    }

   
    
    
    cout << "Decoded x values: ";
    for (auto x : x_values) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << "Decoded y values: ";
    for (auto y : y_values) {
        cout << y << " ";
    }
    cout << endl;

    return 0;
}
