#ifndef _Student_H_
#define _Student_H_
#include <iostream>
#include <vector>
#include <map>

namespace Students {

	class Student { // абстрактный базовый класс
	protected:
		std::string  f_name;
		std::string  name;
		int kol;
		std::map <std::string, int> marks;
		virtual std::ostream& show(std::ostream&)const = 0;
		virtual std::istream& get(std::istream&) = 0;
	public:
		Student() { kol = 0; f_name = '\0'; name = '\0'; marks = {}; }
		Student(int kol0, std::string  f_name0, std::string  name0, std::map <std::string, int> marks0) :
			kol(kol0), f_name(f_name0), name(name0), marks(marks0) {};

		virtual Student* clone()const = 0;
		std::string getFN() const { return f_name; }
		std::string getN() const { return name; }
		int getK() const { return kol; }
		std::map <std::string, int> getA() const { return marks; }

		Student & setFN(std::string a) { f_name = a; return *this; }
		Student & setN(std::string a) { name = a; return *this; }
		Student & setK(int a) { kol = a; return *this; }

		friend std::ostream& operator <<(std::ostream &, const Student &);
		friend std::istream& operator >>(std::istream &, Student &);

		virtual int get_type()const = 0;
		virtual std::map <std::string, int> get_marks()const = 0;
		virtual void add_marks(std::string &, int n, int q) = 0;
		virtual ~Student() {}
	};

};
#endif


