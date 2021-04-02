#include "Encoder.h"


class Huffman_Tree_Builder
{
    
private:
    
    Encoder * encoder ;
    std::string Raw_Data , Output_File_Path , Table_File ;
    std::vector<Character*> Characters , _Characters ;
    Character * Huffman_Tree ;
    
public:
    
    Huffman_Tree_Builder() ;
    void Set_Data(  std::vector<Character*> characters , std::string raw_data , std::string output_file_path , std::string table_file ) ;
    void Build_MinHeap() ;
    void Fix_MinHeap() ; 
    void Copy_Characters() ;
    void Build_Huffman_Tree() ;
    void Encode_Letters() ; 
    void Heapify( int i ) ;
    void Insert( Character * m ) ;
    void Swap( int i , int j ) ;
    int Min() ;
    ~Huffman_Tree_Builder() ;
    
} ;
