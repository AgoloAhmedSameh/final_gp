#include <string>
#include <tuple>

std::tuple<std::string> month_season(const std::string& month, int days) {
    std::string season;

    if (month == "January" || month == "February" || month == "March") {
        season = "winter";
    } else if (month == "April" || month == "May" || month == "June") {
        season = "spring";
    } else if (month == "July" || month == "August" || month == "September") {
        season = "summer";
    } else {
        season = "autumn";
    }

    if (month == "March" && days > 19) {
        season = "spring";
    } else if (month == "June" && days > 20) {
        season = "summer";
    } else if (month == "September" && days > 21) {
        season = "autumn";
    } else if (month == "October" && days > 21) {
        season = "autumn";
    } else if (month == "November" && days > 21) {
        season = "autumn";
    } else if (month == "December" && days > 20) {
        season = "winter";
    }

    return std::make_tuple(season);
}
