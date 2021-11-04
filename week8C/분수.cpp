#include <iostream>
using namespace std;

class Fraction{
	private:
		int numerator;
		int denominator;
	public:
		Fraction();
		Fraction(int num,int denom);
		void setNumerator(int num);
		void setDenominator(int denom);
		int getNumerator();
		int getDenominator();
		int gcd(int a,int b);
		void print();
		Fraction reduce();
		Fraction add(Fraction r);
};
Fraction::Fraction(){
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int num,int denom){
	numerator = num;
	denominator = denom;
}
void Fraction::setNumerator(int num){
	numerator = num;
}
void Fraction::setDenominator(int denom){
	denominator = denom;
}
int Fraction::getNumerator(){
	return numerator;
}	
int Fraction::getDenominator(){
	return denominator;
}
int Fraction::gcd(int a,int b){
	int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b!= 0) {
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}
void Fraction::print(){
	cout << numerator << "/" << denominator << endl;
}
Fraction Fraction::add(Fraction r){
	Fraction result;
	result.setDenominator(denominator * r.getDenominator());
	result.setNumerator(numerator*r.getDenominator()+r.getNumerator()*denominator);
	int d = gcd(result.getDenominator(), result.getNumerator());
	result.setDenominator(result.getDenominator()/d);
	result.setNumerator(result.getNumerator()/d);
	return result;
}
