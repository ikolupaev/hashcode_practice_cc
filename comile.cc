#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int rows;
int columns;
vector<string> data;
vector<string> commands;

bool is_dot( char ch ) { return ch == '#'; }

void PAINT_SQUARE( int x, int y, int size ) {
    ostringstream oss;
    oss << "PAINT_SQUARE " << x << " " << y << " " << size;
    
    commands.push_back( oss.str() );
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

void parse() {
    int row = 0;
    for ( auto s : data ) {
        int column = 0;
        for ( auto ch: s ) {
            if( is_dot(ch) ) PAINT_SQUARE( row, column, 0 );
            column++; 
        }
        row++;
    }
}

int main() {
    load();
    parse();
    write();
}