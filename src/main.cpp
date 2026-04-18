#include <iostream>
#include "../include/SimulationEngine.h"
#include "../include/Martingale.h"
#include "../include/Paroli.h"
#include "../include/Fibonacci.h"

using namespace std;

int main() {
    SimulationEngine engine(10000, 10000.0, 10.0, 1000.0);

    engine.addStrategy("Martingale", [] { return make_unique<Martingale>(10.0); });
    engine.addStrategy("Paroli",     [] { return make_unique<Paroli>(10.0, 3); });
    engine.addStrategy("Fibonacci",  [] { return make_unique<Fibonacci>(10.0); });

    engine.run();

    if (engine.exportCSV("results.csv"))
        cout << "Xuất CSV thành công: results.csv" << endl;
    else
        cout << "Xuất CSV thất bại!" << endl;

    return 0;
}
