// Dmytro Demchuk K-25 & Polina Harchenko K-28
// GCC 13+ | MSVC v19.36+

#include "Generator.h"
#include "InputSetup.h"
#include <iostream>

#ifdef _WIN32
#include <cstdlib>
#endif

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    RunConfig config;
    if (!prepareInput(argc, argv, config))
        return 1;

    try {
        Generator gen(config.filename, config.n);
        cout << "Теоретична кількість варіантів C(M,n) = " << gen.total() << "\n\n";

        if (!config.experiment) {
            int i = 1;
            for (;;) {
                string variant = gen();
                cout << "Варіант " << i++ << " \n" << variant << "\n\n";
            }
        }
        unsigned long long count = 0;
        try {
            for (;;) {
                gen();
                ++count;
            }
        } catch (const NoMoreVariants&) {}

        cout << "Згенеровано: " << count
             << (count == gen.total() ? " - збігається з C(M,n)\n" : " - не збігається!\n");
    } catch (const NoMoreVariants& e) {
        cout << e.what() << "\n";
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
