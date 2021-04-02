#include "Command_Line_Arguments_Reader.h"


int main( int argc , char ** argv )
{
    if ( argc != 5 )
        Generate_Error( "Missing command line arguments " ) ;
    else
        Launch( argv[1] , argv[2] , argv[3] , argv[4] ) ;
}

void Launch( char * flag , char * input_file_path , char * output_file_path , char * Table_File )
{
    Command_Line_Arguments_Reader * Command_line_arguments_reader = new Command_Line_Arguments_Reader() ;
    Command_line_arguments_reader->Set_Data(flag,input_file_path,output_file_path,Table_File) ;
    Command_line_arguments_reader->Check_Flag() ;
}

void Generate_Error( std::string Message )
{
    std::cout << std::endl ;
    std::cout << "----------------------------" << std::endl ;
    std::cout << Message << std::endl ;
    std::cout << "----------------------------" << std::endl ;
    std::cout << std::endl ;
}
