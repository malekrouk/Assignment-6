#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

void getData(vector<vector<int>>& v)
{
    ifstream file("Data.txt");
    string line;
    int n;
    int row=0;
    string convert;

    if (!file.is_open())
    cout<<"Error opening the file"<<endl;

    while (getline(file, line)) {
        istringstream stream(line);


        v.push_back(vector<int>());

        while (getline(stream, convert, '\t')) {
            n = stoi(convert);
            cout << n << endl;
            v[row].push_back(n);
        }
        row++;
    }

  /*  for (const auto& rowValues : v) {
        for (int value : rowValues) {
            cout << value << "\t";
        }
        cout << endl;
    }
    */


}




int main() {
    vector<vector<int>> adjList;
    getData(adjList);
    return 0;
}
