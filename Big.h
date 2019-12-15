#ifndef _Big_H_
#define _Big_H_
#include <iostream>
#include "Student.h"
#include <vector>
#include <map>

namespace Students {

	class Big :public Student { // производный класс
	protected:
		std::string work;
		std::string place;
		int mark;
		virtual std::ostream& show(std::ostream&)const;
		virtual std::istream& get(std::istream&);
	public:
		Big() :Student() {
			work = "\0";
			place = "\0";
			mark = 0;
		};
		Big(int kol0, std::string  f_name0, std::string  name0, std::map <std::string, int> marks0, std::string work0, std::string place0, int mark0) :
			Student(kol0, f_name0, name0, marks0) {
			work = work0;
			place = place0;
			mark = mark0;
		}
		std::string  getW() const { return work; }
		std::string  getPL() const { return place; }
		int getM() const { return mark; }

		virtual Big* clone()const
		{
			return new Big(*this);
		}

		virtual int get_type()const { return 2; }
		virtual std::map <std::string, int> get_marks()const;
		virtual void add_marks(std::string &, int n, int q);
		Big & add_work(std::string w);
		std::string get_work();
		Big & add_place(std::string pl);
		std::string get_place();
		Big & add_mark(int m);
		int get_mark()const;
	};

};
#endif



