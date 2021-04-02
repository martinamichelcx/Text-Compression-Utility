#include "Decompression_File_Manager.h"


class Compression_Evaluator
{
    
private:
    
    std::vector<Character*> Characters ;
    float Compression_Ratio , Efficiency , Entropy ;
    
public:
    
    Compression_Evaluator() ;
    void Set_Data( std::vector<Character*> characters ) ;
    void Calculate_Ratio() ;
    void Calculate_Efficiency() ; 
    ~Compression_Evaluator() ;
} ;
