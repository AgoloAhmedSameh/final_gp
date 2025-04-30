bool check_monthnumber(const std::string& monthname3) {
    if (monthname3 == "April" || monthname3 == "June" || monthname3 == "September" || monthname3 == "November") {
        return true;
    } else {
        return false;
    }
}
