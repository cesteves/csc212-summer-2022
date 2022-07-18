#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

// Functions to be implemented:

bool inSet(std::set<std::string> countries, std::string check){
    for(std::set<std::string>::iterator it = countries.begin(); it != countries.end(); ++it){
        if(*it == check){
            return true;
        }
    }
    return false;
    //return countries.count(check);
}

bool inMap(std::map<std::string, int> cases, std::string check){
    for(std::map<std::string, int>::iterator it = cases.begin(); it != cases.end(); ++it){
        if(it->first == check){
            //std::cout << it->first << "\t" << it->second << std::endl;
            return true;
        }
    }
    return false;
    //return cases.count(check);
}

int main(){
    std::set<std::string> countries;

    std::map<std::string, int> cases;

    std::ifstream data;

    std::string entry;
    std::string col_data[3];    // state/province - country - cases
    std::string line;

    data.open("confirmed_cases.txt");

    std::getline(data, line);

    while (std::getline(data, line)){
        std::stringstream ss(line);
        // Clear first 2 columns from the row
        for(int i = 0; i < 2; i++){
            std::getline(ss, entry, ',');
        }

        // Store state/province & country
        std::getline(ss, col_data[0], ',');
        std::getline(ss, col_data[1], ',');

        // Clear columns 5-7
        for(int i = 0; i < 3; i++){
            std::getline(ss, entry, ',');
        }

        // Store confirmed cases
        std::getline(ss, col_data[2], ',');

        // Insert the country
        countries.insert(col_data[1]);

        // If there is no province, use the country
        if (col_data[0] == "") {
            cases.emplace(col_data[1], std::stoi(col_data[2]));
        }else{
            cases.emplace(col_data[0], std::stoi(col_data[2]));
        }

        // Skip the rest of the columns
        continue;
    }
    data.close();

    //Space for custom test cases:


    //Test Case 1

    if (!inSet(countries, "Afghanistan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "Botswana")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (!inSet(countries, "United Kingdom")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "Either country is not in set or inSet is incorrect." << std::endl;
        return 1;
    }
    if (inSet(countries, "Queensland")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Mayotte")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the the countries set." << std::endl;
        return 1;
    }
    if (inSet(countries, "Sichuan")){
        std::cout << "Test Case 1: Failed" << std::endl;
        std::cout << "A state/province was added to the countries set." << std::endl;
        return 1;
    }

    //Test Case 2:
    if (!inMap(cases, "Zimbabwe")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Zimbabwe not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Greenland")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Greenland not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (!inMap(cases, "Botswana")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "Botswana not in map or inMap is incorrect." << std::endl;
        return 1;
    }
    if (inMap(cases, "United Kingdom")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "China")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }
    if (inMap(cases, "US")){
        std::cout << "Test Case 2: Failed" << std::endl;
        std::cout << "A country that should not be in the map was inserted." << std::endl;
        return 1;
    }

    //Test Case 3:
    if (countries.size() != 190){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of set incorrect. Check your insertion" << std::endl;
        return 1;
    }

    if (cases.size() != 729){
        std::cout << "Test Case 3: Failed" << std::endl;
        std::cout << "Size of map incorrect. Check your insertion" << std::endl;
        return 1;
    }
    std::cout << "All tests passed!" << std::endl;
}