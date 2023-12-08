#include <bitset>
#include <cmath>
#include <iostream>

std::string getBinary() {
  std::string x;
  std::cout << "Enter a binary number 8 digits long: ";
  std::cin >> x;
  return x;
}

std::string letterUtility(int numberGreaterThan9) {
  switch (numberGreaterThan9) {
  case 10:
    return "A";
    break;
  case 11:
    return "B";
    break;
  case 12:
    return "C";
    break;
  case 13:
    return "D";
    break;
  case 14:
    return "E";
    break;
  case 15:
    return "F";
    break;
  default:
    return "Can't be 16";
    break;
  }
}

std::string binaryGroupToHex(std::string group) {
  // convert string to float
  int decimal = 0;

  std::string position1 = group.substr(0, 1);
  std::string position2 = group.substr(1, 1);
  std::string position3 = group.substr(2, 1);
  std::string position4 = group.substr(3, 1);

  // raise each position to 8 4 2 1 respectively
  if (stoi(position1) == 1) {
    decimal += 8;
  }

  if (stoi(position2) == 1) {
    decimal += 4;
  }

  if (stoi(position3) == 1) {
    decimal += 2;
  }
  if (stoi(position4) == 1) {
    decimal += 1;
  }

  if (decimal > 9) {
    std::string hex = letterUtility(decimal);
    return hex;
  } else {
    return std::to_string(decimal);
  }
}

std::string convertToHex(std::string x) {
  std::string group1 = x.substr(0, 4);
  std::string group2 = x.substr(4, 4);
  std::string hex = binaryGroupToHex(group1) + binaryGroupToHex(group2);
  return hex;
}

int main() {
  std::cout << "Hello user!\n";
  std::string userBin = getBinary();
  std::string userHex = convertToHex(userBin);
  std::cout << "Your binary number is: " << userHex << "\n";
}
