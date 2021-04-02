#include "Decoder.h"



class Decompression_File_Manager
{
    
private:
    
    int SizeOfExtension ;
    Decoder * decoder ;
    std::ifstream E , T ;
    std::string Encoded_Message ;
    std::string Encoded_File, Output_File_Path,Table_File_Path , Binary_255 ;
    std::vector<std::pair<std::string,std::string> > Table ;
    
public:
    
    Decompression_File_Manager() ;
    void Set_Data( std::string encoded_file, std::string output_file_path, std::string table_file_path) ;
    void Open_Files() ;
    void Check_Files() ;
    void Read_Encoded_Texts() ;
    void Read_Table() ;
    void Close_Files() ; 
    void Decode() ;
    void Generate_Error( std::string Message ) ;
    std::string Convert_To_Binary( unsigned int Decimal ) ;
    std::string AND( std::string bin1 , std::string bin2 ) ;
    std::string Truncate( std::string Binary ) ;
    void Remove_Extension() ;
    ~Decompression_File_Manager() ;
    
} ;
