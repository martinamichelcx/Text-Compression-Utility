#include "Command_Line_Arguments_Reader.h"


Command_Line_Arguments_Reader::Command_Line_Arguments_Reader()
{
    compression_file_manager = new Compression_File_Manager() ;
    decompression_file_manager = new Decompression_File_Manager() ;
}

void Command_Line_Arguments_Reader::Set_Data( char * flag , char * input_file_path , char * output_file_path , char * table_file )
{
    Flag = flag ;
    Input_File_Path = input_file_path ;
    Output_File_Path = output_file_path ;
    Table_File_Path = table_file ;
}

void Command_Line_Arguments_Reader::Check_Flag()
{
    if ( Flag == "-C" )
        Compress() ;
    else if ( Flag == "-D" )
        Decompress() ;
    else
        Generate_Error("Invalid flag") ;
}

void Command_Line_Arguments_Reader::Compress()
{
    compression_file_manager->Set_Data(Input_File_Path, Output_File_Path,Table_File_Path) ;
    compression_file_manager->Open_File() ;
}

void Command_Line_Arguments_Reader::Decompress()
{
    decompression_file_manager->Set_Data(Input_File_Path, Output_File_Path,Table_File_Path) ;
    decompression_file_manager->Open_Files() ;
}

void Command_Line_Arguments_Reader::Generate_Error( std::string Message )
{
    std::cout << Message << std::endl ;
}

Command_Line_Arguments_Reader::~Command_Line_Arguments_Reader()
{
    delete compression_file_manager ;
    delete decompression_file_manager ;
}
