#include <iostream>
#include <assert.h>
#include <map>
using namespace std;
#include "TensorLib.h"
#include "MERA_Operator.cpp"
#define FERMION 1



int main(){
	Qnum_t q10(1, 0);
	Qnum_t q_10(-1, 0);
	Qnum_t q30(3, 0);
#ifdef FERMION
	Qnum_t q_11(-1, 0, 1);
	Qnum_t q11(1, 0, 1);
	Qnum_t q_31(-3, 0, 1);
#else
	Qnum_t q_11(-1, 1);
	Qnum_t q11(1, 1);
	Qnum_t q_31(-3, 1);
#endif
	vector<Bond_t> bonds;
	vector<Qnum_t> qnums;
	qnums.push_back(q10);qnums.push_back(q_11);
	Bond_t bdr(BD_ROW, qnums);
	Bond_t bdc(BD_COL, qnums);
	bonds.push_back(bdr);
	bonds.push_back(bdr);
	bonds.push_back(bdc);
	bonds.push_back(bdc);
	double H_elem[] = {1.0/4,      0,      0,     0,
						   0, -1.0/4,  1.0/2,     0,
						   0,  1.0/2, -1.0/4,     0,
						   0,      0,      0, 1.0/4};

	SyTensor_t H0(bonds, "Ob");
	H0.addRawElem(H_elem);

	SyTensor_t U(bonds, "U");
	U.orthoRand();
	SyTensor_t UT = U;
	UT.transpose();
	
	bonds.clear();
	vector<Qnum_t> qnums1;
	qnums1.push_back(q30); qnums1.push_back(q11); qnums1.push_back(q11); qnums1.push_back(q11);
	qnums1.push_back(q_10); qnums1.push_back(q_10); qnums1.push_back(q_10); qnums1.push_back(q_31);
	Bond_t bdr1(BD_ROW, qnums1);
	Bond_t bdc1(BD_COL, qnums1);
	bonds.clear();
	bonds.push_back(bdr1);
	bonds.push_back(bdc);
	bonds.push_back(bdc);
	bonds.push_back(bdc);
	SyTensor_t W1(bonds, "W1");
	W1.orthoRand();
	SyTensor_t W1T = W1;
	W1T.transpose();
	SyTensor_t W2(bonds, "W2");
	W2.orthoRand();
	SyTensor_t W2T = W2;
	W2T.transpose();

	bonds.clear();
	bonds.push_back(bdr1);
	bonds.push_back(bdr1);
	bonds.push_back(bdc1);
	bonds.push_back(bdc1);
	SyTensor_t Rho(bonds, "Rho");
	Rho.orthoRand();
	//cout<<Rho;
	/*
	printRawElem(H0, "H0_elem");
	printRawElem(W1, "W1_elem");
	printRawElem(U, "U_elem");
	printRawElem(Rho, "Rho_elem");
	*/
	
	// write out tensors before contraction.
	
	int label_H0[] = {1, 4, 2, 5};
	H0.addLabel(label_H0);
	H0.save("tenH0");
	U.save("tenU");
	UT.save("tenUT");
	W1.save("tenW1");
	W2.save("tenW2");
	W1T.save("tenW1T");
	W2T.save("tenW2T");
	Rho.save("tenRho");
	
	// Network replaceWith()
	SyTensor_t newU;
	Network_t UEnvL("../Diagrams/UEnvL");
	Network_t UEnvC("../Diagrams/UEnvC");
	Network_t UEnvR("../Diagrams/UEnvR");

	newU = UpdateU(U, Rho, H0, W1, UEnvL, UEnvC, UEnvR);

	/*
	cout << UEnvL;
	cout << UEnvC;
	cout << UEnvR;
	*/

	//cout<<Rho1;
	newU.save("tennewU");
	newU.printRawElem();
	H0.check();
	//Check whether tensors are modified or not after contractions
	SyTensor_t H0_tmp("tenH0");
	SyTensor_t U_tmp("tenU");
	SyTensor_t UT_tmp("tenUT");
	SyTensor_t W1_tmp("tenW1");
	SyTensor_t W1T_tmp("tenW1T");
	SyTensor_t W2_tmp("tenW2");
	SyTensor_t W2T_tmp("tenW2T");
	SyTensor_t Rho_tmp("tenRho");
	SyTensor_t newU_tmp("tennewU");
	
	assert(H0.elemCmp(H0_tmp));
	assert(U.elemCmp(U_tmp));
	assert(UT.elemCmp(UT_tmp));
	assert(W1.elemCmp(W1_tmp));
	assert(W1T.elemCmp(W1T_tmp));
	assert(W2.elemCmp(W2_tmp));
	assert(W2T.elemCmp(W2T_tmp));
	assert(Rho.elemCmp(Rho_tmp));
	assert(newU.elemCmp(newU_tmp));
}
