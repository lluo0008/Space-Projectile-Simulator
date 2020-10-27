/**
 * Lily de Loe
 * 2020/10/26
 */

#ifndef UNTITLED_ODESYSTEM_H
#define UNTITLED_ODESYSTEM_H

#include <vector>

using namespace std;

class ODESystem {
public:
    virtual /**
	 * Generates the dimension of the system
	 *
	 * @return the system's dimension
	 */
    int getSystemSize() = 0;

    virtual /**
     * Gets the current values
     *
     * @return the current values
     */
    std::vector<double> getCurrentValues() = 0;

    virtual /**
     * Generates the ordinary differential equations for the system
     * @param time the time
     * @param values the velocity components
     * @return the ordinary differential equations
     */
    std::vector<double> getFunction(double time, std::vector<double> values) = 0;

};


#endif //UNTITLED_ODESYSTEM_H
