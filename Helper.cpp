/**
 * Lily de Loe
 * 2020/10/26
 */

#include <vector>
#include "Helper.h"
using namespace std;
/**
	 * copies the given array
	 * @param in initial array
	 * @return copy of the initial array
	 */
static std::vector<double> copyVector(std::vector<double> in){
    std::vector<double> temp;
    for (int i = 0; i < in.size(); i++) {
        temp[i] = in[i];
    }
    return temp;
} //end copyArray

