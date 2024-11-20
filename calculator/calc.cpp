#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>
using namespace std;
void help() {
    cout << "Использование: calculator -o <operation> <numbers>\n";
    cout << "Доступные операции:\n";
    cout << " - arif\n";
    cout << " - median\n";
}

double arif(const std::vector<double>& numbers) {
    double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

double median(std::vector<double> numbers) {
    sort(numbers.begin(), numbers.end());
    size_t n = numbers.size();
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        return numbers[n / 2];
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        help();
        return 1;
    }

    string operation;
    vector<double> numbers;

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-o" || string(argv[i]) == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i];
            } else {
                help();
                return 1;
            }
        } else {
            try {
                numbers.push_back(stod(argv[i]));
            } catch (const invalid_argument&) {
                help();
                return 1;
            }
        }
    }

    // Убедимся, что количество операндов от 6 до 8
    if (numbers.size() < 6 || numbers.size() > 8) {
        cout << "Ошибка: должно быть от 6 до 8 операндов.\n";
        return 1;
    }
    if (operation == "arif") {
        cout << "Среднее арифметическое: " << arif(numbers) << endl;
    } else if (operation == "median") {
        cout << "Медиана: " << median(numbers) << endl;
    } else {
        help();
        return 1;
    }
    return 0;
}
