#include "Compression_Evaluator.h"


class Compression_File_Writer
{
    
private:
    
    int SizeOfExtension ;
    std::ofstream O , T ;
    std::string Compressed_Data , Output_File_Path , Table_File ;
    std::vector<Character*> Characters ;
    Compression_Evaluator * compression_evaluator ;
    
public:
    
    Compression_File_Writer() ;
    void Set_Data( std::string compressed_data , std::string Output_File_Path , std::vector<Character*> characters , std::string table_file , int sizeOfExtension ) ;
    void Open_Files() ;
    void Check_Files() ;
    void Write_In_Files() ;
    void Close_Files() ;
    void Evaluate_Compression() ; 
    void Generate_Error( std::string Message ) ;
    ~Compression_File_Writer() ;
} ;
