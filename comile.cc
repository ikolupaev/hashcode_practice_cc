#include "core.h"

bool is_square_fit( int x, int y, int size ) {
    
    for ( int row = x-size; row <= x+size; row++ )
        for ( int column = y-size; column <= y+size; column++ )
            if ( !is_filled( row, column ) ) return false;
            
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