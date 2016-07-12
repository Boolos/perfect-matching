#include "polynomial.hpp"

/**
 * Returns true if the value is between -csce::EPS and csce::EPS,
 * otherwise false is returned.
 */
bool csce::iszero(long double value){
	return std::fabsl(value) <= csce::EPS;
}

/**
 * Returns true if the values of a and b differ by at most
 * csce::EPS and returns false otherwise.
 */
bool csce::isequal(long double a, long double b){
	return std::fabsl(a - b) <= csce::EPS;
}

/**
 * Returns a new polynomial with a constant term (degree 0) with the
 * specified coefficient.
 */
csce::polynomial csce::polynomial::value_of(long double coefficient) {
	csce::polynomial self;
	self.terms[{}] = coefficient;
	return self;
}

/**
 * Returns the textual representation of this polynomial as a string.
 */
std::string csce::polynomial::str() const {
	int x=0;
	std::stringstream output;
	for(auto& it : this->terms){
		if(csce::iszero(it.second)){
			//a zero coefficient would result in a value of zero for this term, so skip printing it
			continue;
		}
		
		if(x > 0){
			output << " + ";
		}
		
		if(!csce::isequal(it.second, 1.0L) || it.first.size() == 0){
			output << it.second; //print the coefficient
		}
		
		
		std::map<char, int> ordered_map;
		for(auto& term : it.first){
			ordered_map[term.first] = term.second;
		}
		
		for(auto& term : ordered_map){
			if(term.second == 0){
				continue; //x^0 is 1
			} else if(term.second == 1){
				output << term.first; //x^1 is x
			} else {
				output << "(" << term.first << "^" << term.second << ")";
			}
		}
		x++;
	}
	
	return output.str();
}

csce::polynomial csce::polynomial::add(const csce::polynomial& other) const {
	csce::polynomial result;
	result.terms = this->terms;
	
	for(auto it = other.terms.begin(); it != other.terms.end(); it++){
		auto term = result.terms.find (it->first);
		if(term == other.terms.end()){
			result.terms[it->first] = it->second;
		} else {
			result.terms[it->first] += it->second;
		}
		
		if(csce::iszero(result.terms[it->first])){
			//the coefficient is zero, so remove this
			result.terms.erase(it->first);
		}
	}
	
	return result;
}

csce::polynomial csce::polynomial::subtract(const csce::polynomial& other) const {
	csce::polynomial result;
	result.terms = this->terms;
	
	for(auto& it : other.terms){
		auto term = result.terms.find (it.first);
		if(term == other.terms.end()){
			result.terms[it.first] = -it.second;
		} else {
			result.terms[it.first] -= it.second;
		}
		
		if(csce::iszero(result.terms[it.first])){
			//the coefficient is zero, so remove this
			result.terms.erase(it.first);
		}
	}
	
	return result;
}

/**
 * Multiplies this polynomial with the polynomial <param>other</param> and returns
 * the product as a new polynomial.
 */
csce::polynomial csce::polynomial::multiply(const csce::polynomial& other) const {
	csce::polynomial result;
	
	for(auto& a : this->terms){
		for(auto& b : other.terms){
			long double coefficient = a.second * b.second;
			if(!csce::iszero(coefficient)){
				std::unordered_map<char, int> terms;
				
				//add terms that only exist in polynomial A and also terms that exist
				//in both polynomials A and B
				for(auto& aterm : a.first){
					auto term = b.first.find(aterm.first);
					if(term == b.first.end()){
						if(aterm.second != 0){
							terms[aterm.first] = aterm.second;
						}
					} else {
						int exponent = aterm.second + b.first.at(aterm.first);
						if(exponent != 0){
							terms[aterm.first] = exponent;
						}
					}
				}
				
				//now only add the terms that were not found in polynomial A
				for(auto& bterm : b.first){
					auto term = terms.find(bterm.first);
					if(term == terms.end()){
						if(bterm.second != 0){
							terms[bterm.first] = bterm.second;
						}
					}
				}
				
				if(result.terms.find(terms) != result.terms.end()){
					//the term already exists, so this term will have to be added
					//to the existing term
					coefficient += result.terms[terms];
					if(csce::iszero(coefficient)){
						//the term has become zero, so remove it from the expression
						result.terms.erase(terms);
					} else {
						//the term is non-zero, so update the coefficient
						result.terms[terms] = coefficient;
					}
				} else {
					//this is a new term, so add it
					result.terms[terms] = coefficient;
				}
			}
		}
	}
	
	return result;
}

/**
 * Performs a division of this polynomial by the polynomial <param>b</param> and returns a pair of polynomials
 * such that the first polynomial in the pair is the quotient and the
 * second element in the pair is the remainder.
 */
std::pair<csce::polynomial, csce::polynomial> csce::polynomial::divide(const csce::polynomial& b) const {
	csce::polynomial q;
	csce::polynomial r = *this;
	
	int d = b.degree();
	long double c = b.leading_coefficient();
	
	while(r.degree() >= d && !r.iszero()){
		csce::polynomial s;
		//TODO: this is fine for univariate polynomials, but the 'x' term should really come from the polynomial
		//      and it should also support multivariate polynomials
		s.terms[{{'x', r.degree() - d}}] = r.leading_coefficient() / c;
		q = q + s;
		r = r - s * b;
	}
	
	return std::make_pair(q, r);
}

/**
 * Returns the degree of the polynomial. The degree of
 * a monomial is the sum of the exponents of each term in the
 * monomial. The degree of a polynomial then is the maximum
 * degree over all monomials in the polynomial.
 */
int csce::polynomial::degree() const {
	int degree = std::numeric_limits<int>::min();
	for(auto& term : this->terms){
		int sum = 0;
		for(auto& var : term.first){
			sum += var.second;
		}
		degree = std::max(degree, sum);
	}
	return degree == std::numeric_limits<int>::min() ? 0 : degree;
}

/**
 * Returns the coefficient of the monomial with the highest
 * degree (see polynomial::degree).
 */
long double csce::polynomial::leading_coefficient() const {
	int degree = std::numeric_limits<int>::min();
	long double coefficient = 0.0L;
	for(auto& term : this->terms){
		int sum = 0;
		for(auto& var : term.first){
			sum += var.second;
		}
		if(sum > degree){
			degree = sum;
			coefficient = term.second;
		}
	}
	return degree == std::numeric_limits<int>::min() ? 0 : coefficient;
}

bool csce::polynomial::iszero() const {
	for(auto& term : this->terms){
		if(!csce::iszero(term.second)){
			return false;
		}
	}
	return true;
}


csce::polynomial_gcd_t csce::polynomial::gcd(const csce::polynomial& b) const {
	csce::polynomial_gcd_t result;
	
	csce::polynomial rprev = (*this);
	csce::polynomial rcurr = b;
	
	csce::polynomial sprev = csce::polynomial::value_of(1);
	csce::polynomial scurr = csce::polynomial::value_of(0);
	
	csce::polynomial tprev = csce::polynomial::value_of(0);
	csce::polynomial tcurr = csce::polynomial::value_of(1);
	
	while(!rcurr.iszero()){
		csce::polynomial r = rcurr;
		csce::polynomial s = scurr;
		csce::polynomial t = tcurr;
		
		std::pair<csce::polynomial, csce::polynomial> div = rprev / rcurr;
		csce::polynomial q = div.first;
		rcurr = rprev - q * rcurr;
		scurr = sprev - q * scurr;
		tcurr = tprev - q * tcurr;
		
		rprev = r;
		sprev = s;
		tprev = t;
	}
	
	result.gcd = rprev;
	result.u = sprev;
	result.v = tprev;
	
	return result;
}

void csce::polynomial::replace(char var, int value) {
	for(auto& term : this->terms){
		for(auto& v : term.first){
            if (v.first == var) {
                this->terms.erase(term.first);
            }
		}
	}
}