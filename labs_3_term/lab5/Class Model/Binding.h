///////////////////////////////////////////////////////////
//  Binding.h
//  Implementation of the Enumeration Binding
//  Created on:      16-окт.-2017 18:32:48
//  Original author: Никита
///////////////////////////////////////////////////////////
#if !defined(EA_37F41B58_B50F_4f95_B197_AF7C013453F1__INCLUDED_)
#define EA_37F41B58_B50F_4f95_B197_AF7C013453F1__INCLUDED_
#include <string>
#include <iostream>
enum Binding
{
	HardBinding,
	SoftBinding,
	DutchBinding,
	IntegralBinding
};

inline std::ostream& operator <<(std::ostream & os, Binding & source) {
	switch (source)
	{
	case HardBinding:		
		os << "HardBinding";
		break;
	case SoftBinding:
		os << "SoftBinding";
	case DutchBinding:
		os << "DutchBinding";
	case IntegralBinding:
		os << "IntegralBinding";
	default:
		break;
	}
	return os;
}
#endif // !defined(EA_37F41B58_B50F_4f95_B197_AF7C013453F1__INCLUDED_)
