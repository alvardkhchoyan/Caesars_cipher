#include <iostream>
#include <string>
#include <fstream>

class Caesars_cipher {
public:
    void Encode();
    void Decode();
    void wEncode();
    void wDecode();
private:
    std::string str;
};

void Caesars_cipher::Encode() {
    std::string str1;
    std::cout << " enter the string: ";
    std::cin.ignore(1);
    std::getline(std::cin,str);
    std::ofstream mfile ("Decode.txt", std::ios::app);
    if (mfile.is_open()) {
        mfile << str;
        mfile << "\n";
        mfile.close();
    }
    else {
        std::cout << "Unable to open file";
        return;
    }
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            str1 += ' ';
        }
        if ((str[i] >= 65 && str[i] <= 90)) {
            if (str[i] < 68) {
                str[i] += 23;
            }
            else if (str[i] > 87) {
                str[i] -= 23;
            }
            else {
                str[i] -= 3;
            }
            str1 += str[i];
        }
        if ((str[i] >= 97 && str[i] <= 122 )) {
            if (str[i] < 100) {
                str[i] += 23;
            }
            else if (str[i] > 199) {
                str[i] -= 23;
            }
            else {
                str[i] -= 3;
            }
            str1 += str[i];
        }
    }
    std::ofstream file ("Encode.txt",std::ios::app);
    if (file.is_open()) {
        file << str1;
        file << "\n";
        file.close();
    }
    else {
        std::cout << "Unable to open file";
        return;
    }
}

void Caesars_cipher::Decode() {
    std::string str1;
    std::cout << " enter the string: ";
    std::cin.ignore(1);
    std::getline( std::cin,str);
    std::ofstream mfile ("Decode.txt",std::ios::app);
    if (mfile.is_open()) {
        mfile << str;
        mfile << "\n";
        mfile.close();
    }
    else {
        std::cout << "Unable to open file";
        return;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ') {
            str1 += ' ';
        }
        if ((str[i] >= 65 && str[i] <= 90)) {
            if (str[i] > 87) {
                str[i] -= 23;
            }
            else {
                str[i] += 3;
            }
            str1 += str[i];
        }
        if ((str[i] >= 97 && str[i] <= 122)) {
            if (str[i] > 119) {
                str[i] -= 23;
            }
            else {
                str[i] += 3;
            }
            str1 += str[i];
        }
    }
    std::ofstream file ("Encode.txt",std::ios::app);
    if (file.is_open()) {
        file << str1;
        file << "\n";
        file.close();
    }
    else {
        std::cout << "Unable to open file";
        return;
    }
}

void Caesars_cipher::wEncode() {
    std::string line;
    std::ifstream myfile ("Encode.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line)) {
            std::cout << line << '\n';
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
    return;
}

void Caesars_cipher::wDecode() {
    std::string line;
    std::ifstream myfile ("Decode.txt");
    if (myfile.is_open()) {
        while (getline (myfile,line)) {
            std::cout << line << '\n';
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
    return;
}

int main() {
    int num = 0;
    Caesars_cipher obj;
    std::cout << " 1.write encoded \n 2.write decoded \n 3.read encoded \n 4.read decoded \n ";
    do {
        std::cout << " number: ";
        std::cin >> num;
        switch(num)
        {
            case 1:
                obj.Encode();
                break;
            case 2:
                obj.Decode();
                break;
            case 3:
                obj.wEncode();
                break;
            case 4:
                obj.wDecode();
                break;
        }
        std::cin.ignore(1);
    } while( num != 0 );
}
