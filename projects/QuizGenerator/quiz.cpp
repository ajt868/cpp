#include <iostream>
#include <ctime>

int main() {

    std::string questions[] = 
    {"1. Explain Lenz's Law\n",
    "2. What is the Motor Effect?\n",
    "3. What are the two postulates of Albert Einstein with regards to special relativity? \n",
    "4. Outline the derivation for escape velocity.\n",
    "5. Analyse the relationship between the mass defect and binding energy.\n";}

    std::cout << time(0) << std::endl;
    srand(0);

    return 0;

}
