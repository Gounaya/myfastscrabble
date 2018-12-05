#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


int main(int argc ,char *argv[]){
    std::ifstream infile(argv[2], ios::in);
    std::vector<string> myVector;
    bool found = 1;

    if (argc < 5 || argv[1] != string("-d") || argv[3] != string("-s") || argc%2!=1 ){
        return 2;
    }
    for (int i = 0; i < argc-4; i+=2) {
        string tmp = argv[4+i];
        myVector.insert(myVector.end(), tmp);
    }
    if (infile.is_open()) {
        std::string line;
        for (unsigned it=0; it<myVector.size(); it++){
            transform(myVector.at(it).begin(), myVector.at(it).end(), myVector.at(it).begin(), ::tolower);
            sort(myVector.at(it).begin(), myVector.at(it).end());
        }
        while (getline(infile, line)) {
            string mot = line.c_str();
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            sort(line.begin(), line.end());
            for (unsigned it=0; it<myVector.size(); it++){
                if(line == myVector.at(it)){
                    cout << mot <<"\n";
                    found = 0;
                }
            }
        }
        infile.close();
    } else {
        return 3;
    }
    return found;
}
