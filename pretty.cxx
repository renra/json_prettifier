#include <iostream>
#include <fstream>
#include <string>
#include "./json/src/json.hpp"

using namespace std;
using json = nlohmann::json;

int main(int argc, char * argv[]) {
  if(argc < 2) {
    cout << "Wrong usage" << endl;
    return 1;
  }

  ifstream file(argv[1]);

  string content(
    (istreambuf_iterator<char>(file)),
    (istreambuf_iterator<char>())
  );

  auto j = json::parse(content);
  cout << j.dump(2) << endl;
  return 0;
}
