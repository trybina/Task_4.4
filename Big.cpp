#include <iostream>
#include <math.h>
#include "Student.h"
#include "Small.h"
#include "Big.h"
#include <string>
#include <vector>

namespace Students {

	std::ostream& Big::show(std::ostream& os)const
	{
		return os << "Big student; first name - " << getFN() << ", name - " << getN()
			<< ", number of marks - " << getK() << ", work - " << getW() << ", place - " << getPL() << ", mark - " << getM();
	}

	std::istream& Big::get(std::istream& is)
	{
		return is >> f_name >> name >> work >> place >> mark;
	}

	std::map <std::string, int> Big::get_marks() const
	{
		return marks;
	}

	void Big::add_marks(std::string &s, int n, int q)
	{
		if (kol < q)
		{
			marks.insert(make_pair(s, n));
			kol++;
		}
	}

	std::string Big::get_work()
	{
		return work;
	}

	std::string Big::get_place()
	{
		return place;
	}

	int Big::get_mark()const
	{
		return mark;
	}

	Big & Big::add_mark(int m)
	{
		mark = m;
		return *this;
	}

	Big & Big::add_place(std::string pl)
	{
		place = pl;
		return *this;
	}

	Big & Big::add_work(std::string w)
	{
		work = w;
		return *this;
	}
};

