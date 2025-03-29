# include <stdio.h>
# include "common.h "
# include "piece_gen.h "
# include "defects.h "
# include "weight_dims.h "
# include "timing.h "
# include "classify.h "
# include "format.h "
# include "display_log.h "
# include "stats.h "

int main () {
    struct Piece piece ;
    struct Destination dest = {0 , 0 , 0};
    char buffer [200];
    for ( int i = 0; i < 5; i ++)
    {
        generatePiece (& piece ) ;
        checkDefects (& piece ) ;
        measureWeightAndDims (& piece ) ;
        setStationTimes (& piece ) ;
        classifyPiece ( piece , & dest ) ;
        formatData (& piece , buffer , 200) ;
        displayAndLog ( buffer ) ;
        updateStats (& piece , & dest ) ;
    }
    printStats () ;
 return 0;
}



