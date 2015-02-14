/****************************************************************************
*  @file CMakeLists.txt
*  @license
*    Universal Tensor Network Library
*    Copyright (c) 2013-2014
*    Yun-Da Hsieh, Pochung Chen and Ying-Jer Kao
*
*    This file is part of Uni10, the Universal Tensor Network Library.
*
*    Uni10 is free software: you can redistribute it and/or modify
*    it under the terms of the GNU Lesser General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    Uni10 is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public License
*    along with Uni10.  If not, see <http://www.gnu.org/licenses/>.
*  @endlicense
*  @brief Header file for UniTensor class
*  @author Yun-Da Hsieh
*  @date 2014-05-06
*  @since 0.1.0
*
*****************************************************************************/
#ifndef UNITENSOR_H
#define UNITENSOR_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <assert.h>
#include <sstream>
#include <stdexcept>
#include <uni10/datatype.hpp>
#include <uni10/data-structure/uni10_struct.h>

/**
 * @brief Class of the symmetry tensor.
 */
namespace uni10{
class Block;
class CBlock;
class Matrix;
class CMatrix;
class UniTensor{
	public:
		UniTensor();
		UniTensor(double val);
		UniTensor(const std::string& fname);
		UniTensor(const std::vector<Bond>& _bonds, const std::string& _name = "");
		UniTensor(const std::vector<Bond>& _bonds, std::vector<int>& labels, const std::string& _name = "");
		UniTensor(const std::vector<Bond>& _bonds, int* labels, const std::string& _name = "");
		UniTensor(const UniTensor& UniT);
		UniTensor(const Block& UniT);
		~UniTensor();
		UniTensor& operator=(const UniTensor& UniT);
		UniTensor& assign(const std::vector<Bond>& _bond);
		void setLabel(const std::vector<int>& newLabels);
    void setLabel(int* newLabels);
		std::vector<int> label()const;
		int label(size_t idx)const;
		std::string getName();
    void setName(const std::string& _name);
		size_t bondNum()const;
		size_t inBondNum()const;
		std::vector<Bond> bond()const;
		Bond bond(size_t idx)const;
		size_t elemNum()const;
		Matrix getRawElem()const;
    void setRawElem(const Block& blk);
    void setRawElem(const std::vector<double>& rawElem);
    void setRawElem(const double* rawElem);
    double at(const std::vector<int>& idxs)const;
    double at(const std::vector<size_t>& idxs)const;
    size_t blockNum()const;
    std::vector<Qnum> blockQnum()const;
    Qnum blockQnum(size_t idx)const;
		const std::map<Qnum, Block>& const_getBlocks()const;
		const Block& const_getBlock()const;
		const Block& const_getBlock(const Qnum& qnum)const;
		std::map<Qnum, Matrix> getBlocks()const;
		Matrix getBlock(bool diag = false)const;
		Matrix getBlock(const Qnum& qnum, bool diag = false)const;
		void putBlock(const Block& mat);
		void putBlock(const Qnum& qnum, const Block& mat);
    double* getElem();
    void setElem(const double* elem, bool _ongpu = false);
    void setElem(const std::vector<double>& elem, bool _ongpu = false);
    double operator[](size_t idx)const;
		void set_zero();
		void set_zero(const Qnum& qnum);
		void identity();
		void identity(const Qnum& qnum);
		void randomize();
		void orthoRand();
		void orthoRand(const Qnum& qnum);
    void clear();
    void save(const std::string& fname);
    UniTensor& permute(const std::vector<int>& newLabels, int inBondNum);
    UniTensor& permute(int* newLabels, int inBondNum);
    UniTensor& permute(int inBondNum);
		UniTensor& transpose();
		UniTensor& combineBond(const std::vector<int>& combined_labels);
    UniTensor& partialTrace(int la, int lb); //CHECK
    double trace()const;
    std::vector<UniTensor> hosvd(size_t modeNum, size_t fixedNum = 0)const;
    std::vector<UniTensor> hosvd(size_t modeNum, size_t fixedNum, std::vector<Matrix>& Ls)const;
    std::vector<UniTensor> hosvd(size_t modeNum, size_t fixedNum, std::vector<std::map<Qnum, Matrix> >& Ls)const;
    std::vector<UniTensor> hosvd(size_t modeNum, std::vector<Matrix>& Ls)const;
    std::vector<UniTensor> hosvd(size_t modeNum, std::vector<std::map<Qnum, Matrix> >& Ls)const;
    bool similar(const UniTensor& Tb)const;
    bool elemCmp(const UniTensor& UniT)const;
    std::string printRawElem(bool print=true)const;
    static std::string profile(bool print = true);
    UniTensor& operator*= (double a);
    UniTensor& operator*= (const UniTensor& Tb);
    UniTensor& operator+= (const UniTensor& Tb);
    std::vector<_Swap> exSwap(const UniTensor& Tb)const;
    void addGate(const std::vector<_Swap>& swaps);
    friend UniTensor contract(UniTensor& Ta, UniTensor& Tb, bool fast);
    friend UniTensor otimes(const UniTensor& Ta, const UniTensor& Tb);
    friend UniTensor operator*(const UniTensor& Ta, const UniTensor& Tb);
    friend UniTensor operator*(const UniTensor& Ta, double a);
    friend UniTensor operator*(double a, const UniTensor& Ta);
    friend UniTensor operator+(const UniTensor& Ta, const UniTensor& Tb);
    friend std::ostream& operator<< (std::ostream& os, const UniTensor& UniT);
    friend class Node;
    friend class Network;

	private:
		std::string name;
		double *elem;		//Array of elements
		int status;	//Check initialization, 1 initialized, 3 initialized with label, 5 initialized with elements
		std::vector<Bond> bonds;
		std::map<Qnum, Block> blocks;
		std::vector<int>labels;
		void packMeta();
		int RBondNum;	//Row bond number
		int RQdim;
		int CQdim;
		size_t m_elemNum;
		std::map<int, Block*> RQidx2Blk;	//Qidx to the Block
		std::map<int, size_t> QidxEnc;
		std::map<int, size_t> RQidx2Off;	//the row offset starts from the block origin of a qnum
		std::map<int, size_t> CQidx2Off;	//the col offset starts from the block origin of a qnum
		std::map<int, size_t> RQidx2Dim;
		std::map<int, size_t> CQidx2Dim;
    bool ongpu;
		static int COUNTER;
		static int64_t ELEMNUM;
		static size_t MAXELEMNUM;
		static size_t MAXELEMTEN;	//Max number of element of a tensor
		//Private Functions
		void initUniT();
		size_t grouping();
    std::vector<UniTensor> _hosvd(size_t modeNum, size_t fixedNum, std::vector<std::map<Qnum, Matrix> >& Ls, bool returnL)const;
		static const int HAVEBOND = 1;		  /**< A flag for initialization */
		static const int HAVEELEM = 2;		  /**< A flag for having element assigned */
};
UniTensor contract(UniTensor& Ta, UniTensor& Tb, bool fast = false);
UniTensor otimes(const UniTensor& Ta, const UniTensor& Tb);
};	/* namespace uni10 */
#endif /* UNITENSOR_H */