#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int rows;
int columns;
vector<string> data;
vector<string> commands;

bool is_filled( int x, int y ) { return data[x][y] == '#'; }

bool clear( int x, int y ) { 
    data[x][y] = '.'; 
    cerr << "clear x: " << x << " y: " << y << " " << data[x][y] << endl; 
}

void PAINT_SQUARE( int x, int y, int size ) {
    ostringstream oss;
    oss << "PAINT_SQUARE " << x << " " << y << " " << size;
    commands.push_back( oss.str() );
    
    for ( int row = x-size; row < x+size; row++ )
        for ( int column = y-size; column< y+size; column++ )
            clear( row, column );
    
}

void load() {
    cin >> rows >> columns;

    while ( cin ) {
        string s;
        cin >> s;
        data.push_back( s );
    }
}

void write() {
    cout << commands.size() << endl;
    for ( auto c : commands ) cout << c << endl;
}

void parse();

int main() {
    load();
    parse();
    write();
}