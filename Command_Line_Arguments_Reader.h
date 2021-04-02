#include "Compression_File_Manager.h"


class Command_Line_Arguments_Reader
{
    
private:
    
    std::string Flag , Input_File_Path , Output_File_Path , Table_File_Path ;
    Decompression_File_Manager * decompression_file_manager ;
    Compression_File_Manager * compression_file_manager ;
    
public:
     
    Command_Line_Arguments_Reader() ;
    void Set_Data( char * flag , char * input_file_path , char * output_file_path , char * table_file ) ;
    void Check_Flag() ;
    void Compress() ;
    void Decompress() ;
    void Generate_Error( std::string Message ) ;
    ~Command_Line_Arguments_Reader() ;
    
} ;
