// Bankers Algorithm
// CS 33211
// Casey Shimko
#include <iostream> 
#include <fstream> 
#include <vector> 
#include <string> 
#include <sstream>
using namespace std;

#define MAX 10
// get data from .txt file
vector <string> getData(string line) {
    vector <string> data;
    string mid;
    stringstream linestream(line);
    while (getline(linestream, mid, ','))
    {
        data.push_back(mid);
    }
    return data;
}

int main(int argc, char* argv[]) {
    string stateFile;
    string line;
    int NP, NR;             // number of processes, number of resources
    vector <string> data;
    string mid;

    int all[MAX][MAX];        // allocation table
    int max[MAX][MAX];        // max table
    int avail[MAX];          // available table

    stateFile = argv[1];
    ifstream inFile(stateFile);

    getline(inFile, line);
    data = getData(line);
    istringstream(data[0]) >> NP;
    istringstream(data[1]) >> NR;

    cout << "NP = " << NP << ", NR = " << NR << '\n';

    int pro = 0; // processes
    int res = 0; // resources
    int temp = 0;

    // get and store data
    while (getline(inFile, line)) {
        

        data = getData(line);                   // each line

        for (res = 0; res < NR; res++) {

            istringstream(data[res]) >> temp;
            
            if (pro < NP) {
                all[pro][res] = temp;
            }
            else if (pro < 2 * NP) {
                max[pro - NP][res] = temp;
            }
            else {
                avail[res] = temp;
            }
        }
        pro++;
    }
    inFile.close();

    // PRINT OUT TABLES

    cout << "\nAllocation table\n";
    for (int i = 0; i < pro; i++) { 
        for (int j = 0; j < res; j++) {
            cout << all[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMax table\n"; 
    for (int i = 0; i < pro; i++) { 
        for (int j = 0; j < res; j++) {
            cout << max[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAvailable resource list\n"; 
    for (int i = 0; i < res; i++) {
        cout << avail[i] << " "; 
    }
    cout << endl << endl;

    // bankers

    bool safe = true;       // tracks if true

    int x, y, z;
    int fin[MAX];           // finished processes
    int end[MAX];           // 
    int it = 0;

    for (z = 0; z < NP; z++) {      // set all to 0
        fin[z] = 0;
    }

    int need[MAX][MAX];

    for (x = 0; x < NP; x++) {
        for (y = 0; y < NR; y++)
            need[x][y] = max[x][y] - all[x][y];
    }

    int a = 0;

    for (z = 0; z < NP; z++) {
        for (x = 0; x < NP; x++) {
            if (fin[x] == 0) {
                int b = 0;
                for (y = 0; y < NR; y++) {
                    if (need[x][y] > avail[y]) {
                        b = 1;
                        break;
                    }
                }
                if (b == 0) {
                    end[it++] = x;
                    for (a = 0; a < NR; a++) {
                        avail[a] += all[x][a];
                    }
                    fin[x] = 1;

                }
            }
        }
    }

    // check to see if it safe
    for (x = 0; x < NP; x++) {
        if (fin[x] == 0) {
            safe = false;
        }
    }

    // is not safe
    if (safe == false) {
        cout << "System is not safe.\n" << endl;
    }
    else {
        cout << "System is safe." << endl;
        cout << "Safe sequence is: " << endl;
        for (x = 0; x < NP - 1; x++) {
            cout << "P" << end[x] << " to ";
        }
        cout << " P" << end[NP - 1] << "\n\n";
    }
    return(0);
}