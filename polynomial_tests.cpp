#include "catch.hpp"
#include <string>
#include <unordered_map>

#include "polynomial.hpp"

SCENARIO("Polynomial operations") {

	GIVEN("Two polynomials") {
		csce::polynomial pa;
		
		std::unordered_map<char, int> pa_terms = { { 'x', 3 },{ 'y', 3 } };
		pa.terms[pa_terms] = 3.0L;

		pa_terms = { { 'y', 3 } };
		pa.terms[pa_terms] = 5.0L;

		REQUIRE( pa.str() == "5(y^3) + 3(x^3)(y^3)" );

		csce::polynomial pb;

		std::unordered_map<char, int> pb_terms = { { 'x', 2 },{ 'y', 3 } };
		pb.terms[pb_terms] = 4.0L;

		REQUIRE( pb.str() == "4(x^2)(y^3)" );

		WHEN("the add operator is applied") {
			csce::polynomial result = pa + pb;

			THEN("they are summed correctly") {
				REQUIRE(result.str() == "4(x^2)(y^3) + 5(y^3) + 3(x^3)(y^3)");
			}
		}

		WHEN("the subtraction operator is applied") {
			csce::polynomial result = pa - pb;

			THEN("they are subtracted correctly") {
				REQUIRE(result.str() == "-4(x^2)(y^3) + 5(y^3) + 3(x^3)(y^3)");
			}
		}

		WHEN("the mutlipication operator is applied") {
			csce::polynomial result = pa * pb;

			THEN("they are multiplied correctly") {
				REQUIRE(result.str() == "12(x^5)(y^6) + 20(x^2)(y^6)");
			}
		}

	}
}