#ifndef __SSTREAM_INCLUDED__
#define __SSTREAM_INCLUDED__
#include <sstream>
#endif

#include <map>
#include <stdio.h>

#ifndef __VECTOR_INCLUDED__
#define __VECTOR_INCLUDED__
#include <vector>
#endif

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>

#include "input.h"

// Using boost
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

using namespace std;

int Ncycle;
int Ninit;
bool Linit;
double Temp;
int Iensemble;
double Pdisp;
double Pswap;
double Pvol;
double Prxn;
int Nrxn;
int Ntype;
double Deltax;
double Deltav;
double Press_Fuga;
double Box_1;
double Box_2;

vector<int> Nparts_array;
vector<double> LJ_array;
vector<int> Rxns_array;
vector<int> Stoich_array;


template <typename T>
vector<T> as_vector(ptree const& pt, ptree::key_type const& key)
{
  vector<T> r;
  for (auto& item : pt.get_child(key))
    r.push_back(item.second.get_value<T>());
  return r;
}

void read_data() {
  // declare variables

  // read simulation input in json format
  ptree inp_tree;
  ifstream inp_file( "Input.json" );
  read_json( inp_file, inp_tree );
  inp_file.close();

  // make a copy of simulation input
  ofstream inp_log( "Input.log" );
  write_json( inp_log, inp_tree );
  inp_log.close();

  // store simulation parameters
  Ncycle = inp_tree.get<int>("Params.Ncycle");
  Ninit = inp_tree.get<int>("Params.Ninit");
  Linit = inp_tree.get<bool>("Params.Linit");
  Temp = inp_tree.get<double>("Params.Temp");
  Iensemble = inp_tree.get<int>("Params.Iensemble");
  Pdisp = inp_tree.get<double>("Params.Pdisp");
  Pswap = inp_tree.get<double>("Params.Pswap");
  Pvol = inp_tree.get<double>("Params.Pvol");
  Prxn = inp_tree.get<double>("Params.Prxn");
  Nrxn = inp_tree.get<int>("Params.Nrxn");
  Ntype = inp_tree.get<int>("Params.Ntype");
  Deltax = inp_tree.get<double>("Params.Deltax");
  Deltav = inp_tree.get<double>("Params.Deltav");
  Press_Fuga = inp_tree.get<double>("Params.Press/Fuga");
  Box_1 = inp_tree.get<double>("Params.Box(1)");
  Box_2 = inp_tree.get<double>("Params.Box(2)");

  // store array variables
  for ( auto i: as_vector<int>(inp_tree, "Nparts.array") ) Nparts_array.push_back(i);
  for ( auto i: as_vector<double>(inp_tree, "LJ.array") ) LJ_array.push_back(i);
  for ( auto i: as_vector<int>(inp_tree, "Rxns.array") ) Rxns_array.push_back(i);
  for ( auto i: as_vector<int>(inp_tree, "Stoich.array") ) Stoich_array.push_back(i);

  //for (int i=0; i<Nparts_array.size(); ++i) printf("%d ",Nparts_array[i]);
  //printf("\n");
}
