#include <iostream>
#include <math.h>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include <string>
#include <vector>

namespace Students {

	std::ostream & operator <<(std::ostream &os, const std::pair<std::string, int> &p) {

		return os << '"' << p.first << '"' << " - " << p.second << std::endl;
	}

	std::ostream& operator <<(std::ostream &os, const Student &p)
	{
		return p.show(os);
	}

	std::istream& operator >>(std::istream &is, Student &p)
	{
		return p.get(is);
	}

};

