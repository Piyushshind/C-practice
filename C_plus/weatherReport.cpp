#include <iostream>
#include <iomanip>

class WeatherReport {
private:
    int day_of_month;
    double high_temp;
    double low_temp;
    double amount_rain;
    double amount_snow;

public:
    // Default constructor
    WeatherReport() : day_of_month(0), high_temp(0), low_temp(0), amount_rain(0), amount_snow(0) {}

    // Parameterized constructor
    WeatherReport(int day, double high, double low, double rain, double snow)
        : day_of_month(day), high_temp(high), low_temp(low), amount_rain(rain), amount_snow(snow) {}

    // Function to prompt user for input
    void setValues() {
        std::cout << "Enter day of month: ";
        std::cin >> day_of_month;
        std::cout << "Enter high temperature: ";
        std::cin >> high_temp;
        std::cout << "Enter low temperature: ";
        std::cin >> low_temp;
        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;
        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    // Function to display weather report
    void display() const {
        std::cout << "Day of month: " << day_of_month << std::endl;
        std::cout << "High temperature: " << high_temp << std::endl;
        std::cout << "Low temperature: " << low_temp << std::endl;
        std::cout << "Amount of rain: " << amount_rain << std::endl;
        std::cout << "Amount of snow: " << amount_snow << std::endl;
    }

    // Function to calculate and display monthly report
    static void generateMonthlyReport(const WeatherReport reports[], int size) {
        double total_high = 0, total_low = 0, total_rain = 0, total_snow = 0;

        for (int i = 0; i < size; ++i) {
            total_high += reports[i].high_temp;
            total_low += reports[i].low_temp;
            total_rain += reports[i].amount_rain;
            total_snow += reports[i].amount_snow;
        }

        std::cout << "Monthly Report:\n";
        std::cout << "Average high temperature: " << std::fixed << std::setprecision(2) << total_high / size << std::endl;
        std::cout << "Average low temperature: " << std::fixed << std::setprecision(2) << total_low / size << std::endl;
        std::cout << "Total amount of rain: " << total_rain << std::endl;
        std::cout << "Total amount of snow: " << total_snow << std::endl;
    }
};

int main() {
    int choice;
    const int MAX_DAYS = 31; // Maximum days in a month
    WeatherReport reports[MAX_DAYS];

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enter weather report\n";
        std::cout << "2. Generate monthly report\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int day;
                std::cout << "Enter day of month (1-31): ";
                std::cin >> day;
                reports[day - 1].setValues();
                break;
            }
            case 2:
                WeatherReport::generateMonthlyReport(reports, MAX_DAYS);
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
