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

bool is_square_clean( int x, int y, int size ) {
    
    for ( int row = x-size; row <= x+size; row++ )
        for ( int column = y-size; column <= y+size; column++ )
            if( is_filled( row, column ) ) return false;
            
    return true;
}

bool is_square_fit( int x, int y, int size ) {
    
    for ( int row = x-size; row <= x+size; row++ )
        for ( int column = y-size; column <= y+size; column++ )
            if( !is_filled( row, column ) ) return false;
            
    return true;
}

void fill_with_squares( int sq_size ) {
    
    cerr << "fill with sq size: " << sq_size << endl;
    
    for ( int x = sq_size; x+sq_size < rows; x++ ) 
        for ( int y = sq_size; y+sq_size < columns; y++ ) 
            if ( is_square_fit(x,y,sq_size) )
                PAINT_SQUARE(x,y,sq_size);
}

void parse() {
    
    for ( int sq_size = min(rows, columns); sq_size >= 0; sq_size-- ) {
        fill_with_squares( sq_size );
    }
}

int main() {
    load();
    parse();
    write();
}