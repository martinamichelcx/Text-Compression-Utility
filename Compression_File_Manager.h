#include "Huffman_Tree_Builder.h"


class Compression_File_Manager
{
    
private:
    
    std::ifstream I ;
    int NumberOfCharacters ;
    std::string Raw_Data ; 
    std::vector<Character*> Characters ;
    Huffman_Tree_Builder * huffman_tree_builder ;
    std::string Input_File_Path , Output_File_Path , Table_File ;
    
public:
    
    Compression_File_Manager() ;
    void Set_Data( std::string input_file_path , std::string output_file_path , std::string table_file ) ;
    void Open_File() ;
    void Check_File() ;
    void Read_File() ;
    void Record_Data( std::vector<char> * characters ) ;
    void Close_File() ;
    void Build_Huffman_Tree() ; 
    ~Compression_File_Manager() ;
    
} ;
