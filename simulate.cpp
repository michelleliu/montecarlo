//
// Reaction monte carlo simulation
//
#include <sstream>
#include <map>
#include <stdio.h>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>

#include "input.h"

// Using boost
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
using namespace std;

int main( int argc, char *argv[] ) {

  // display help commands
  if( argc < 2 ) {
    printf( "reaction-mc usage: simulate [inputfile]\n" );
    exit(0);
  }

  // read input file
  // file must be named "Input.json"
  read_data();

  // depending on ensemble, ...
  if (Iensemble==5) {
    Pvol=0;

  }
}
