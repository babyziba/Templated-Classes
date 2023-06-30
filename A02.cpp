#include <iostream> //cin , cout
#include <fstream> //file streams
#include <iomanip> // setprecision
#include <iterator> // isstream :: iterator
#include <string> //std:: string
#include <vector> //std:: vector
#include <numeric> //std:: accumulate
#include <algorithm> //std::sort
#include "Items.h"


int main() {
    //Part I
    std::cout << "************ Part I**********\n";
    std::cout << "Min , max and average of a list of numbers :\n";
    std::cout << "****************************\n";
    
    std::initializer_list <int > il{ 5,7,1,3,1024,19,29,-64, 0};
    Items <int> item_int_array(il.size(), il);
    
    // A2 Todo : Sort the Items < int > using std :: sort
    std::sort(item_int_array.begin(), item_int_array.end());


    //A2 Todo get max and min using Items member functions
    std::cout << "max = " << *std::max(item_int_array.begin(), item_int_array.end()-1) <<std::endl;
    std::cout << "min = " << *std::min(item_int_array.begin(), item_int_array.end() - 1) << std::endl;

    double average = std::accumulate(item_int_array.begin(), item_int_array.end(), 0 );

    std::cout << "average = " << std::accumulate(item_int_array.begin(), item_int_array.end(), 0.0 ) / il.size() << std::endl;

    std::cout << std::endl;

    //Part II
    std::cout << "************ Part II **********\n";
    std::cout << "Simple Bioinformatics :\n";
    std::cout << "*****************************\n";
    //
    // open file: sars_cov_2.txt and count the number of DNA base nucleotides
    //
    std::string filename = "sars_cov_2.txt";
    std::ifstream ifs(filename);
    if (!ifs.is_open()){
        std::cout << "not open";
    }
    std::istream_iterator <char > ifs_iter(ifs);
    std::istream_iterator <char > ifs_end_iter;
    // count number of charís in file
    int base_count = 0;
    for (; ifs_iter != ifs_end_iter; ifs_iter++)
        base_count++;
    // reset ifstream and istream_iterator to beginning of file
    ifs.clear();
    ifs_iter = ifs.seekg(0, std::ios::beg);
    // copy file data to the Items bases
    Items <char> bases;
    bases.update_number_of_items(base_count);
    //throwing error on windows
    std::copy(ifs_iter, ifs_end_iter, bases.begin());
    // close the file
    ifs.close();
    
    // A2 Todo: count of Aís, Gís Tís and Cís with std:: count

    int mycount = std::count(bases.begin(), bases.end(), 'A');
    int gcount = std::count(bases.begin(), bases.end(), 'G');
    int tcount = std::count(bases.begin(), bases.end(), 'T');
    int ccount = std::count(bases.begin(), bases.end(), 'C');

    std::cout << "(A)denine count = " << mycount << "\n";
    std::cout << "(G)uanine count = " << gcount << "\n";
    std::cout << "(T)hymine count = " << tcount << "\n";
    std::cout << "(C)ytosine count = " << ccount << "\n";
    std::cout << std::endl;
    //A/T and G/C
    std::cout << std::fixed << std::setprecision(2)
        << "A/T = " << (double)mycount/tcount << "\n";
    std::cout << std::fixed << std::setprecision(2)
        << "G/C = " << (double)gcount/ccount << "\n";
    std::cout << std::endl;
    std::cout << "\n***** Tests completed , enter any key to exit *******\n";
    char s; std::cin >> s;

    
    
    
    return 0;

    
}
