#include "polynomial.hpp"

bool csce::iszero(long double value){
	return std::fabsl(value) <= csce::EPS;
}

csce::polynomial csce::polynomial::value_of(long double coefficient) {
	csce::polynomial self;
	self.terms[{}] = coefficient;
	return self;
}

std::string csce::polynomial::str() const {
	int x=0;
	std::stringstream output;
	for(auto& it : (*this).terms){
		if(x > 0){
			output << " + ";
		}
		output << it.second; //print the coefficient
		
		std::map<char, int> ordered_map;
		for(auto& term : it.first){
			ordered_map[term.first] = term.second;
		}
		
		for(auto& term : ordered_map){
			output << "(" << term.first << "^" << term.second << ")";
		}
		x++;
	}
	
	return output.str();
}

csce::polynomial csce::polynomial::add(const csce::polynomial& other) const {
	csce::polynomial result;
	result.terms = (*this).terms;
	
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
	result.terms = (*this).terms;
	
	for(auto it : other.terms){
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

csce::polynomial csce::polynomial::multiply(const csce::polynomial& other) const {
	csce::polynomial result;
	
	for(auto& a : (*this).terms){
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
				
				result.terms[terms] = coefficient;
			}
		}
	}
	
	return result;
}