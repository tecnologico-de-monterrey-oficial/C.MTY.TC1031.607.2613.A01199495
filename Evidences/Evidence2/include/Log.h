//
// Created by Diego Villanueva Fernandez on 18/10/26.
// Matricula: A01199495
//

#ifndef C_MTY_TC1031_607_2613_A01199495_LOG_H

#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <ostream>

struct Log {
    int year = 0;
    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;
    std::string ip;
    std::string event;
    int arrivalOrder = 0;

    static int monthNumber(const std::string& name) {
        const std::string months[12] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        for (int i = 0; i < 12; i++) {
            if (name == months[i]) return i + 1;
        }
        return 0;
    }

    static std::string monthName(int number) {
        const std::string months[12] = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        if (number < 1 || number > 12) return "???";
        return months[number - 1];
    }

    static bool leapYear(int y) {
        return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    }

    static bool validDate(int y, int m, int d) {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;
        const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maximum = days[m - 1];
        if (m == 2 && leapYear(y)) maximum = 29;
        return d <= maximum;
    }

    static bool validIP(const std::string& address) {
        std::istringstream input(address);
        std::string part;
        int count = 0;
        while (std::getline(input, part, '.')) {
            if (part.empty() || part.size() > 3 || ++count > 4) return false;
            for (char c : part) {
                if (!std::isdigit(static_cast<unsigned char>(c))) return false;
            }
            int value = std::stoi(part);
            if (value > 255) return false;
        }
        return count == 4 && !address.empty() && address.back() != '.';
    }

    static bool parse(const std::string& line, Log& result, std::string& error, int order = 0) {
        std::istringstream input(line);
        std::string monthText, dayText, yearText, timeText, address;
        if (!(input >> monthText >> dayText >> yearText >> timeText >> address)) {
            error = "Faltan datos de fecha, hora o IP";
            return false;
        }
        int m = monthNumber(monthText);
        if (m == 0) {
            error = "Mes invalido";
            return false;
        }
        auto digitsOnly = [](const std::string& value) {
            if (value.empty()) return false;
            for (char c : value) {
                if (!std::isdigit(static_cast<unsigned char>(c))) return false;
            }
            return true;
        };
        if (!digitsOnly(dayText) || dayText.size() > 2 ||
            !digitsOnly(yearText) || yearText.size() != 4) {
            error = "Dia o anio con formato invalido";
            return false;
        }
        int d = std::stoi(dayText);
        int y = std::stoi(yearText);
        if (!validDate(y, m, d)) {
            error = "Fecha inexistente";
            return false;
        }
        if (timeText.size() != 8 || timeText[2] != ':' || timeText[5] != ':' ||
            !digitsOnly(timeText.substr(0, 2)) ||
            !digitsOnly(timeText.substr(3, 2)) ||
            !digitsOnly(timeText.substr(6, 2))) {
            error = "Hora con formato invalido";
            return false;
        }
        int h = std::stoi(timeText.substr(0, 2));
        int min = std::stoi(timeText.substr(3, 2));
        int s = std::stoi(timeText.substr(6, 2));
        if (h > 23 || min > 59 || s > 59) {
            error = "Hora fuera de rango";
            return false;
        }
        if (!validIP(address)) {
            error = "Direccion IP invalida";
            return false;
        }
        std::string description;
        std::getline(input >> std::ws, description);
        if (description.empty()) {
            error = "Descripcion del evento vacia";
            return false;
        }
        result.year = y;
        result.month = m;
        result.day = d;
        result.hour = h;
        result.minute = min;
        result.second = s;
        result.ip = address;
        result.event = description;
        result.arrivalOrder = order;
        error.clear();
        return true;
    }

    bool operator<(const Log& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        if (minute != other.minute) return minute < other.minute;
        return second < other.second;
    }

    bool operator==(const Log& other) const {
        return year == other.year && month == other.month && day == other.day &&
               hour == other.hour && minute == other.minute && second == other.second;
    }

    bool sameDay(const Log& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    std::string dayString() const {
        std::ostringstream output;
        output << monthName(month) << ' ' << std::setw(2) << std::setfill('0')
               << day << ' ' << year;
        return output.str();
    }

    std::string toString() const {
        std::ostringstream output;
        output << dayString() << ' ' << std::setfill('0')
               << std::setw(2) << hour << ':' << std::setw(2) << minute << ':'
               << std::setw(2) << second << ' ' << ip << ' ' << event;
        return output.str();
    }
};

inline std::ostream& operator<<(std::ostream& output, const Log& log) {
    return output << log.toString();
}

#endif //C_MTY_TC1031_607_2613_A01199495_LOG_H
