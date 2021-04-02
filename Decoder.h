#include "Decompression_File_Writer.h"



class Decoder
{
    
private:
    
    std::string Encoded_Message , Decoded_Message ;
    std::vector<std::pair<std::string,std::string> > Table ;
    std::string Output_File_Path ;
    Decompression_File_Writer * dfile_writer ;
    
public:
    
    Decoder() ;
    void Set_Data( std::string output_file_path , std::vector<std::pair<std::string,std::string> > table , std::string encoded_message ) ;
    void Decode() ;
    void Write_In_File() ;
    std::string Search_Table( std::string extracted_bits ) ; 
    ~Decoder() ;
    
} ;
