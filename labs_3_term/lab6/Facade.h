#pragma once
#include <iostream>
enum Facade
{
	CommonFacade,
	GlassFacade,
	CPBFacade,
	AeratedConcreteFacade
};

inline std::ostream& operator<<(std::ostream & os, Facade source) {
	switch (source)
	{
	case CommonFacade:
		os << "CommonFacade";
	case GlassFacade:
		os << "GlassFacade";
	case CPBFacade:
		os << "CPBFacade";
	case AeratedConcreteFacade:
		os << "AeratedConcreteFacade";
	default:
		break;
	}
	return os;
}