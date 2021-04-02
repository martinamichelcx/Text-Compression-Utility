#include "Compression_File_Writer.h"



class Encoder
{
    
private:
    
    std::string Encoding , Compressed_Data , Further_Compressed_Data , Output_File_Path , Table_File ;
    std::vector<Character*> Characters ;
    Compression_File_Writer * compression_file_writer ;
    int SizeOfExtension ;
    
public:
    
    Encoder() ;
    void Set_Data( std::string output_file_path , std::string table_file ) ;
    void Encode_Characters( Character * Huffman_Tree , Character * Root ) ;
    void Sort_Characters() ; 
    void Compress_Data( std::string Raw_Data ) ;
    void Compress_Further() ;
    void Write_In_File() ; 
    int Convert_To_Decimal(std::string Binary ) ;
    std::string Append(std::string Binary , int NumberOfBits ) ;
    std::string Extract_Bits( int l , int h ) ;
    void Quick_Sort( int l , int h ) ;
    int Partition( int l , int h ) ;
    void Swap( int i , int j ) ;
    std::string Search_Encoding( int l , int h , int ASCII ) ;
    ~Encoder() ;
    
} ;
