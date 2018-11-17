#include "stdafx.h"
#ifndef BASIC_STRING_H_
#define BASIC_STRING_H_
#include "iostream"
#include "basic_cstring.h"
#include "cstring"
const unsigned int npos = 4294967295;

class basic_string{
public:
	basic_string(const char * aim_str = NULL);
	basic_string(size_t n, char c);
	basic_string(const char * aim_str, size_t n);
	//template <typename Iter>
	//basic_string(Iter begin, Iter end);													// undefined
	basic_string(const basic_string & aim_str, size_t pos = 0, size_t n = npos);	
	~basic_string();
	/*----------------------empty()------------------------------*/
	bool empty() const { if (str == NULL) return true; else return false; }
	/*----------------------assign()-----------------------------*/
	basic_string & assign(size_t count, char * ch);
	basic_string & assign(const basic_string & aim_str);
	basic_string & assign(const char * aim_str);									
	template<typename Iter>
	basic_string & assign(Iter begin, Iter end);										// undefined
	basic_string & assign(basic_string & aim_str, size_t pos = 0, size_t n = npos);		// undefined
	/*---------------------operator = ---------------------------*/
	basic_string & operator=(const char * aim_str);
	basic_string & operator=(const basic_string & aim_str);
	basic_string & operator=(char ch);
	friend std::ostream & operator<<(std::ostream & os, const basic_string & obj);
	friend std::istream & operator>>(std::istream & is, const basic_string & obj);
	friend std::istream & getline(std::istream input, basic_string & aim_str);
	/*---------------------operator += ---------------------------*/
	basic_string & operator+=(const char * aim_str);
	basic_string & operator+=(const basic_string & aim_str);
	basic_string & operator+=(const char ch);
	/*---------------------at()----------------------------------*/
	char & at(size_t pos);
	char at(size_t pos) const;
	/*---------------------operator[] ---------------------------*/
	char & operator[](size_t pos);
	char operator[](size_t pos) const;
	/*---------------------front()-------------------------------*/
	char & front();																		// error
	char front() const;
	/*---------------------back()--------------------------------*/
	char & back();																		// undefined
	char back() const;																	// undefined
	/*---------------------c_str()-------------------------------*/
	char * c_str();
	/*---------------------date()--------------------------------*/
	const char * data() const;															// undefined
	/*---------------------size() length()-----------------------*/
	size_t size() const;
	size_t length() const;
	template<typename _InIt>
	size_t distance(_InIt _First, _InIt _Last);
	/*---------------------clear()--------------------------------*/
	void clear();
	/*---------------------insert()-------------------------------*/
	basic_string & insert(size_t index, size_t count, char ch);
	basic_string & insert(size_t index, const char * aim_str);
	basic_string & insert(size_t index, const char * aim_str, size_t count);
	basic_string & insert(size_t index, basic_string & aim_str);
	//template<typename InputIt>
	//void insert(iterator i, InputIt first, InputIt last);							 	// undefined
	//template<typename InputIt>
	//iterator insert(const_iterator i, InputIt first, InputIt last);                   // undefined
	/*---------------------erase()-------------------------------*/
	basic_string & erase(size_t index = 0, size_t count = npos);
	/*---------------------swap()--------------------------------*/
	void swap(basic_string & other);
	/*---------------------reserve()-------------------------------*/
	void reserve(size_t size = 0);
	/*---------------------capacity()-------------------------------*/
	// size_t capacity() const;															// undefined
	/*---------------------push_back()-------------------------------*/
	void push_back(char ch);
	/*---------------------pop_back()-------------------------------*/
	void pop_back();
	/*---------------------compare()-------------------------------*/
	int compare(const basic_string & aim_str) const;
	int compare(size_t pos1, size_t count1, const basic_string & aim_str, size_t pos2, size_t count2) const;// undefined
	int compare(size_t pos1, size_t count1, const basic_string & aim_str) const;
	int compare(const char * aim_str) const;
	int compare(size_t pos1, size_t count1, const char * aim_str) const;
	/*---------------------replace()-------------------------------*/
	basic_string & replace(size_t pos, size_t count, const basic_string & aim_str);     // Replace from No.(pos + 1) to No.(count + 1)
	basic_string & replace(size_t pos, size_t count, const char * cstr);
	/*---------------------substr()-------------------------------*/
	basic_string substr(size_t pos = 0, size_t count = npos);
	/*---------------------copy()-------------------------------*/
	size_t copy(char * cstr, size_t count, size_t pos = 0);
	/*---------------------resize()-------------------------------*/
	void resize(size_t count);
	/*---------------------find()-------------------------------*/
	size_t find(const basic_string & aim_str, size_t pos = 0) const;
	size_t find(const char * cstr, size_t pos, size_t count) const;
	size_t find(const char * cstr, size_t pos = 0) const;
	size_t find(char ch, size_t pos = 0) const;

private:
	char *str;
};


basic_string::basic_string(const char * aim_str){					//构造函数 2
	if (aim_str != NULL){
		str = new char[basic_strlen(aim_str) + 10];
		basic_strcpy(str, aim_str);
	}
	else {
		str = new char[1];
		str = NULL;
	}
}

basic_string::basic_string(size_t n, char c){
	str = new char[n + 10];
	for (size_t i = 0; i < n; i++)
		str[i] = c;
	str[n] = '\0';
	//delete[] str;
}
basic_string::basic_string(const char * aim_str, size_t n){
	if (basic_strlen(aim_str) < n)
		n = basic_strlen(aim_str);
	str = new char[n + 10];
	for (size_t i = 0; i < n; i++){
		str[i] = aim_str[i];
	}
	str[n] = '\0';
}
basic_string::basic_string(const basic_string & aim_str, size_t pos, size_t n){
	str = new char[basic_strlen(aim_str.str) + 10];
	size_t count = 0;
	for (; aim_str[pos] && pos < n; pos++)
		str[count++] = aim_str[pos];
	size_t cnt = aim_str.size();
	if (cnt > n)
		cnt = n;
	str[cnt] = '\0';
}

/*
template<typename Iter>
basic_string::basic_string(Iter begin, Iter end){
	str = new char[basic_strlen(end) + 1];
	//for (int i = 0; begin[i])
}*/
basic_string::~basic_string(){		//析构函数
	delete str;
}
/*  operator  = */
basic_string & basic_string::operator=(const char * aim_str){
	if (aim_str != NULL){
		str = new char[basic_strlen(aim_str) + 10];
		for (int i = 0; aim_str[i]; i++){
			str[i] = aim_str[i];
		}
		str[basic_strlen(aim_str)] = '\0';
	}
	else {
		str = new char[1];
		str = '\0';
	}
	return *this;
}

basic_string & basic_string::operator=(const basic_string & aim_str){
	if (aim_str.str != NULL){
		str = new char[aim_str.size() + 10];
		for (int i = 0; aim_str.str[i]; i++){
			str[i] = aim_str.str[i];
		}
		str[aim_str.size()] = '\0';
	}
	else {
		str = new char[1];
		str = '\0';
	}
	return *this;
}

basic_string & basic_string::operator=(char ch){
	str = new char[10];
	str[0] = ch;
	str[1] = '\0';
	return *this;
}
/* assign() function && operator function*/
basic_string & basic_string::assign(size_t count, char * ch){
	if (basic_strlen(ch) < count)
		count = basic_strlen(ch);
	str = new char[count + 10];
	for (size_t i = 0; i < count; i++){
		str[i] = ch[i];
	}
	ch[count] = '\0';
	return *this;
}
basic_string & basic_string::assign(const basic_string & aim_str){
	str = aim_str.str;
	return *this;
}
basic_string & basic_string::assign(const char * aim_str){
	if (aim_str != NULL){
		str = new char[basic_strlen(aim_str) + 10];
		for (int i = 0; aim_str[i]; i++){
			str[i] = aim_str[i];
		}
		str[basic_strlen(aim_str)] = '\0';
		return *this;
	}
	else{
		str = new char[1];
		str[0] = '\0';
		return *this;
	}
}
std::ostream & operator<<(std::ostream & os, const basic_string & obj){
	os << obj.str;
	return os;
}
std::istream & operator>>(std::istream & is, const basic_string & obj){
	is >> obj.str;
	return is;
}
std::istream & getline(std::istream input, basic_string & aim_str){
	input >> aim_str.str;
	return input;
}
/* at()  */
char & basic_string::at(size_t pos){
		return str[pos];
}
char basic_string::at(size_t pos) const {
		return str[pos + 1];
}
/* operator[] */
char & basic_string::operator[](size_t pos){
	return str[pos];
}
char basic_string::operator[](size_t pos) const{
	return str[pos];
}
/* front() */
char & basic_string::front(){
		return str[0];
}			
char basic_string::front() const{
	if (!empty())
		return str[0];
	else
		return NULL;
}
/* back() */
char & basic_string::back(){
	return str[size() - 1];
}
char basic_string::back() const {
	return str[size() - 1];
}
/* c_str() */
char * basic_string::c_str(){
	char *str_new = new char[basic_strlen(str) + 10];
	for (int i = 0; i < str[i]; i++)
		str_new[i] = str[i];
	str_new[basic_strlen(str)] = '\0';
	return str_new;
}
/* length() size() */
size_t basic_string::size() const {
	return basic_strlen(str);
}
size_t basic_string::length() const {
	return size();
}
/* clear() */
void basic_string::clear(){
	delete str;
}
/* insert() */
basic_string & basic_string::insert(size_t index, size_t count, char ch){
	char *str_new = new char[basic_strlen(str) + count + 10];
	size_t i;
	for (i = 0; i < index; i++)
		str_new[i] = str[i];
	size_t ct = i;
	for (size_t j = 0; j < count; j++, i++)
		str_new[i] = ch;
	for (; str[ct]; ct++,i++){
		str_new[i] = str[ct];
	}
	str_new[basic_strlen(str) + count + 10] = '\0';
	delete str;
	str = new char[basic_strlen(str_new) + 1];
	for (size_t cnt = 0; str_new[cnt]; cnt++)
		str[cnt] = str_new[cnt];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::insert(size_t index, const char * aim_str){
	char * str_new = new char[basic_strlen(str) + basic_strlen(aim_str) + 10];
	size_t i;
	for (i = 0; i < index; i++)
		str_new[i] = str[i];
	size_t ct = i;
	for (int j = 0; aim_str[j]; j++, i++)
		str_new[i] = aim_str[j];
	for (; str[ct]; ct++, i++)
		str_new[i] = str[ct];
	str_new[basic_strlen(str) + basic_strlen(aim_str)] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t cnt = 0; str_new[cnt]; cnt++)
		str[cnt] = str_new[cnt];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::insert(size_t index, const char * aim_str, size_t count){
	if (count > basic_strlen(aim_str))
		count = basic_strlen(aim_str);
	char * str_new = new char[basic_strlen(str) + basic_strlen(aim_str) + 10];
	size_t i;
	for (i = 0; i < index; i++)
		str_new[i] = str[i];
	size_t ct = i;
	for (size_t j = 0; j < count; j++, i++)
		str_new[i] = aim_str[j];
	for (; str[ct]; ct++, i++)
		str_new[i] = str[ct];
	str_new[basic_strlen(str) + basic_strlen(aim_str)] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t cnt = 0; str_new[cnt]; cnt++)
		str[cnt] = str_new[cnt];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::insert(size_t index, basic_string & aim_str){
	char * str_new = new char[basic_strlen(str) + aim_str.size() + 10];
	size_t i;
	for (i = 0; i < index; i++)
		str_new[i] = str[i];
	size_t ct = i;
	for (int j = 0; aim_str[j]; j++, i++)
		str_new[i] = aim_str.str[j];
	for (; str[ct]; ct++, i++)
		str_new[i] = str[ct];
	str_new[basic_strlen(str) + aim_str.size()] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t cnt = 0; str_new[cnt]; cnt++)
		str[cnt] = str_new[cnt];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
/* erase() */
basic_string & basic_string::erase(size_t index, size_t count){
	size_t cnt = 0;
	for (size_t i = 0; str[i]; i++){
		if (i == index)
			i += count;
		str[cnt++] = str[i];
	}
	str[cnt] = '\0';
	return *this;
}
/* swap() */
void basic_string::swap(basic_string & other){
	basic_string temp(str);
	str = other.str;
	other = temp.str;
}
/* reserve() */
void basic_string::reserve(size_t size){
	str = new char[size];
}
/* push_back() */
void basic_string::push_back(char ch){
	str[basic_strlen(str)] = ch;
	str[basic_strlen(str) + 1] = '\0';
}
/* pop_back() */
void basic_string::pop_back(){
	str[basic_strlen(str) - 1] = '\0';
}
/* operator += */
basic_string & basic_string::operator+=(const char * aim_str){
	char *str_new = new char[basic_strlen(str) + basic_strlen(aim_str) + 10];
	size_t i;
	for (i = 0; str[i]; i++)
		str_new[i] = str[i];
	for (size_t ct = 0; aim_str[ct]; ct++, i++)
		str_new[i] = aim_str[ct];
	str_new[basic_strlen(str) + basic_strlen(aim_str)] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t i = 0; str_new[i]; i++)
		str[i] = str_new[i];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::operator+=(const basic_string & aim_str){
	char *str_new = new char[basic_strlen(str) + basic_strlen(aim_str.str) + 10];
	size_t i;
	for (i = 0; str[i]; i++)
		str_new[i] = str[i];
	for (size_t ct = 0; aim_str.str[ct]; ct++, i++)
		str_new[i] = aim_str.str[ct];
	str_new[basic_strlen(str) + basic_strlen(aim_str.str)] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t i = 0; str_new[i]; i++)
		str[i] = str_new[i];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::operator+=(const char ch){
	char *str_new = new char[size() + 10];
	for (size_t i = 0; str[i]; i++)
		str_new[i] = str[i];
	str_new[size()] = ch;
	str_new[size() + 1] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t i = 0; str_new[i]; i++)
		str[i] = str_new[i];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
/* compare() */
int basic_string::compare(const basic_string & aim_str) const {
	return basic_strcmp(str, aim_str.str);
}
int basic_string::compare(size_t pos1, size_t count1, const basic_string & aim_str) const {
	basic_string st_str(aim_str, pos1, count1);
	return basic_strcmp(str, st_str.str);
}
int basic_string::compare(const char * aim_str) const {
	return basic_strcmp(str, aim_str);
}
int basic_string::compare(size_t pos1, size_t count1, const char * aim_str) const {
	basic_string st_str(aim_str, pos1, count1);
	return basic_strcmp(str, st_str.str);
}
/* replace() */
basic_string & basic_string::replace(size_t pos, size_t count, const basic_string & aim_str){
	if (count > size())
		count = size();
	size_t i;
	char *str_new = new char[size() + aim_str.size() + 10];
	for (i = 0; i < pos; i++)
		str_new[i] = str[i];
	for (size_t ct = 0; aim_str[i]; ct++, i++)
		str_new[i] = aim_str[ct];
	for (; str[count]; i++, count++)
		str_new[i] = str[count];
	str_new[i] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t i = 0; str_new[i]; i++)
		str[i] = str_new[i];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
basic_string & basic_string::replace(size_t pos, size_t count, const char * cstr){
	if (count > size())
		count = size();
	size_t i;
	char *str_new = new char[size() + basic_strlen(cstr) + 10];
	for (i = 0; i < pos; i++)
		str_new[i] = str[i];
	for (size_t ct = 0; cstr[i]; ct++, i++)
		str_new[i] = cstr[ct];
	for (; str[count]; i++, count++)
		str_new[i] = str[count];
	str_new[i] = '\0';
	delete[] str;
	str = new char[basic_strlen(str_new) + 10];
	for (size_t i = 0; str_new[i]; i++)
		str[i] = str_new[i];
	str[basic_strlen(str_new)] = '\0';
	delete[] str_new;
	return *this;
}
/* substr() */
basic_string basic_string::substr(size_t pos, size_t count){
	basic_string re_str;
	size_t ct = 0;
	size_t cnt = size();
	if (count < cnt)
		cnt = count;
	re_str.reserve(cnt + 10);
	for (size_t i = 0; i < cnt && str[pos]; pos++, i++)
		re_str.str[ct++] = str[pos];
	re_str.str[ct] = '\0';
	return re_str;
}
/* copy() */
size_t basic_string::copy(char * cstr, size_t count, size_t pos){
	size_t len = size();
	if (len > count)
		len = count;
	size_t cnt = 0;
	for (size_t i = 0; i < len && str[pos]; pos++){
		cstr[cnt++] = str[pos];
	}
	cstr[cnt] = '\0';
	return cnt;
}
/* resize() */
void basic_string::resize(size_t count){
	if (size() > count)
		str[count] = '\0';
}
/* find() */
size_t basic_string::find(const basic_string & aim_str, size_t pos) const{
	for (size_t pos = 0; pos < size(); pos++){
		if (str[pos] == aim_str.str[pos]){
			bool flag = true;
			for (size_t j = pos, ct = 0; aim_str.str[pos]; j++, ct++){
				if (str[j] != aim_str.str[ct]){
					flag = false;
					break;
				}
			}
			if (flag) 
				return pos;
		}
	}
	return npos;
}
size_t basic_string::find(const char * cstr, size_t pos, size_t count) const {
	for (size_t pos = 0; pos < size(); pos++){
		if (str[pos] == cstr[pos]){
			bool flag = true;
			for (size_t j = pos, ct = 0; ct < count; j++, ct++){
				if (str[j] != cstr[ct]){
					flag = false;
					break;
				}
			}
			if (flag)
				return pos;
		}
	}
	return npos;
}
size_t basic_string::find(char ch, size_t pos) const {
	for (; str[pos]; pos++){
		if (str[pos] == ch)
			return pos;
	}
	return npos;
}
size_t basic_string::find(const char * cstr, size_t pos) const {
	for (size_t pos = 0; pos < size(); pos++){
		if (str[pos] == cstr[pos]){
			bool flag = true;
			for (size_t j = pos, ct = 0; cstr[pos]; j++, ct++){
				if (str[j] != cstr[ct]){
					flag = false;
					break;
				}
			}
			if (flag)
				return pos;
		}
	}
	return npos;
}









/*================================std_operator+()===================================*/


basic_string operator+(basic_string & str_1, basic_string & str_2){
	basic_string re_str = str_1;
	re_str += str_2;
	return re_str;
}
basic_string operator+(char * cstr, basic_string & str){
	basic_string re_str;
	re_str.assign(cstr);
	re_str += str;
	return re_str;
}
basic_string operator+(char ch, basic_string & str){
	basic_string re_str;
	re_str = ch;
	re_str += str;
	return re_str;
}
basic_string operator+(basic_string & str, char * cstr){
	basic_string re_str = str;
	re_str += cstr;
	return re_str;
}
basic_string operator+(basic_string & str, char ch){
	basic_string re_str = str;
	re_str += ch;
	return re_str;
}
bool operator==(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) == 0)
		return true;
	else
		return false;
}
bool operator!=(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) != 0)
		return true;
	else
		return false;
}
bool operator<(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) == -1)
		return true;
	else
		return false;
}
bool operator<=(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) == -1 || str_1.compare(str_2) == 0)
		return true;
	else
		return false;
}
bool operator>(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) == 1)
		return true;
	else
		return false;
}
bool operator>=(basic_string & str_1, basic_string & str_2){
	if (str_1.compare(str_2) == 1 || str_1.compare(str_2) == 0)
		return true;
	else
		return false;
}
void swap(basic_string & str_1, basic_string & str_2){
	basic_string temp_str = str_1;
	str_1.clear();
	str_1 = str_2;
	str_2.clear();
	str_2 = temp_str;
}

int stoi(const basic_string & aim_str, size_t pos = 0, int base = 10){
	char *temp_cstr = new char[aim_str.size() + 10];
	size_t ct = 0;
	for (; pos < aim_str.size(); pos++)
		temp_cstr[ct++] = aim_str[pos];
	temp_cstr[ct] = '\0';

	char *cstr = new char[aim_str.size() + 10];
	bool flag = true;
	size_t cnt = 0;
	char point = '0';

	for (size_t i = 0; i < basic_strlen(temp_cstr); i++){
		if (isgraph(temp_cstr[i]) && flag){
			if (temp_cstr[i] == '-'){
				point = temp_cstr[i];
				i++;
			}
			cstr[cnt++] = temp_cstr[i];
			flag = false;
		}
		else
			cstr[cnt++] = temp_cstr[i];
	}
	cstr[cnt] = '\0';
	delete[] temp_cstr;

	size_t len = basic_strlen(cstr);
	int re_num = 0, temp;
	if (cstr[0] == '0' && (cstr[1] != '0' && cstr[1] != 'x' && cstr[1] != 'X'))
		base = 8;
	else if (cstr[0] == '0' && (cstr[1] == 'x' || cstr[1] == 'X'))
		base = 16;

	for (size_t i = 0; i < len; i++){
		if (cstr[i] >= '0' && cstr[i] <= '9')
			temp = cstr[i] - '0';
		else if (base >= 11 && (cstr[i] >= 'A' && cstr[i] <= 'A' + base - 10))
			temp = cstr[i] - 'A' + 10;
		else if (base >= 11 && (cstr[i] >= 'a' && cstr[i] <= 'a' + base - 10))
			temp = cstr[i] - 'a' + 10;
		re_num = re_num * base + temp;
	}
	if (point == '-')
		return -re_num;
	else
		return re_num;

}
long stol(const basic_string & aim_str, size_t pos = 0, int base = 10){
	char *temp_cstr = new char[aim_str.size() + 10];
	size_t ct = 0;
	for (; pos < aim_str.size(); pos++)
		temp_cstr[ct++] = aim_str[pos];
	temp_cstr[ct] = '\0';

	char *cstr = new char[aim_str.size() + 10];
	bool flag = true;
	size_t cnt = 0;
	char point = '0';

	for (size_t i = 0; i < basic_strlen(temp_cstr); i++){
		if (isgraph(temp_cstr[i]) && flag){
			if (temp_cstr[i] == '-'){
				point = temp_cstr[i];
				i++;
			}
			cstr[cnt++] = temp_cstr[i];
			flag = false;
		}
		else
			cstr[cnt++] = temp_cstr[i];
	}
	cstr[cnt] = '\0';
	delete[] temp_cstr;

	size_t len = basic_strlen(cstr);
	long re_num = 0, temp;
	if (cstr[0] == '0' && (cstr[1] != '0' && cstr[1] != 'x' && cstr[1] != 'X'))
		base = 8;
	else if (cstr[0] == '0' && (cstr[1] == 'x' || cstr[1] == 'X'))
		base = 16;

	for (size_t i = 0; i < len; i++){
		if (cstr[i] >= '0' && cstr[i] <= '9')
			temp = cstr[i] - '0';
		else if (base >= 11 && (cstr[i] >= 'A' && cstr[i] <= 'A' + base - 10))
			temp = cstr[i] - 'A' + 10;
		else if (base >= 11 && (cstr[i] >= 'a' && cstr[i] <= 'a' + base - 10))
			temp = cstr[i] - 'a' + 10;
		re_num = re_num * base + temp;
	}
	if (point == '-')
		return -re_num;
	else
		return re_num;

}
long long stoll(const basic_string & aim_str, size_t pos = 0, int base = 10){
	char *temp_cstr = new char[aim_str.size() + 10];
	size_t ct = 0;
	for (; pos < aim_str.size(); pos++)
		temp_cstr[ct++] = aim_str[pos];
	temp_cstr[ct] = '\0';

	char *cstr = new char[aim_str.size() + 10];
	bool flag = true;
	size_t cnt = 0;
	char point = '0';

	for (size_t i = 0; i < basic_strlen(temp_cstr); i++){
		if (isgraph(temp_cstr[i]) && flag){
			if (temp_cstr[i] == '-'){
				point = temp_cstr[i];
				i++;
			}
			cstr[cnt++] = temp_cstr[i];
			flag = false;
		}
		else
			cstr[cnt++] = temp_cstr[i];
	}
	cstr[cnt] = '\0';
	delete[] temp_cstr;

	size_t len = basic_strlen(cstr);
	long long re_num = 0, temp;
	if (cstr[0] == '0' && (cstr[1] != '0' && cstr[1] != 'x' && cstr[1] != 'X'))
		base = 8;
	else if (cstr[0] == '0' && (cstr[1] == 'x' || cstr[1] == 'X'))
		base = 16;

	for (size_t i = 0; i < len; i++){
		if (cstr[i] >= '0' && cstr[i] <= '9')
			temp = cstr[i] - '0';
		else if (base >= 11 && (cstr[i] >= 'A' && cstr[i] <= 'A' + base - 10))
			temp = cstr[i] - 'A' + 10;
		else if (base >= 11 && (cstr[i] >= 'a' && cstr[i] <= 'a' + base - 10))
			temp = cstr[i] - 'a' + 10;
		re_num = re_num * base + temp;
	}
	if (point == '-')
		return -re_num;
	else
		return re_num;

}
unsigned long stoul(const basic_string & aim_str, size_t pos = 0, int base = 10){
	char *temp_cstr = new char[aim_str.size() + 10];
	size_t ct = 0;
	for (; pos < aim_str.size(); pos++)
		temp_cstr[ct++] = aim_str[pos];
	temp_cstr[ct] = '\0';

	char *cstr = new char[aim_str.size() + 10];
	bool flag = true;
	size_t cnt = 0;

	for (size_t i = 0; i < basic_strlen(temp_cstr); i++){
		if (isgraph(temp_cstr[i]) && flag){
			cstr[cnt++] = temp_cstr[i];
			flag = false;
		}
		else
			cstr[cnt++] = temp_cstr[i];
	}
	cstr[cnt] = '\0';
	delete[] temp_cstr;

	size_t len = basic_strlen(cstr);
	unsigned long re_num = 0, temp;
	if (cstr[0] == '0' && (cstr[1] != '0' && cstr[1] != 'x' && cstr[1] != 'X'))
		base = 8;
	else if (cstr[0] == '0' && (cstr[1] == 'x' || cstr[1] == 'X'))
		base = 16;

	for (size_t i = 0; i < len; i++){
		if (cstr[i] >= '0' && cstr[i] <= '9')
			temp = cstr[i] - '0';
		else if (base >= 11 && (cstr[i] >= 'A' && cstr[i] <= 'A' + base - 10))
			temp = cstr[i] - 'A' + 10;
		else if (base >= 11 && (cstr[i] >= 'a' && cstr[i] <= 'a' + base - 10))
			temp = cstr[i] - 'a' + 10;
		re_num = re_num * base + temp;
	}
	return re_num;
}
unsigned long long stoull(const basic_string & aim_str, size_t pos = 0, int base = 10){
	char *temp_cstr = new char[aim_str.size() + 10];
	size_t ct = 0;
	for (; pos < aim_str.size(); pos++)
		temp_cstr[ct++] = aim_str[pos];
	temp_cstr[ct] = '\0';

	char *cstr = new char[aim_str.size() + 10];
	bool flag = true;
	size_t cnt = 0;

	for (size_t i = 0; i < basic_strlen(temp_cstr); i++){
		if (isgraph(temp_cstr[i]) && flag){
			cstr[cnt++] = temp_cstr[i];
			flag = false;
		}
		else
			cstr[cnt++] = temp_cstr[i];
	}
	cstr[cnt] = '\0';
	delete[] temp_cstr;

	size_t len = basic_strlen(cstr);
	unsigned long long re_num = 0, temp;
	if (cstr[0] == '0' && (cstr[1] != '0' && cstr[1] != 'x' && cstr[1] != 'X'))
		base = 8;
	else if (cstr[0] == '0' && (cstr[1] == 'x' || cstr[1] == 'X'))
		base = 16;

	for (size_t i = 0; i < len; i++){
		if (cstr[i] >= '0' && cstr[i] <= '9')
			temp = cstr[i] - '0';
		else if (base >= 11 && (cstr[i] >= 'A' && cstr[i] <= 'A' + base - 10))
			temp = cstr[i] - 'A' + 10;
		else if (base >= 11 && (cstr[i] >= 'a' && cstr[i] <= 'a' + base - 10))
			temp = cstr[i] - 'a' + 10;
		re_num = re_num * base + temp;
	}
	return re_num;
}
basic_string to_string(long double value){
	char num_str_1[20];
	sprintf(num_str_1, "%f", value);
	int len = basic_strlen(num_str_1);
	for (int i = len - 1; i > 0; i--){
		if (num_str_1[i] == '\0')
			continue;
		else if (num_str_1[i] == '0')
			num_str_1[i] = '\0';
		else if (num_str_1[i] == '.'){
			num_str_1[i] = '\0';
			break;
		}
		else
			break;
	}
	basic_string re_str = num_str_1;
	return re_str;
}


#endif

	