///////////////////////////////////////////////////////////
//  Cover.h
//  Implementation of the Class Cover
//  Created on:      16-окт.-2017 18:32:49
//  Original author: Никита
///////////////////////////////////////////////////////////

#if !defined(EA_EA27ED9B_6019_4ebc_9195_69BD94818464__INCLUDED_)
#define EA_EA27ED9B_6019_4ebc_9195_69BD94818464__INCLUDED_

#include "IShowable.h"
#include <string>

class Cover : public IShowable
{

public:
	Cover();
	Cover(std::string preview, bool hasImages);
	virtual ~Cover();

	void Show();

private:
	bool hasImages;
	std::string preview;

};
#endif // !defined(EA_EA27ED9B_6019_4ebc_9195_69BD94818464__INCLUDED_)
