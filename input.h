#ifndef __SSTREAM_INCLUDED__
#define __SSTREAM_INCLUDED__
#include <sstream>
#endif

#ifndef __VECTOR_INCLUDED__
#define __VECTOR_INCLUDED__
#include <vector>
#endif

#ifndef __INPUT_H__
#define __INPUT_H__
using namespace std;

void read_data();

extern int Ncycle;
extern int Ninit;
extern bool Linit;
extern double Temp;
extern int Iensemble;
extern double Pdisp;
extern double Pswap;
extern double Pvol;
extern double Prxn;
extern int Nrxn;
extern int Ntype;
extern double Deltax;
extern double Deltav;
extern double Press_Fuga;
extern double Box_1;
extern double Box_2;

extern vector<int> Nparts_array;
extern vector<double> LJ_array;
extern vector<int> Rxns_array;
extern vector<int> Stoich_array;
#endif /* __INPUT_H__ */
