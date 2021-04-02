#include "Character.h"


class Decompression_File_Writer
{
    
private:
    
    std::string Decoded_Message , File_Name ;
    std::ofstream F ;

public:
    
    Decompression_File_Writer() ;
    void Set_Data( std::string file_name , std::string decoded_message ) ;
    void Open_File() ;
    void Check_File() ;
    void Write_In_File() ;
    void Close_File() ;
    void Generate_Error( std::string Message ) ;
    ~Decompression_File_Writer() ;
    
} ;
