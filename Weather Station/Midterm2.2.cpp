#include "math.h"
#include <iostream>
#include "Measure.h"
#include "WeatherStation.h"
using namespace std;
int Measure::numOfMeasures = 0;
int main()
{
    WeatherStation st("Lodz", "Weather Institute", 3); //max 3 measure devices
    cout << Measure::count() << endl; //0
    try {
        st.add(new MinMeasure(1, "Temperature", 2.3, 2.5, 2.0)); //degrees, spread 0.5
        st.add(new MaxMeasure(2, "Wind", 20, 18.5, 19)); //km/h, spread 1.5
        st.add(new AvgMeasure(3, "Preasure", 1015, 1010, 1008)); //hPa, spread 7
        st.add(new MaxMeasure(4, "Humidity", 75, 73, 77)); //percents, spread 4
    }
    catch (WeatherStation::LimitError& e) {
        cout << e.what() << endl; //only 3 measure devices allowed
    }
    cout << st;

    cout << Measure::count() << endl; //3
    cout << st.maxSpread() << endl; //7.0
    st.remove("Preasure");
    cout << Measure::count() << endl; //2
    cout << st.maxSpread() << endl; //1.5

    try {
        cout << st[1].getResult() << endl; //2.0
        cout << st[5].getResult() << endl; //IndexError exception
    }
    catch (WeatherStation::IndexError& e) {
        cout << e.what() << endl; //item no. 5 not found 
    }
    st.clear();
    cout << Measure::count() << endl; //0
}

